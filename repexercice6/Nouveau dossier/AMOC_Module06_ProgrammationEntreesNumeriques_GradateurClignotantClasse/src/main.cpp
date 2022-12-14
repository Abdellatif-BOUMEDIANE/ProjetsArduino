#include <Arduino.h>
#include <Program.h>
// const
const int borneEntree = 2;
const int borneSortie = 10;
const int borneEntreeClignotement = 4;
const int borneSortieClignotement = 9;

Program *ptrprogram;
void setup()
{
  Serial.end();
  Serial.begin(9600);
  ptrprogram = new Program(borneSortie, borneSortieClignotement, borneEntree, borneEntreeClignotement);
}

void loop()
{

  ptrprogram->loop();
}
