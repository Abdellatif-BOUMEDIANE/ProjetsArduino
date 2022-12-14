#include <Arduino.h>
#include <Program.h>
const int borneEntree = 2;
const int borneSortie = 10;

Program *ptrprogram;
void setup()
{
  ptrprogram = new Program(borneSortie, borneEntree);
}

void loop()
{
  ptrprogram->loop();
}
