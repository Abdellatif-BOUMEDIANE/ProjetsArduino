#include <Arduino.h>
#include <WiFi.h>
#include "Action.h"
#include "ActionAnimerDelsWebClient.h"
#include "DEL.h"
#include "Bouton.h"
#include "config.h"
#include "Program.h"
#include "WebClient.h"
#include "ReacteurNucleaire.h"

Program::Program()
{
    ReacteurNucleaire *reacteurNucleaire = new ReacteurNucleaire();

    DEL *delVerte = new DEL(25);

    DEL *delRouge = new DEL(26);

    WebClient *webClient = new WebClient(reacteurNucleaire, delVerte, delRouge);

    Action *actionAnimerDelsClient = new ActionAnimerDelsWebClient(webClient);

    Bouton *bouton = new Bouton(17, actionAnimerDelsClient);

    this->m_webClient = webClient;
    
    this->m_bouton = bouton;

    this->connectionReseau();
}

void Program::connectionReseau()
{
    const uint8_t nbEssaisMaximum = 30;
    uint8_t nbEssais = 0;

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connexion : ");

    while (nbEssais < nbEssaisMaximum && WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
        nbEssais++;
    }

    Serial.println("");

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.print("Connecté au réseau WiFi, adresse IP : ");
        Serial.println(WiFi.localIP());
        Serial.println("");
    }
}

void Program::boucle()
{
    this->m_webClient->tick();
    this->m_bouton->tick();
}
