#include <Arduino.h>
#include <Bouton.h>
#include <DEL.h>
#include <ActionModifierIntensiteDEL.h>
#include <Program.h>

// donner membre del,
// maintenat
// m_mpindel
// pindell

Program::Program(uint8_t p_pinDEL, uint8_t p_pinBouton) : m_pinDEL(p_pinDEL), m_pinBouton(p_pinBouton)
{
    DEL *del = new DEL(m_pinDEL);
    ActionModifierIntensiteDEL *action = new ActionModifierIntensiteDEL(del);
    this->m_bouton = new Bouton(m_pinBouton, action);
}
void Program::loop()
{
    m_bouton->tick();
    // delClignoter
}