#include <Arduino.h>

const int borneEntree = 2;
const int borneSortie = 3;
const int borneSortieAnalogue = 10;
int valeurAllumageAnalog;
int dernierEtatLed = LOW;
int etatLed = LOW;
long derniereDateChangement = 0;
int dernierEtatBouton = HIGH;
int dernierEtatStableBouton = HIGH;
const int delaiMinPression = 25;
void setup()
{
  pinMode(borneSortieAnalogue, OUTPUT);
  pinMode(borneSortie, OUTPUT);
  pinMode(borneEntree, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int etatBouton = digitalRead(borneEntree);
  long dateActuelle = millis();
  if (etatBouton != dernierEtatBouton)
  {
    derniereDateChangement = dateActuelle;
    dernierEtatBouton = etatBouton;
  }
  if (dateActuelle - derniereDateChangement > delaiMinPression)
  {
    if (dernierEtatStableBouton == LOW && etatBouton == HIGH)
    {
      dernierEtatLed = !dernierEtatLed;
      digitalWrite(borneSortie, dernierEtatLed);
      valeurAllumageAnalog = 255;
      if (!dernierEtatLed)
      {
        valeurAllumageAnalog = 0;
      }
      analogWrite(borneSortieAnalogue, valeurAllumageAnalog);
    }
    dernierEtatStableBouton = etatBouton;
  }
}