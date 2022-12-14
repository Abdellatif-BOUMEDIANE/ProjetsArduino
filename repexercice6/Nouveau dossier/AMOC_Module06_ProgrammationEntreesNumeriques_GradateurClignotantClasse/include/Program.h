#pragma once

#include <Arduino.h>
#include <Bouton.h>
#include <Action.h>
#include <DEL.h>

class Program
{
private:
    // donnees membre intensité

    Bouton *m_bouton;
    Bouton *m_boutonClignotement;
    DEL *m_del;
    DEL *m_delClignotement;
    uint8_t m_pinDEL;
    uint8_t m_pinDELClignotement;
    uint8_t m_pinBouton;
    uint8_t m_pinBoutonClignotement;
    Action *m_action;

public:
    Program(uint8_t p_pinDEL, uint8_t p_pinDELClignotement, uint8_t p_pinBouton, uint8_t p_pinBoutonClignotement);
    void loop();
};