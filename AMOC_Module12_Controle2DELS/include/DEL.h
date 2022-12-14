#pragma once 

#include <Arduino.h>

#include "Actionneur.h"

class DEL : public Actionneur
{
    private:
        int m_pin;
        bool m_estAllumee;

    public:
        DEL(int const &p_id, String const &p_description, int p_pin, bool p_estAllumee);
        const void allumer();
        const void eteindre();
        const bool estAllume();
};