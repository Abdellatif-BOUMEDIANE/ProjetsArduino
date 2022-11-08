#include <Arduino.h>
#include <passageDeParametres2.h>
#include <Flasher.h>
#include <MorseDEL.h>
#include <Morse.h>
#include <MorseSerie.h>

Flasher flasher(LED_BUILTIN, 500);

void setup()
{
  // put your setup code here, to run once:

  // Serial.end();
  // Serial.begin(9600);
  // int valeur1 = 42;
  // int *val_r = &valeur1;
  // int valeur2 = 13;
  // int *val_p = &valeur2;
  // Serial.println("Avant appel à la fonction passageDeParametres1(valeur1,valeur2);");
  // Serial.println("int *&valeur1 (int ** : 0x" + String((uint16_t)(&val_r), HEX) + ") adresse : 0x" + String((uint16_t)val_r, HEX) + " = " + String(*val_r));
  // Serial.println("int **valeur2 (int ** : 0x" + String((uint16_t)(&val_p), HEX) + ") adresse : 0x" + String((uint16_t)val_p, HEX) + " = " + String(*val_p));
  // Serial.println("Appel de passageDeParametres2(*&valeur1,**valeur2);");
  // passageDeParametres2(val_r, &val_p);
  Flasher flasherDuSetup(LED_BUILTIN, 200);
  flasher = flasherDuSetup;
  Serial.println("Flasher (p_flasher : 0x" + String((uint16_t)(&flasher), HEX) + ") = " + String((uint16_t)(&flasher), HEX));
  Serial.println("Flasher (p_flasherDuSetup : 0x" + String((uint16_t)(&flasherDuSetup), HEX) + ") = " + String((uint16_t)(&flasherDuSetup), HEX));
  // passageDeParametresCopie2(flasher);
  // passageDeParametresCopie2(flasherDuSetup);
  // passageDeParametresReference2(flasher);
  // passageDeParametresReference2(flasherDuSetup);
  passageDeParametresPointeur2(&flasher);
  passageDeParametresPointeur2(&flasherDuSetup);
  Morse *morse;
  MorseSerie morseSerie(100);
  morse = &morseSerie;
}

void loop()
{
  // put your main code here, to run repeatedly:
  flasher.FaireClignoter(1);
}