#include <Arduino.h>
#include <passageDeParametres2.h>
void setup()
{
  // put your setup code here, to run once:
  Serial.end();
  Serial.begin(9600);
  int valeur1 = 42;
  int valeur2 = 13;
  int *val1 = &valeur1;
  int *val2 = &valeur2;
  int *val2_p = val2;
  Serial.println(42);
  Serial.println("Bonjour à tous!");
  Serial.println(String(42, HEX));
  Serial.println("0x" + String(42, HEX));
  Serial.println("int valeur 1 (int * : 0x" + String((uint16_t)(&val1), HEX) + ")= " + String(valeur1));
  Serial.println("int valeur 2 (int * : 0x" + String((uint16_t)(&val2), HEX) + ")= " + String(valeur2));
  Serial.println("Appel de passageDeParametres2(&val1,val1_p);");
  passageDeParametres2(val1, &valeur2);
}

void loop()
{
  // put your main code here, to run repeatedly:
}