#pragma once
#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "ReacteurNucleaire.h"
#include "DEL.h"

class WebClient
{
private:
    ReacteurNucleaire *m_reacteurNucleaire;

    DEL *m_delVerte;

    DEL *m_delRouge;

    long m_dateDernierChangement;

    void recupererEtat();

    String deserialiserEtat(String &p_etat);

    void afficherEtatEnDels();

    String serialiserEtat(String &p_etat);

public:
    WebClient(ReacteurNucleaire *p_reacteurNucleaire, DEL *p_delVerte, DEL *p_delRouge);

    void permuterEtat();

    void tick();
};
