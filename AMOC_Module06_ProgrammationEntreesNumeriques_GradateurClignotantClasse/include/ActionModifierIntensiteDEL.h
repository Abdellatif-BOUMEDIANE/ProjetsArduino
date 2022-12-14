#pragma once
#include <Action.h>
#include <DEL.h>

class ActionModifierIntensiteDEL : public Action
{
private:
    DEL *m_DEL;
    float m_pourcentageIntensite;
    float m_pas;

public:
    ActionModifierIntensiteDEL(DEL *p_DEL);
    void executer();
    void recupererDatesEvenement(int p_optionAllumageExtinction, unsigned long p_tempsAllumage, unsigned long p_tempsextinction);
};
