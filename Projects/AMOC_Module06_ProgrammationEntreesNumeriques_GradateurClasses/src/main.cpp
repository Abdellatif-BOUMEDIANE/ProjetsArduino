#include <Arduino.h>
const int borneEntree = 2;
const int borneSortie = 10;
int luminance = 0;
int pasIncrementation = 63;
// int dernierEtatLed = LOW;
long derniereDateChangement = 0;
int dernierEtatBouton = HIGH;
int dernierEtatStableBouton = HIGH;
const int delaiMinPression = 25;
void setup()
{
  pinMode(borneSortie, OUTPUT);
  pinMode(borneEntree, INPUT);
}

void loop()
{
  /*
  int etatBouton = digitalRead(borneEntree);
  long dateActuelle = millis();
  if (etatBouton != dernierEtatBouton)
  {
    derniereDateChangement = dateActuelle;
    dernierEtatBouton = etatBouton;
  }
  if (dateActuelle - derniereDateChangement > delaiMinPression)
  {
    if (dernierEtatStableBouton == HIGH && etatBouton == LOW)
    {
      // bouton appuyé
      // Action à réaliser
    }
    else if (dernierEtatStableBouton == LOW && etatBouton == HIGH)
    {
      // bouton relaché
      // ... et donc comme click
      // Action à réaliser
      luminance += pasIncrementation;
      if (luminance > 255 || luminance < 0)
        pasIncrementation = -pasIncrementation;
    }
    // dernierEtatLed = !dernierEtatLed;
    analogWrite(borneSortie, luminance);
  }
  dernierEtatStableBouton = etatBouton;
  */
}
