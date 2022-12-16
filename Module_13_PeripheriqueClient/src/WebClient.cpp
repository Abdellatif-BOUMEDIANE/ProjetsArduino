#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "config.h"
#include "WebClient.h"

WebClient::WebClient(ReacteurNucleaire *p_reacteurNucleaire, DEL *p_delVerte, DEL *p_delRouge) : m_reacteurNucleaire(p_reacteurNucleaire),
                                                                                                 m_delVerte(p_delVerte),
                                                                                                 m_delRouge(p_delRouge)
{
    this->m_dateDernierChangement = millis();
}

void WebClient::recupererEtat()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        String etat = "";
        String adresseIpServeur = SERVER_IP_ADDRESS;
        String url = "http://" + adresseIpServeur + "/coeur-reacteur";

        HTTPClient httpClient;
        httpClient.begin(url);

        int codeStatut = httpClient.GET();

        if (codeStatut != 200)
        {
            Serial.println(HTTPClient::errorToString(codeStatut));
        }
        else
        {
            etat = httpClient.getString();
            etat = this->deserialiserEtat(etat);

            if (etat != this->m_reacteurNucleaire->recupererEtat())
            {
                this->m_reacteurNucleaire->permuterEtat(etat);
            }
        }
    }
    else
    {
        Serial.println("Non connecté au WiFi !");
    }
}

void WebClient::afficherEtatEnDels()
{
    const String etat = this->m_reacteurNucleaire->recupererEtat();

    if (etat == "repos")
    {
        this->m_delVerte->eteindre();
        this->m_delRouge->allumer();
    }
    else if (etat == "actif")
    {
        this->m_delRouge->eteindre();
        this->m_delVerte->allumer();
    }
    else
    {
        this->m_delRouge->eteindre();
        this->m_delVerte->eteindre();
    }
}

String WebClient::deserialiserEtat(String &p_etat)
{
    DynamicJsonDocument doc(64);
    DeserializationError error = deserializeJson(doc, p_etat);

    if (error)
    {
        Serial.print(F("deserializeJson() échouée!: "));
        Serial.println(error.f_str());
        return "error";
    }

    String etat = doc["etat"];

    return etat;
}

void WebClient::permuterEtat()
{
    String etatModifiE = "";

    if (this->m_reacteurNucleaire->recupererEtat() == "repos")
    {
        etatModifiE = "actif";
    }
    else
    {
        etatModifiE = "repos";
    }

    etatModifiE = this->serialiserEtat(etatModifiE);

    if (WiFi.status() == WL_CONNECTED)
    {
        String adresseIpServeur = SERVER_IP_ADDRESS;
        String url = "http://" + adresseIpServeur + "/coeur-reacteur";

        HTTPClient httpClient;
        httpClient.begin(url);
        httpClient.addHeader("Content-type", "application/json");

        int codeStatut = httpClient.PUT(etatModifiE);

        if (codeStatut != 200)
        {
            Serial.println(HTTPClient::errorToString(codeStatut));
        }
    }
    else
    {
        Serial.println("Non connecté au WiFi !");
    }
}

String WebClient::serialiserEtat(String &p_etat)
{
    String etatModifiE = "";
    StaticJsonDocument<64> doc;

    doc["etat"] = p_etat;
    serializeJson(doc, etatModifiE);
    Serial.println(etatModifiE);
    return etatModifiE;
}

void WebClient::tick()
{
    long dateActuelle = millis();

    if (dateActuelle - this->m_dateDernierChangement > UPDATE_TIMER)
    {
        this->recupererEtat();
        this->afficherEtatEnDels();
        this->m_dateDernierChangement = dateActuelle;
    }
}
