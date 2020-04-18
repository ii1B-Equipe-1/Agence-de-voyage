#ifndef DESTINATION_H
#define DESTINATION_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Destination
{
    private:
        string Pays;
        string Ville;
    public:
        Destination(const string&, const string&); //constructeur
        ~Destination();
        string getPays();
        string getVille();
        void setPays(const string&);
        void setVille(const string&);
        bool operator==(const Destination&);
        friend ostream& operator<<(ostream&, const Destination&);
};

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