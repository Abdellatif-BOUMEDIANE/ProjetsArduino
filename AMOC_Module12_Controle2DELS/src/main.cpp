#include <Arduino.h>

#include "Program.h"

#define VITESSE 115200

Program* pointeurProgramme = new Program();

void setup() {

  Serial.end();
  
  Serial.begin(VITESSE);

  pointeurProgramme->Configuration();
}


void loop() {

  pointeurProgramme->loop();
  
}
