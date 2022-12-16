#include <Arduino.h>

#include "Program.h"

#include "ServeurWeb.h"

#include <WiFi.h>

#include <HTTPClient.h>

#include "configuration.h"

#include "Actionneur.h"

#include "DEL.h"

#define BORNE_DEL_1 25
#define BORNE_DEL_2 26

bool erreur = false;

IPAddress adresseIPPrivee(192, 168, 51, 1);
IPAddress passerelleParDefault(192, 168, 51, 1);
IPAddress masqueDeSousReseaux(255, 255, 255, 0);

Program::Program()
{
  this->m_actionneurs.push_back(new DEL(1, "DEL 1", BORNE_DEL_1, false));
  this->m_actionneurs.push_back(new DEL(2, "DEL 2", BORNE_DEL_2, false));
}

void Program::listeFileDansDossier(File dossier, int numerotab)
{
  while (true)
  {
    File entree = dossier.openNextFile();

    if (!entree)
    {
      break;
    }

    for (int i = 0; i < numerotab; i++)
    {
      Serial.println('\t');
    }

    Serial.print(entree.name());

    if (entree.isDirectory())
    {
      Serial.println('/');
      listeFileDansDossier(entree, numerotab + 1);
    }
    else
    {
      Serial.print("\t\t");
      Serial.println(entree.size(), DEC);
    }
  }
}

const void Program::Configuration()
{
  bool estConfigurerCorectement = WiFi.softAPConfig(adresseIPPrivee, passerelleParDefault, masqueDeSousReseaux);

  bool demarragePointAccesReussit = false;

  Serial.println(String("configuration réseau du point d'accès : ") + estConfigurerCorectement ? "Réussite" : "Échec");

  if (estConfigurerCorectement)
  {
    demarragePointAccesReussit = WiFi.softAP(WIFI_SSID, WIFI_PASSWORD);

    Serial.println(String("Démarrage du point d'accès : ") + (demarragePointAccesReussit ? "Réussi" : "Échec"));

    if (demarragePointAccesReussit)
    {
      this->m_serveur = new ServeurWeb(this->m_actionneurs);

      Serial.println();
      Serial.println(F("Initialisation ..."));

      if (SPIFFS.begin())
      {
        Serial.println(F("SPIFFS est monté correctement"));
      }
      else
      {
        Serial.println(F("Une erreur est survenue durant le montage de SPIIFS"));
      }

      unsigned int totalBites = SPIFFS.totalBytes();
      unsigned int bitesUtilise = SPIFFS.usedBytes();

      Serial.println();

      Serial.println("==== Information sur le système de fichier ====");

      Serial.println("total d'espace : " + String(totalBites) + " bites");

      Serial.println("total espace utilisée : " + String(bitesUtilise) + " bites");

      File dossier = SPIFFS.open("/");

      listeFileDansDossier(dossier, 1);
    }
  }

  erreur = !(estConfigurerCorectement && demarragePointAccesReussit);
}

const void Program::loop()
{
  if (!erreur)
  {
    this->m_serveur->tick();
  }
}
