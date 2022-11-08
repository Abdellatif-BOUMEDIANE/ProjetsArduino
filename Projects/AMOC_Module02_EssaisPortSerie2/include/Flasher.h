#pragma once
#include "DEL.h"
class Flasher
{
private:
    DEL m_DEL;
    int m_dureeAllumeeEteinte;

public:
    Flasher(DEL p_DEL, int p_dureeAllumeeEteinte);
    void FaireClignoter(int p_nombreCycles);
    // constructeur par copie
    Flasher(const Flasher &p_aCopier);

    // opérateur d'affectation
    Flasher &operator=(const Flasher &p_source);
};