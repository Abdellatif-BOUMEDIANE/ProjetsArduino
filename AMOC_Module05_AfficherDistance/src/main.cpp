#include <Arduino.h>
const int borneTrigger = 10;
const int borneEcho = 8;
long duree, cm, pouces;
int distance;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("démarrage de la console");
  pinMode(borneTrigger, OUTPUT);
  pinMode(borneEcho, INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(borneTrigger, LOW);
  delayMicroseconds(5);
  digitalWrite(borneTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(borneTrigger, LOW);
  duree = pulseIn(borneEcho, HIGH);
  cm = (duree / 2) / 29.1;
  Serial.print(cm);
  Serial.println(" cm de distance");
}