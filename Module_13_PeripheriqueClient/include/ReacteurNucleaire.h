#pragma once
#include <Arduino.h>

class ReacteurNucleaire
{
private:
    String m_etat;

public:
    ReacteurNucleaire();

    const String recupererEtat();

    void permuterEtat(String &p_etat);
};