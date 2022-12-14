#include <Arduino.h>
#include "Flasher.h"
#include "DEL.h"
Flasher::Flasher(DEL p_del, int p_dureeAllumeeEteinte)
    : m_DEL(p_del),
      m_dureeAllumeeEteinte(p_dureeAllumeeEteinte)
{
    Serial.end();
    Serial.begin(9600);
    Serial.println("Flasher::Flasher(int,int) (0x" + String((uint16_t)this, HEX) + ")");
    this->m_DEL.eteindre();
}

// Constructeur par copie
Flasher::Flasher(const Flasher &p_aCopier)
    : m_DEL(p_aCopier.m_DEL),
      m_dureeAllumeeEteinte(p_aCopier.m_dureeAllumeeEteinte)
{
    Serial.println("Flasher::Flasher(const Flasher &) (0x" + String((uint16_t)this, HEX) + ")");
}

// Operateur d,affectation
Flasher &Flasher::operator=(const Flasher &p_source)
{
    Serial.println("Flasher &Flasher::operator=(const Flasher &) (0x" + String((uint16_t)this, HEX) + ")-source : (0x" + String((uint16_t)(&p_source), HEX) + ")");
    this->m_DEL = p_source.m_DEL;
    this->m_dureeAllumeeEteinte = p_source.m_dureeAllumeeEteinte;
    return *this;
}

void Flasher::FaireClignoter(int p_nombreCycles)
{
    Serial.println("void Flasher::FaireClignoter(int p_nombreCycles) (0x" + String((uint16_t)this, HEX) + ")");
    for (int numCycle = 0; numCycle < p_nombreCycles; ++numCycle)
    {
        this->m_DEL.allumer();
        delay(this->m_dureeAllumeeEteinte);
        this->m_DEL.eteindre();
        delay(this->m_dureeAllumeeEteinte);
    }
}