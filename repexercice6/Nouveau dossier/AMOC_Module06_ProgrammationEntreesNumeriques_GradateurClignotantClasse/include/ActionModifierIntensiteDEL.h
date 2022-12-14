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
    DEL getDEL();
    void setDEL(DEL *p_DEL);
    float getPourcentageIntensite();
    void setPourcentageIntensite(float p_pourcentageIntensite);
    float getPas();
    void setPas(float p_pas);
    void ActionModifierIntensiteDEL::recupererDatesEvenement(int p_optionAllumageExtinction, unsigned long periodeAllumage,unsigned long periodeEteinte );
};
