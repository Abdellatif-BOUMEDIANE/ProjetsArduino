#include <Arduino.h>
#include <GestionDELInterne.h>
#include <Configuration.h>
void setup()
{
  // put your setup code here, to run once:
  // Serial.end();
  // Serial.begin(9000);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  AfficherSEnMorse(dureeDELAllumeeS, dureeDELEteinteS);
  AfficherOEnMorse(dureeDELAllumeeO, dureeDELEteinteO);
  AfficherSEnMorse(dureeDELAllumeeS, dureeDELEteinteS);
  AfficherBoucle(delaiBoucle);
}