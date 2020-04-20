#include "voyagesEnGroupe.h"
using namespace std;

voyagesEnGroupe::voyagesEnGroupe(){};
voyagesEnGroupe::~voyagesEnGroupe(){};
int voyagesEnGroupe::existe(string idVoy)
{
    for (int i=0; i < tabVoyageEnGroupe.size() ; i++)
        if (tabVoyageEnGroupe[i].getIdVoyage() == idVoy)
            return i;
    return -1;
}
bool voyagesEnGroupe::ajouter_voyageEnGroupe(voyageEnGroupe g)
{
    if (existe(g.getIdVoyage()))
        return false;
    else
        {
            tabVoyageEnGroupe.push_back(g);
            return true;
        }
}

void voyagesEnGroupe::afficher_groupes()
{
    for (int i=0; i<tabVoyageEnGroupe.size(); i++)
    {
        cout << "*** Groupe i : " << endl;
        tabVoyageEnGroupe[i].afficher_groupe();
    }
}

int voyagesEnGroupe::nb_voyagesEnGroupe()
{
    return tabVoyageEnGroupe.size();
}

vector<string> voyagesEnGroupe::groupes_disponibles()
{
    vector <string> disponibles;
    cout << "Les groupes disponibles :  " << endl;
    for (int i =0; i< tabVoyageEnGroupe.size(); i++)
    {
        if (tabVoyageEnGroupe[i].nb_participants() <= 15)
            tabVoyageEnGroupe[i].afficher_groupe();
            disponibles.push_back(tabVoyageEnGroupe[i].getIdVoyage());   
    }
    return disponibles;
}

vector<string> voyagesEnGroupe::groupes_disponibles(Destination d)
{
    vector <string> disponibles;
    cout << "Les groupes disponibles :  " << endl;
    for (int i =0; i< tabVoyageEnGroupe.size(); i++)
    {
        if ((tabVoyageEnGroupe[i].nb_participants() < 15) && (tabVoyageEnGroupe[i].getDestination() == d))
            tabVoyageEnGroupe[i].afficher_groupe();
            disponibles.push_back(tabVoyageEnGroupe[i].getIdVoyage());   
    }
    return disponibles;
}

bool voyagesEnGroupe::existe_groupes_disponibles()
{
    for (int i=0; i < tabVoyageEnGroupe.size(); i++)
        if (tabVoyageEnGroupe[i].nb_participants() < 15 )
            return true ;
    return false;
}

bool voyagesEnGroupe::existe_groupes_disponibles(Destination d)
{
    for (int i=0; i < tabVoyageEnGroupe.size(); i++)
        if ((tabVoyageEnGroupe[i].nb_participants() < 15) && (tabVoyageEnGroupe[i].getDestination() == d ))
            return true ;
    return false;
}