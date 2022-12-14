#pragma once
#include <Flasher.h>
void passageDeParametres2(int *&p_rp, int **p_pp);
void passageDeParametresCopie2(Flasher p_flasher);
void passageDeParametresReference2(Flasher &p_flasher);
void passageDeParametresPointeur2(Flasher *p_flasher);