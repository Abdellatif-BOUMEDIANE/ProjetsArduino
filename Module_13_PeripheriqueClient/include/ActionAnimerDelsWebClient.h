#pragma once
#include "Action.h"
#include "WebClient.h"
#include "ReacteurNucleaire.h"

class ActionAnimerDelsWebClient : public Action
{
private:
    WebClient *m_webClient;

public:
    ActionAnimerDelsWebClient(WebClient *p_webClient);
    virtual const void executer();
};