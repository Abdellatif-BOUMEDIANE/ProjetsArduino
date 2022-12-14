#pragma once

#include <Arduino.h>
#include <Action.h>

class Bouton
{
private:
    uint8_t m_pin;
    Action *m_actionBoutonPresse;
    long m_derniereDateChangement;
    bool m_dernierEtatBouton;
    bool m_dernierEtatStableBouton;
    bool m_etatBouton;
    bool dernierEtatLed;
    int m_delaiPression;

public:
    Bouton(int p_pinBouton, Action *p_actionBouton);
    void tick();
};