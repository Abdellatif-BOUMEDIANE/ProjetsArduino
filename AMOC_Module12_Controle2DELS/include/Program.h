#pragma once 

#include "ServeurWeb.h"

#include "Actionneur.h"

class Program
{
    private:
        ServeurWeb* m_serveur;
        void listeFileDansDossier(File dossier, int numerotab);
        std::vector<Actionneur*> m_actionneurs;
        
    public:
        Program();
        const void loop();
        const void Configuration();
};