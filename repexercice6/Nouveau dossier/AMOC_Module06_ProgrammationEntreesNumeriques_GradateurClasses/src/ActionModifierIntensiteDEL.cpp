#include <Arduino.h>
#include <Action.h>
#include <ActionModifierIntensiteDEL.h>
#include <DEL.h>

ActionModifierIntensiteDEL::ActionModifierIntensiteDEL(DEL *p_DEL) : m_DEL(p_DEL)
{
    this->setPourcentageIntensite(0);
}
void ActionModifierIntensiteDEL::executer()
{
    if (this->m_pourcentageIntensite == 0)
    {
        this->m_pas = 25;
    }
    if (this->m_pourcentageIntensite == 100)
    {
        this->m_pas = -25;
    }
    this->m_pourcentageIntensite = this->m_pourcentageIntensite + m_pas;
    this->m_DEL->allumer(this->m_pourcentageIntensite);
}

DEL ActionModifierIntensiteDEL::getDEL()
{
    return *this->m_DEL;
}

void ActionModifierIntensiteDEL::setDEL(DEL *p_DEL)
{
    this->m_DEL = p_DEL;
}

float ActionModifierIntensiteDEL::getPourcentageIntensite()
{
    return this->m_pourcentageIntensite;
}

void ActionModifierIntensiteDEL::setPourcentageIntensite(float p_pourcentageIntensite)
{
    this->m_pourcentageIntensite = p_pourcentageIntensite;
}

float ActionModifierIntensiteDEL::getPas()
{
    return this->m_pas;
}

void ActionModifierIntensiteDEL::setPas(float p_pas)
{
    this->m_pas = p_pas;
}
