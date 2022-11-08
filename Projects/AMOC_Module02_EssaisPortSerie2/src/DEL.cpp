#include <Arduino.h>
#include "DEL.h"
DEL::DEL(const int &p_pinDel)
    : m_pinDEL(p_pinDel)
{
    Serial.end();
    Serial.begin(9600);
    Serial.println("Flasher::Flasher(int,int) (0x" + String((uint16_t)this, HEX) + ")");
    pinMode(this->m_pinDEL, OUTPUT);
    digitalWrite(this->m_pinDEL, LOW);
}

void DEL::allumer() const
{
    pinMode(this->m_pinDEL, OUTPUT);
    digitalWrite(this->m_pinDEL, HIGH);
}

void DEL::eteindre() const
{
    pinMode(this->m_pinDEL, OUTPUT);
    digitalWrite(this->m_pinDEL, LOW);
}