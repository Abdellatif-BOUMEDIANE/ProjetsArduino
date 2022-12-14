#include <Arduino.h>
#include <ActionModifierIntensiteDEL.h>

ActionModifierIntensiteDEL::ActionModifierIntensiteDEL(DEL *p_DEL) : m_DEL(p_DEL)
{
    this->m_pourcentageIntensite = 0;
}

void ActionModifierIntensiteDEL::executer()
{
    unsigned long tempsAllumage = 0;
    unsigned long tempsExtinction = 0;

    if (this->m_pourcentageIntensite == 0)
    {
        this->m_pas = 25;
    }
    if (this->m_pourcentageIntensite == 100)
    {
        this->m_pas = -25;
    }
    int valeur = ((int)(this->m_pourcentageIntensite / 25.0));
    this->recupererDatesEvenement(valeur, tempsAllumage, tempsExtinction);
    this->m_DEL->clignoter(tempsAllumage, tempsExtinction);
}
void ActionModifierIntensiteDEL::recupererDatesEvenement(int p_optionAllumageExtinction, unsigned long tempsAllumage, unsigned long tempsExtinction)
{
    switch (p_optionAllumageExtinction)
    {
    case 0:
        tempsAllumage = 1000;
        tempsExtinction = 0;
        break;
    case 1:
        tempsAllumage = 750;
        tempsExtinction = 250;
        break;
    case 2:
        tempsAllumage = 500;
        tempsExtinction = 500;
        break;
    case 3:
        tempsAllumage = 250;
        tempsExtinction = 750;
        break;
    case 4:
        tempsAllumage = 0;
        tempsExtinction = 1000;
        break;

    default:
        break;
    }
}
