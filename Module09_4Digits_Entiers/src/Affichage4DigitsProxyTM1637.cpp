#include <Arduino.h>
#include <TM1637Display.h>
#include "./../include/Affichage4DigitsProxyTM1637.h"

Affichage4DigitsProxyTM1637 ::Affichage4DigitsProxyTM1637(int p_pinHorloge, int p_pinDonnees)
{
    pinMode(p_pinHorloge, OUTPUT);
    pinMode(p_pinDonnees, OUTPUT);
    this->m_tm1637->setBrightness(7);
}
const void Affichage4DigitsProxyTM1637::afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4)
{
    this->m_tm1637->setBrightness(7);
    this->m_tm1637->clear();
    this->m_tm1637->showNumberDec(p_d1, p_d2, p_d3, p_d4);
}