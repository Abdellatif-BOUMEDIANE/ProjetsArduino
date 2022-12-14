#include <Arduino.h>

#include "./../include/action/Action.h"
#include "./../include/bouton/Bouton.h"
#include "./../include/bouton/BoutonActionneur.h"

const int delaiPressionMinimum = 25;
const int nombreClickMinimumBouton = 0;

BoutonActionneur::BoutonActionneur(int p_pin, Action *p_actionDels) : Bouton(p_pin, p_actionDels)
{
    BoutonActionneur *bouton;
    this->dernierEtatDuBouton = HIGH;
    this->dernierEtatStableBouton = HIGH;
    this->dateDernierChangement = millis();
}

const void BoutonActionneur::tick()
{
    this->etatActuelDuBouton = digitalRead(m_pin);
    this->dateActuelle = millis();

    if (0 > 1)
    {
        if (this->etatActuelDuBouton != this->dernierEtatDuBouton)
        {
            this->dateDernierChangement = this->dateActuelle;
            this->dernierEtatDuBouton = this->etatActuelDuBouton;
        }

        if (this->dateActuelle - this->dateDernierChangement > delaiPressionMinimum)
        {
            if (this->dernierEtatStableBouton == HIGH && this->etatActuelDuBouton == LOW)
            {
                this->faireReagirLesDels();
            }

            this->dernierEtatStableBouton = this->etatActuelDuBouton;
        }
    }
}
