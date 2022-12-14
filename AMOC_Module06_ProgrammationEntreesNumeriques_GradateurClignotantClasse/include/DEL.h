#pragma once

class DEL
{
private:
    uint8_t m_pin;
    bool m_estDelEteinte;
    unsigned long m_prochainChangement;

public:
    DEL(uint8_t p_pin);
    void allumer();
    void allumer(float p_pourcentageIntensite);
    void eteindre();
    void clignoter(unsigned long tempsAllumage, unsigned long tempsExtinction);
    void clignoter();
};