#include <Arduino.h>
#include <GestionDELInterne.h>
void allumerDELInterne(int p_duree)
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(p_duree);
}
void eteindreDELInterne(int p_duree)
{
    digitalWrite(LED_BUILTIN, LOW);
    delay(p_duree);
}
void AfficherSEnMorse(int valeur1, int valeur2)
{
    allumerDELInterne(valeur1);
    eteindreDELInterne(valeur2);
    allumerDELInterne(valeur1);
    eteindreDELInterne(valeur2);
    allumerDELInterne(valeur1);
    eteindreDELInterne(valeur2);
}
void AfficherOEnMorse(int valeur1, int valeur2)
{
    allumerDELInterne(valeur1);
    eteindreDELInterne(valeur2);
    allumerDELInterne(valeur1);
    eteindreDELInterne(valeur2);
    allumerDELInterne(valeur1);
    eteindreDELInterne(valeur2);
}
void AfficherBoucle(int valeur1)
{
    eteindreDELInterne(valeur1);
}