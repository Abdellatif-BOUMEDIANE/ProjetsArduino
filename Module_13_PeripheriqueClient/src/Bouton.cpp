#include "Arduino.h"
#include "Bouton.h"
#include "Action.h"

Bouton::Bouton(int p_pinBouton, Action *p_actionAnimerDelsWebClient) : m_pin(p_pinBouton),
                                                                       m_actionAnimerDelsWebClient(p_actionAnimerDelsWebClient)
{
    pinMode(this->m_pin, INPUT);

    this->m_dernierEtatBouton = HIGH;

    this->m_derniereDateChangement = 0;

    this->m_dernierEtatStableBouton = HIGH;
}

void Bouton::tick()
{
   bool etatBouton = digitalRead(this->m_pin);

    long dateActuelle = millis();

    if (etatBouton != this->m_dernierEtatBouton)
    {
        this->m_derniereDateChangement = dateActuelle;

        this->m_dernierEtatBouton = etatBouton;
    }

    if (dateActuelle - this->m_derniereDateChangement > this->m_delaiMinPression)
    {
        if (this->m_dernierEtatStableBouton == HIGH && etatBouton == LOW)
        {
            // raisonnement bouton relaché!
        }
        else if (this->m_dernierEtatStableBouton == LOW && etatBouton == HIGH)
        {
            this->m_actionAnimerDelsWebClient->executer();
        }

        this->m_dernierEtatStableBouton = etatBouton;
    }
}
