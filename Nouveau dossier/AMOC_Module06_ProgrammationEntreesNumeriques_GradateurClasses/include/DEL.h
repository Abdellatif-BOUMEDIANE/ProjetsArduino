#pragma once

class DEL
{
private:
    uint8_t m_pin;

public:
    DEL(uint8_t p_pin);
    uint8_t getPin();
    void allumer();
    void allumer(float p_pourcentageIntensite);
    void eteindre();
};