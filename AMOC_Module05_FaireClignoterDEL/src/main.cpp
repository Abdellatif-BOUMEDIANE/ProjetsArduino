#include <Arduino.h>
int bornePotentiometre = A0;
const int borneSortie3 = 3;
const int borneSortie5 = 5;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("démarrage de la console");
  pinMode(borneSortie3, OUTPUT);
  pinMode(borneSortie5, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // put your main code here, to run repeatedly:
  static int valeurLue;
  valeurLue = analogRead(bornePotentiometre);
  Serial.print("Valeur Lue =");
  Serial.print(valeurLue);
  Serial.print(" Ve = ");
  Serial.print(valeurLue * 5.0 / 1024.0);
  Serial.println("V");
  int valeurBorneSortie = 255 - map(valeurLue, 0, 1023, 0, 255);
  analogWrite(borneSortie3, 255 - map(valeurLue, 0, 1023, 0, 255));
  analogWrite(borneSortie5, map(valeurLue, 0, 1023, 0, 255));
}