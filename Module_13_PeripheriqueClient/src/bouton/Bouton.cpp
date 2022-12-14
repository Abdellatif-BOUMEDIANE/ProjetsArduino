#include <Arduino.h>

#include "./../include/action/Action.h"

#include "./../include/bouton/Bouton.h"

Bouton::Bouton(int p_pin, Action *p_actionDels) : m_pin(p_pin), m_actionDels(p_actionDels)
{
    pinMode(this->m_pin, INPUT);
}

const void Bouton::faireReagirLesDels()
{
    this->m_actionDels->executer();
}
