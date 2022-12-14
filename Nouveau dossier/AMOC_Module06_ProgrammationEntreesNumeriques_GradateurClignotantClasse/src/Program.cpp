#include <Arduino.h>
#include <Bouton.h>
#include <DEL.h>
#include <ActionModifierIntensiteDEL.h>
#include <Program.h>

// donner membre del,
// maintenat
// m_mpindel
// pindell

Program::Program(uint8_t p_pinDEL, uint8_t p_pinDELClignotement, uint8_t p_pinBouton, uint8_t p_pinBoutonClignotement)
    : m_pinDEL(p_pinDEL), m_pinDELClignotement(p_pinDELClignotement), m_pinBouton(p_pinBouton)
{
    this->m_del = new DEL(m_pinDEL);
    this->m_action = new ActionModifierIntensiteDEL(this->m_del);
    this->m_bouton = new Bouton(m_pinBouton, this->m_action);

    this->m_delClignotement = new DEL(this->m_pinDELClignotement);
}
void Program::loop()
{
    m_bouton->tick();
    this->m_action->executer();
}
