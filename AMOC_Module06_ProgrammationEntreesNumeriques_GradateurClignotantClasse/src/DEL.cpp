#include <Arduino.h>
#include <DEL.h>

DEL::DEL(uint8_t p_pin) : m_pin(p_pin)
{

    pinMode(m_pin, OUTPUT);
    analogWrite(m_pin, 0);
    this->m_estDelEteinte = true;
}

void DEL::allumer()
{
    analogWrite(this->m_pin, 255);
}
void DEL::allumer(float p_pourcentageIntensite)
{
    analogWrite(this->m_pin, p_pourcentageIntensite * 2.55);
}
void DEL::eteindre()
{
    analogWrite(this->m_pin, 0);
}
void DEL::clignoter(unsigned long tempsAllumage, unsigned long tempsExtinction)
{
    unsigned long tempsActuel = millis();
    if (this->m_estDelEteinte)
    {
        if (tempsAllumage != 0)
        {
            if ((tempsActuel == this->m_prochainChangement))
            {
                this->m_estDelEteinte = !this->m_estDelEteinte;
                this->allumer();
                // this->m_derniereDateChangement = tempsActuel;
                this->m_prochainChangement = tempsActuel + tempsAllumage;
            }
        }
    }
    else
    {
        if (tempsExtinction != 0)
        {
            if ((tempsActuel == this->m_prochainChangement))
            {
                this->m_estDelEteinte = !this->m_estDelEteinte;
                this->eteindre();
                // this->m_derniereDateChangement = tempsActuel;
                this->m_prochainChangement = tempsActuel + tempsExtinction;
            }
        }
    }
}
