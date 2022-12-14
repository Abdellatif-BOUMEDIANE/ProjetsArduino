#include <Arduino.h>
#include "./../include/Affichage4Digits.h"

Affichage4Digits ::Affichage4Digits(Affichage4DigitsProxy *p_proxy)
{
    this->m_proxy = p_proxy;
}
void Affichage4Digits::afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4)
{
    this->m_proxy->afficher(p_d1, p_d2, p_d3, p_d4);
}
void Affichage4Digits::afficherEntier(uint16_t p_valeur)
{
    // faut tronquer ton chiffre en quatre chiffre
    // this->m_proxy->afficher(p_valeur);
}