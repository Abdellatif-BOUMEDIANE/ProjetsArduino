#include "ServeurWeb.h"

#include <Arduino.h>

#include <SPIFFS.h>

#include <WebServer.h>

#include <detail/RequestHandlersImpl.h>

#include <ArduinoJson.h>

#include <uri/UriBraces.h>

#include "Actionneur.h"

#define NOMBRE_A_SOUSTRAIRE_ASCII_INT  48

#define PORT 80

#define OK 200
#define BAD_REQUEST 400
#define NOT_FOUND 404
#define REDIRECTION 301

#define TAILLE_DOCUMENT_JSON 500

ServeurWeb::ServeurWeb(std::vector<Actionneur*> p_actionneurs) : m_actionneurs(p_actionneurs)
{
  SPIFFS.begin();

  pinMode(LED_BUILTIN, OUTPUT);

  this->m_webServer = new WebServer(PORT);

  this->ajouterFichiersStatiques("/");

  this->m_webServer->on("/", HTTPMethod::HTTP_GET, [this]() { this->afficherRacine(); });

  this->m_webServer->on(UriBraces("/actionneurs/{}"), HTTPMethod::HTTP_PUT,
                    [this]() {
                        int id = atoi(this->m_webServer->pathArg(0).c_str());
                        this->actionner(id);
                    });

  this->m_webServer->onNotFound( [this]() { this->ressourceNonTrouvee(this->m_webServer->uri()); });

  this->m_webServer->begin();

}

void ServeurWeb::tick() 
{
   this->m_webServer->handleClient();
}

void ServeurWeb::afficherRacine()
{

  Serial.println("Réception requête");
  Serial.println(this->m_webServer->uri());

  this->m_webServer->sendHeader("Location", "index.html", true);
  this->m_webServer->send(REDIRECTION, "text/plain", "");

}

void ServeurWeb::ajouterFichiersStatiques(String const& p_debutNomFichier)
{
  File racine = SPIFFS.open("/");
  ajouterFichiersStatiques(p_debutNomFichier, racine);
}

void ServeurWeb::ajouterFichiersStatiques(String const& p_debutNomFichier, File& p_repertoire)
{
  if (!p_repertoire)
  {
    return;
  } 

  Serial.println(String("Traitement du répertoire: ") + p_repertoire.name());

  File fichier = p_repertoire.openNextFile();

  while (fichier)
  {
    String nomFichier = String(fichier.name());

    if (fichier.isDirectory())
    {
      ajouterFichiersStatiques(p_debutNomFichier, fichier);
    }
    else
    {
      if (nomFichier.startsWith(p_debutNomFichier))
      {
        Serial.println(String("Ajout du fichier statique: " + nomFichier));
        this->m_webServer->serveStatic(nomFichier.c_str(), SPIFFS, nomFichier.c_str());
      }
    }

    fichier.close();
    fichier = p_repertoire.openNextFile();
  }

  p_repertoire.close();
}

void ServeurWeb::ressourceNonTrouvee(const String& p_nomRessource)
{
  Serial.println("Ressource : " + p_nomRessource + " non trouvée !");
  this->m_webServer->send(NOT_FOUND, "text/plain", "Not found");
}


void ServeurWeb::actionner(int const& p_id)
{
  DynamicJsonDocument document(TAILLE_DOCUMENT_JSON);

  String corpsDeLaRequete = this->m_webServer->arg("plain");

  DeserializationError error = deserializeJson(document, corpsDeLaRequete);

  String id = document["id"];

  String etat = document["etat"];

  if (error)
  {
    Serial.print(F("La désérialisation à échoué "));
    Serial.println(error.f_str());
  }
  else
  {
    if(id.length() == 1)
    {
      int idConvertit = toAscii(id[0]) - NOMBRE_A_SOUSTRAIRE_ASCII_INT;

      if(p_id == idConvertit)
      {
        for (int actionneur = 0; actionneur < this->m_actionneurs.size(); actionneur++)
        {
            if(this->m_actionneurs.at(actionneur)->id() == idConvertit)
            {
              if(etat == "eteint")
              {
                this->m_actionneurs.at(actionneur)->eteindre();
                this->m_webServer->send(OK, "text/plain", this->m_actionneurs.at(actionneur)->description() + " éteinte");
              }
              else if (etat == "allume")
              {
                this->m_actionneurs.at(actionneur)->allumer();
                this->m_webServer->send(OK, "text/plain", this->m_actionneurs.at(actionneur)->description() + " allumée");
              }
            }
        }
      }
      else
      {
        this->m_webServer->send(BAD_REQUEST, "text/plain", "Bad Request");
      }
    }
  }
}