#include <Arduino.h>
#include <DEL.h>
#include <MorseDEL.h>
MorseDEL::MorseDEL(const int &p_dureePoint, const int &_pindel) : Morse(p_dureePoint)
{
}
void MorseDEL::afficherPoint() const
{
    Serial.println(".");
}
void MorseDEL::afficherTrait() const
{
    Serial.println("-");
}
