#include <Arduino.h>
#include "Flasher.h"
Flasher::Flasher(int p_pinDel, int p_dureeAllumeeEteinte)
    : m_pinDel(p_pinDel),
      m_dureeAllumeeEteinte(p_dureeAllumeeEteinte)
{
    Serial.end();
    Serial.begin(9600);
    Serial.println("Flasher::Flasher(int,int) (0x" + String((uint16_t)this, HEX) + ")");
    pinMode(this->m_pinDel, OUTPUT);
    digitalWrite(this->m_pinDel, LOW);
}

// Constructeur par copie
Flasher::Flasher(const Flasher &p_aCopier)
    : m_pinDel(p_aCopier.m_pinDel),
      m_dureeAllumeeEteinte(p_aCopier.m_dureeAllumeeEteinte)
{
    Serial.println("Flasher::Flasher(const Flasher &) (0x" + String((uint16_t)this, HEX) + ")");
}

// Operateur d,affectation
Flasher &Flasher::operator=(const Flasher &p_source)
{
    Serial.println("Flasher &Flasher::operator=(const Flasher &) (0x" + String((uint16_t)this, HEX) + ")-source : (0x" + String((uint16_t)(&p_source), HEX) + ")");
    this->m_pinDel = p_source.m_pinDel;
    this->m_dureeAllumeeEteinte = p_source.m_dureeAllumeeEteinte;
    return *this;
}

void Flasher::FaireClignoter(int p_nombreCycles)
{
    Serial.println("void Flasher::FaireClignoter(int p_nombreCycles) (0x" + String((uint16_t)this, HEX) + ")");
    for (int numCycle = 0; numCycle < p_nombreCycles; ++numCycle)
    {
        digitalWrite(this->m_pinDel, HIGH);
        delay(this->m_dureeAllumeeEteinte);
        digitalWrite(this->m_pinDel, LOW);
        delay(this->m_dureeAllumeeEteinte);
    }
}