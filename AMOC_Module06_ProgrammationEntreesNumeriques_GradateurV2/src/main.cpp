#include <Arduino.h>

const int borneEntree = 2;
const int borneSortie = 3;
const int borneSortieAnalogue = 10;

int dernierEtatLed = LOW;
int luminance = 0;
int pasIncrementation = 9;
int pasDecrementation = -25;
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

      if (luminance == 0)
      {
        pasIncrementation = 25;
      }

      if (luminance == 100)
      {
        pasIncrementation = -25;
      }

      luminance = luminance + pasIncrementation;
      analogWrite(borneSortieAnalogue, luminance * 2.55);
      Serial.println(luminance);
    }
    dernierEtatStableBouton = etatBouton;
  }
}
