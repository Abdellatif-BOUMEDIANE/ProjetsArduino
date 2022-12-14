#pragma once

#include <Arduino.h>

class Actionneur
{
    private:
        int m_id;
        String m_description;

    public:
        Actionneur(int const& p_id, String const& p_despcription);
        const String& description();
        const int id();
        virtual const void allumer() = 0;
        virtual const void eteindre() = 0;
        virtual const bool estAllume() = 0;
};