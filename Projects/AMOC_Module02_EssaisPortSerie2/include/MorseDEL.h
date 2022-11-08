#pragma once
#include <Arduino.h>
#include <Morse.h>
class MorseDEL : public Morse
{
private:
    int m_pinDEL;

public:
    MorseDEL(const int &p_dureepoint, const int &p_pinDel);
    void afficherPoint() const;
    void afficherTrait() const;
};