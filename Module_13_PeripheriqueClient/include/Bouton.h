#pragma once
#include "Arduino.h"
#include "Action.h"

class Action;

class Bouton
{

private:
    uint8_t m_pin;

    Action *m_actionAnimerDelsWebClient;

    bool m_dernierEtatBouton;

    long m_derniereDateChangement;

    bool m_dernierEtatStableBouton;

    const int m_delaiMinPression = 25;

public:
    Bouton(int p_pinBouton, Action *p_actionAnimerDelsWebClient);

    void tick();
};