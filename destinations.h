#ifndef DESTINATIONS_H
#define DESTINATIONS_H

#include <iostream>
#include <string>
#include <vector>
#include "destination.h"
using namespace std;

class Destinations
{
    protected:
        vector<Destination> tabDestination;
    public:
        Destinations();
        ~Destinations();
        int existe(const Destination&); //retourne la position dans le vecteur sinon -1
        bool ajouter_destination(const Destination&);
        bool supprimer_destination(const Destination&);
        void saisir_destination();//a partir du clavier
        void enlever_destination();//a partir du clavier
        friend ostream& operator<<(ostream&, const Destinations&);
};


#endif