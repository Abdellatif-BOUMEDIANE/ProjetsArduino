#include <Arduino.h>
#include <passageDeParametres2.h>
void passageDeParametres2(int &p_rp, int **p_pp)
{
    Serial.println("int p_v1 (int * : 0x" + String((uint16_t)(&p_rp), HEX) + ") = " + String(*p_rp));
    Serial.println("int &p_v1 (int * : 0x" + String((uint16_t)(&p_rp), HEX) + ") = " + String(*p_rp));
    Serial.println("int *p_p1 (int ** : 0x" + String((uint16_t)(&p_pp), HEX) + ") adresse : 0x" + String((uint16_t)p_pp, HEX) + " = " + String(*p_pp));
    int *temp = new int;
    *temp = 42;
    p_rp = temp;
    int *temp1 = new int;
    *temp1 = 13;
    int *temp2;
    temp2 = temp1;
    int *temp3;
    temp3 = temp2;
    p_pp = temp3;
}