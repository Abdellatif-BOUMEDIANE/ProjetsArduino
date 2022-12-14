#pragma once
class Flasher
{
private:
    int m_pinDel;
    int m_dureeAllumeeEteinte;

public:
    Flasher(int p_pinDel, int p_dureeAllumeeEteinte);
    void FaireClignoter(int p_nombreCycles);
    // constructeur par copie
    Flasher(const Flasher &p_aCopier);

    // opérateur d'affectation
    Flasher &operator=(const Flasher &p_source);
};