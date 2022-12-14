#pragma once

#include "Action.h"

#include "./DEL/DEL.h"

class ActionAnimerDelsClient : public Action
{
private:
    DEL **m_tableauDesDels;

public:
    ActionAnimerDelsClient(DEL **p_tableauDesDels[2]);
    const void executer();
};