#pragma once
#include <Morse.h>
class MorseSerie : public Morse
{

public:
    MorseSerie(const int &p_dureePoint);
    MorseSerie &operatornew(const MorseSerie &p_source);
    void afficherPoint() const;
    void afficherTrait() const;
};