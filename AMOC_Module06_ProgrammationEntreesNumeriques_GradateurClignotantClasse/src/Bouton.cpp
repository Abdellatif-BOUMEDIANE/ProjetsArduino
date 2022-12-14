#include <Arduino.h>
#include <Bouton.h>
#include <Action.h>

Bouton::Bouton(int p_pinBouton, Action *p_actionBouton)
    : m_pin(p_pinBouton), m_actionBoutonPresse(p_actionBouton)
{
    pinMode(p_pinBouton, INPUT);
    this->m_derniereDateChangement = millis();
    this->m_dernierEtatBouton = HIGH;
    this->m_dernierEtatStableBouton = HIGH;
    this->m_delaiPression = 25;
}

void Bouton::tick()
{

    this->m_etatBouton = digitalRead(this->m_pin);
    long tempsActuel = millis();
    if (this->m_etatBouton != this->m_dernierEtatBouton)
    {
        this->m_derniereDateChangement = tempsActuel;
        this->m_dernierEtatBouton = this->m_etatBouton;
    }
    if (tempsActuel - this->m_derniereDateChangement > this->m_delaiPression)
    {
        if (this->m_dernierEtatStableBouton == HIGH && this->m_etatBouton == LOW)
        {
            this->m_actionBoutonPresse->executer();
        }
    }
    this->m_dernierEtatStableBouton = this->m_etatBouton;
}