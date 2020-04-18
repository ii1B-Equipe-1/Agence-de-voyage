#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>
#include "date.h"
using namespace std;

class client
{
    private:
        string numPasseport;
        string Nom;
        string Prenom;
        Date DateNaissance;
        vector<string> VoyagesClient; // vecteur contenant les idVoyage du client
    public:
        client();
        client(const string&, const string&, const string&, Date);
        ~client();
        string getNumPasseport();
        string getNom();
        string getPrenom();
        Date getDateNaissance();
        vector<string> getVoyagesClient();
        bool ajouter_voyage(string idVoy);
        int participe_au_voyage(string idVoy); // retourne la pos du voyage dans VoyagesClient si le voy existe sinon -1
        friend ostream& operator<<(ostream&, const client&);//affiche le client (sans afficher les voyages)
};


class clients
{
    public:
        vector<client> tabClient;
    public:
        clients();
        ~clients();
        int existe(const string&); //basé sur numPasseport (retourne la position ou bien -1)
        bool ajouter_client( client );
        bool supprimer_client(const string&);//supprime un client à partir de son numPasseport
        void saisir_client();//crée un client et l'ajoute à tabclient
};



/**** autres fonctions ****/
bool est_majus(const string&);
bool est_numPasseport(const string&); //verifie si une chaine est un numPass valide
string saisir_numPasseport();
#endif