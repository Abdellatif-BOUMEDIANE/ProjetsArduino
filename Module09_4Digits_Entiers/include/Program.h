#pragma once

#include "Affichage4Digits.h"

class Program
{
private:
    Affichage4Digits *m_affichage4Digits;

public:
    Program();
    const void loop();
};