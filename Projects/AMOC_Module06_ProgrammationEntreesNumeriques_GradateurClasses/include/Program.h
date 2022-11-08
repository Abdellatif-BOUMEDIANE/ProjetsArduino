#pragma once

#include <Arduino.h>
#include <Bouton.h>

class Program
{
private:
    Bouton *m_bouton;

public:
    Program();
    void loop();
};