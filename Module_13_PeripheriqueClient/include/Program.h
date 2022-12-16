#pragma once
#include <Arduino.h>
#include "WebClient.h"
#include "Bouton.h"

class Program
{
private:
  WebClient *m_webClient;

  Bouton *m_bouton;

public:
  Program();

  void boucle();

  void connectionReseau();
};
