#pragma once

#include <Arduino.h>
#include <Bouton.h>

class Program
{
private:
    Bouton *m_bouton;
    uint8_t m_pinDEL;
    uint8_t m_pinBouton;

public:
    Program(uint8_t p_pinDEL, uint8_t p_pinBouton);
    void loop();
};