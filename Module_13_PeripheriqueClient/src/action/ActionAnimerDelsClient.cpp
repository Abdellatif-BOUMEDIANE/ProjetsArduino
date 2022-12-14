#include <Arduino.h>

#include "./../include/action/Action.h"
#include "./../include/action/ActionAnimerDelsClient.h"

const int nombreDeDels = 2;

ActionAnimerDelsClient::ActionAnimerDelsClient(DEL **p_tableauDesDels[2]) : Action()
{
    m_tableauDesDels = new DEL *[2];

    for (int position = 0; position < 6; position++)
    {
        m_tableauDesDels[position] = *p_tableauDesDels[position];
    }
}

const void ActionAnimerDelsClient::executer()
{

    char nombrePourEteindre = '0';
    char nombrePourAllumer = '1';

    // int longeurValeurBinaire = valeurBinaire.length() - 1;

    // for (int position = 0; position < 6; position++)
    // {
    //     this->m_tableauDesDels[position]->eteindre();
    // }

    // for (int i = 0; i <= longeurValeurBinaire; i++)
    // {
    //     int positionInverse = longeurValeurBinaire - i;

    //     if (valeurBinaire[i] == nombrePourEteindre)
    //     {
    //         this->m_tableauDesDels[positionInverse]->eteindre();
    //     }
    //     else if (valeurBinaire[i] == nombrePourAllumer)
    //     {
    //         this->m_tableauDesDels[positionInverse]->allumer();
    //     }
    // }
}