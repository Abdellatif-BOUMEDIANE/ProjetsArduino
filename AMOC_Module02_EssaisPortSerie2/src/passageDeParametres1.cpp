#include <Arduino.h>
#include <passageDeParametres1.h>
#include <Flasher.h>
void passageDeParametres1(int p_v1, int &p_r1, int *p_p1)
{
    Serial.println("int p_v1 (int * : 0x" + String((uint16_t)(&p_v1), HEX) + ") = " + String(p_v1));
    Serial.println("int &p_v1 (int * : 0x" + String((uint16_t)(&p_r1), HEX) + ") = " + String(p_r1));
    Serial.println("int *p_p1 (int ** : 0x" + String((uint16_t)(&p_p1), HEX) + ") adresse : 0x" + String((uint16_t)p_p1, HEX) + " = " + String(*p_p1));
}
void passageDeParametresCopie1(Flasher p_flasher)
{
    Serial.println("Flasher (p_flasher : 0x" + String((uint16_t)(&p_flasher), HEX) + ") = " + String((uint16_t)(&p_flasher), HEX));
}
void passageDeParametresReference1(Flasher &p_flasher)
{
    Serial.println("Flasher (p_flasher : 0x" + String((uint16_t)(&p_flasher), HEX) + ") = " + String((uint16_t)(&p_flasher), HEX));
}
void passageDeParametresPointeur1(Flasher *p_flasher)
{
    Serial.println("Flasher (p_flasher : 0x" + String((uint16_t)(&p_flasher), HEX) + ") = " + String((uint16_t)(&p_flasher), HEX));
}