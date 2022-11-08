#include <Arduino.h>
#include <passageDeParametres2.h>
#include <Flasher.h>
void passageDeParametres2(int *&p_rp, int **p_pp)
{
    Serial.println("Apres appel à la fonction passageDeParametres1(valeur1,valeur2);");
    Serial.println("int p_rp (int * : 0x" + String((uint16_t)(&p_rp), HEX) + ") = " + String(*p_rp));
    Serial.println("int *&p_rp (int ** : 0x" + String((uint16_t)(&p_rp), HEX) + ") adresse : 0x" + String((uint16_t)p_rp, HEX) + " = " + String(*p_rp));
    Serial.println("int **p_pp (int ** : 0x" + String((uint16_t)(&p_pp), HEX) + ") adresse : 0x" + String((uint16_t)p_pp, HEX) + " = " + String(**p_pp));
}
void passageDeParametresCopie2(Flasher p_flasher)
{
    Serial.println("Flasher (p_flasher : 0x" + String((uint16_t)(&p_flasher), HEX) + ") = " + String((uint16_t)(&p_flasher), HEX));
}
void passageDeParametresReference2(Flasher &p_flasher)
{
    Serial.println("Flasher (p_flasher : 0x" + String((uint16_t)(&p_flasher), HEX) + ") = " + String((uint16_t)(&p_flasher), HEX));
}
void passageDeParametresPointeur2(Flasher *p_flasher)
{
    Serial.println("Flasher (p_flasher : 0x" + String((uint16_t)(&p_flasher), HEX) + ") = " + String((uint16_t)(&p_flasher), HEX));
}