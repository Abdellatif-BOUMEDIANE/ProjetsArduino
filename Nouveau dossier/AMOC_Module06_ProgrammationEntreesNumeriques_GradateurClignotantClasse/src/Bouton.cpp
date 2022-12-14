#include <Arduino.h>
#include <Bouton.h>
#include <Action.h>
#include <ActionModifierIntensiteDEL.h>

Bouton::Bouton(int p_pinBouton, Action *p_actionBouton)
    : m_pin(p_pinBouton), m_actionBoutonPresse(p_actionBouton)
{
    pinMode(p_pinBouton, INPUT);
    this->setDerniereDateChangement(millis());
    this->setDernierEtatBouton(HIGH);
    this->setDernierEtatStableBouton(HIGH);
    this->m_delaiPression = 25;
}

int Bouton::getPinBouton()
{
    return this->m_pin;
}

void Bouton::setPinBouton(int p_pinBouton)
{
    this->m_pin = p_pinBouton;
}

Action Bouton::getActionBouton()
{
    return *this->m_actionBoutonPresse;
}

void Bouton::setActionBouton(Action *p_actionBouton)
{
    this->m_actionBoutonPresse = p_actionBouton;
}

void Bouton::setDerniereDateChangement(long p_dernierDateChangement)
{
    this->m_derniereDateChangement = p_dernierDateChangement;
}

long Bouton::getDerniereDateChangement()
{
    return this->m_derniereDateChangement;
}

bool Bouton::getDernierEtatBouton()
{
    return this->m_dernierEtatBouton;
}

void Bouton::setDernierEtatBouton(bool p_dernierEtatBouton)
{
    this->m_dernierEtatBouton = p_dernierEtatBouton;
}

bool Bouton::getDernierEtatLed()
{
    return this->m_dernierEtatBouton;
}

void Bouton::setDernierEtatLed(bool p_dernierEtatBouton)
{
    this->m_dernierEtatBouton = p_dernierEtatBouton;
}

bool Bouton::getDernierEtatStableBouton()
{
    return this->m_dernierEtatStableBouton;
}

void Bouton::setDernierEtatStableBouton(bool p_dernierEtatStableBouton)
{
    this->m_dernierEtatStableBouton = p_dernierEtatStableBouton;
}
bool Bouton::getEtatBouton()
{
    return this->m_etatBouton;
}

void Bouton::setEtatBouton(bool p_etatBouton)
{
    this->m_etatBouton = p_etatBouton;
}

void Bouton::tick()
{
    setEtatBouton(digitalRead(this->getPinBouton()));
    long dateActuelle = millis();
    if (this->getEtatBouton() != this->getDernierEtatBouton())
    {
        this->setDerniereDateChangement(dateActuelle);
        this->setDernierEtatBouton(getEtatBouton());
    }
    if (dateActuelle - this->getDerniereDateChangement() > this->m_delaiPression)
    {
        if (this->getDernierEtatStableBouton() == HIGH && this->getEtatBouton() == LOW)
        {
            this->m_actionBoutonPresse->executer();
        }
    }
    this->setDernierEtatStableBouton(this->getEtatBouton());
}