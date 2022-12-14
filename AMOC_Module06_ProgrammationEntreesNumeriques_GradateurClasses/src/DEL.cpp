#include <Arduino.h>
#include <DEL.h>

DEL::DEL(uint8_t p_pin) : m_pin(p_pin)
{

    pinMode(m_pin, OUTPUT);
    analogWrite(m_pin, 0);
}
uint8_t DEL::getPin()
{
    return this->m_pin;
}
void DEL::allumer()
{
    analogWrite(this->getPin(), 255);
}
void DEL::allumer(float p_pourcentageIntensite)
{
    analogWrite(this->getPin(), p_pourcentageIntensite * 2.55);
}
void DEL::eteindre()
{
    analogWrite(this->getPin(), 0);
}
// creer une methode clignoter