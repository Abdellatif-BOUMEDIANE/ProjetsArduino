#include <Arduino.h>
#include <Morse.h>
Morse::Morse(const int &p_dureePoint)
    : m_dureePoint(p_dureePoint)
{
}
void Morse::afficherPoint() const
{
    Serial.end();
    Serial.begin(9600);
    Serial.println(".");
}
void Morse::afficherTrait() const
{
    Serial.println("-");
}
void Morse::afficherSOS() const
{
    afficherPoint();
    afficherPoint();
    afficherPoint();
    afficherTrait();
    afficherTrait();
    afficherTrait();
    afficherPoint();
    afficherPoint();
    afficherPoint();
}
int Morse::getDureePoint() const
{
    return this->m_dureePoint;
};