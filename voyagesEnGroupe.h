#ifndef VOYAGESENGROUPE_H
#define VOYAGESENGROUPE_H

#include "voyage.h"
#include <vector>
#include "voyageEnGroupe.h"
#include "destination.h"
#include "date.h"
using namespace std;

class voyagesEnGroupe
{
    private:
        vector<voyageEnGroupe> tabVoyageEnGroupe;
    public:
        voyagesEnGroupe();
        ~voyagesEnGroupe();
        int existe(string idVoy);
        bool ajouter_voyageEnGroupe(voyageEnGroupe);
        void afficher_groupes();
        void afficher_groupes(Destination);
        int nb_voyagesEnGroupe();
        vector<string> groupes_disponibles(); //affiche tous les groupes disponibles et retourne les id dans un vecteur
        vector<string> groupes_disponibles(Destination);// affiche les groupes disponible pour une destination et retourne les id dans un vecteur
        bool existe_groupes_disponibles();
        bool existe_groupes_disponibles(Destination);
        voyageEnGroupe& getVoyage(const string& idVoy);
};


#endif