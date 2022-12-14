#pragma once

#include "../action/Action.h"

#include "Bouton.h"

class BoutonActionneur : public Bouton
{
private:
    int m_pin;
    int etatActuelDuBouton;
    int dernierEtatDuBouton;
    int dernierEtatStableBouton;
    int dateActuelle;
    long dateDernierChangement;

public:
    BoutonActionneur(int p_pin, Action *p_actionDels);
    const void tick();
};