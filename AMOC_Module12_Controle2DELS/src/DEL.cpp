#include "DEL.h"

#include "Actionneur.h"

#include <Arduino.h>

DEL::DEL(int const& p_id, String const& p_despcription, int p_pin, bool p_estAllumee) : Actionneur(p_id, p_despcription), m_pin(p_pin), m_estAllumee(p_estAllumee)
{
    pinMode(this->m_pin, OUTPUT);
    digitalWrite(this->m_pin, LOW);
}

const void DEL::allumer()
{
    digitalWrite(this->m_pin, HIGH);
}

const void DEL::eteindre()
{
    digitalWrite(this->m_pin, LOW);
}

const bool DEL::estAllume()
{
    int etat = digitalRead(this->m_pin);

    if(etat == LOW)
    {
        return false;
    }
    else
    {
        return true;
    }
}