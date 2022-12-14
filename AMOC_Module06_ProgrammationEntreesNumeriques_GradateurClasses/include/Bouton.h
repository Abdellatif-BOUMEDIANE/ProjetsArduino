#pragma once

#include <Arduino.h>
#include <Action.h>

class Bouton
{
private:
    uint8_t m_pin;
    Action *m_actionBoutonPresse;
    long m_derniereDateChangement;
    bool m_dernierEtatBouton;
    bool m_dernierEtatStableBouton;
    bool m_etatBouton;
    int m_delaiPression;

public:
    Bouton(int p_pinBouton, Action *p_actionBouton);
    int getPinBouton();
    void setPinBouton(int p_pinBouton);
    Action getActionBouton();
    void setActionBouton(Action *p_actionBouton);
    long getDerniereDateChangement();
    void setDerniereDateChangement(long p_deniereDateChangement);
    bool getdernierEtatBouton();
    void setDernierEtatBouton(bool p_dernierEtatBouton);
    bool getDernierEtatStableBouton();
    void setDernierEtatStableBouton(bool p_dernierEtatStableBouton);
    bool getEtatBouton();
    void setEtatBouton(bool p_pinBouton);
    void tick();
};