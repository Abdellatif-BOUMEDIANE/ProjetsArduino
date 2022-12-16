#pragma once
#include <Arduino.h>

class DEL
{

private:
    uint8_t m_pin;

public:
    DEL(uint8_t p_pin);

    void allumer();

    void eteindre();
};