#include <Arduino.h>
#include <passageDeParametres2.h>
#include <Flasher.h>

Flasher flasher(LED_BUILTIN, 500);
void setup()
{
  // put your setup code here, to run once:
  Serial.end();
  Serial.begin(9600);
  int valeur1 = 42;
  int *val_r = &valeur1;
  int valeur2 = 13;
  int *val_p = &valeur2;
  Serial.println("Avant appel à la fonction passageDeParametres1(valeur1,valeur2);");
  Serial.println("int *&valeur1 (int ** : 0x" + String((uint16_t)(&val_r), HEX) + ") adresse : 0x" + String((uint16_t)val_r, HEX) + " = " + String(*val_r));
  Serial.println("int **valeur2 (int ** : 0x" + String((uint16_t)(&val_p), HEX) + ") adresse : 0x" + String((uint16_t)val_p, HEX) + " = " + String(*val_p));
  Serial.println("Appel de passageDeParametres2(*&valeur1,**valeur2);");
  passageDeParametres2(val_r, &val_p);
}

void loop()
{
  // put your main code here, to run repeatedly:
  flasher.FaireClignoter(1);
}