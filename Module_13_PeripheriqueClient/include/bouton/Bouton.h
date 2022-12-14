#pragma once

#include "./../action/Action.h"

class Bouton
{
private:
    int m_pin;
    Action *m_actionDels;
    

public:
    Bouton(int p_pin, Action *p_actionDels);
    const void faireReagirLesDels();
    virtual const void tick() = 0;
};