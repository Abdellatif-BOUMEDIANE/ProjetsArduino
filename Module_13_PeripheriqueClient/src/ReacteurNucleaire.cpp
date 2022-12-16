#include <Arduino.h>
#include "ReacteurNucleaire.h"

ReacteurNucleaire::ReacteurNucleaire()
{
    ;
}

const String ReacteurNucleaire::recupererEtat()
{
    return this->m_etat;
}

void ReacteurNucleaire::permuterEtat(String &p_etat)
{
    this->m_etat = p_etat;
}
