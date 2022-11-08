#pragma once

#include <Arduino.h>
#include <Action.h>

class Bouton
{
private:
    uint8_t m_pin;
    Action *m_actionBoutonPresse;

public:
    Bouton(int p_pinBouton, Action *p_actionBouton);
    void tick();
};