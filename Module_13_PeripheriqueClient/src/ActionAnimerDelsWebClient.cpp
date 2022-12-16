#include "Arduino.h"
#include "ActionAnimerDelsWebClient.h"
#include "Action.h"
#include "WebClient.h"
#include "ReacteurNucleaire.h"

ActionAnimerDelsWebClient::ActionAnimerDelsWebClient(WebClient *p_webClient) : m_webClient(p_webClient)
{
    ;
}

void const ActionAnimerDelsWebClient::executer()
{
    this->m_webClient->permuterEtat();
}
