#pragma once

#include <Arduino.h>

#include <WebServer.h>

#include <SPIFFS.h>

#include "Actionneur.h"

class ServeurWeb {

    private:
        std::vector<Actionneur*> m_actionneurs;
        WebServer* m_webServer;
        void afficherRacine();
        void ajouterFichiersStatiques(String const& p_debutNomFichier);
        void ajouterFichiersStatiques(String const& p_debutNomFichier, File& p_fichier);
        void ressourceNonTrouvee(String const& p_nomFichier);
        void actionner(int const& p_id);
    
    public:
        ServeurWeb(std::vector<Actionneur*> p_actionneurs);
        void tick();
};

