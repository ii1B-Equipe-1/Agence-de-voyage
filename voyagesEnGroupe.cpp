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
    if (existe(g.getIdVoyage()) != -1)
        return false;
    else
        {
            tabVoyageEnGroupe.push_back(g);
            return true;
        }
}

void voyagesEnGroupe::afficher_groupes()
{
    if (tabVoyageEnGroupe.size()==0)
        cout << "  * Aucun groupe pour le moment " << endl;
    else
        for (int i=0; i<tabVoyageEnGroupe.size(); i++)
            tabVoyageEnGroupe[i].afficher_voyage();
}

void voyagesEnGroupe::afficher_groupes(Destination dest)
{
    if (tabVoyageEnGroupe.size()==0)
        cout << "  * Aucun groupe vers cette destination pour le moment " << endl;
    else
        for (int i=0; i<tabVoyageEnGroupe.size(); i++)
            if (tabVoyageEnGroupe[i].getDestination() == dest)
                tabVoyageEnGroupe[i].afficher_voyage();
}

int voyagesEnGroupe::nb_voyagesEnGroupe()
{
    return tabVoyageEnGroupe.size();
}

vector<string> voyagesEnGroupe::groupes_disponibles()
{
    vector <string> disponibles;
    if (existe_groupes_disponibles())
    {
        cout << "Les groupes disponibles :  " << endl;
        for (int i =0; i< tabVoyageEnGroupe.size(); i++)
        {
            if (tabVoyageEnGroupe[i].nb_participants() < 15)
                tabVoyageEnGroupe[i].afficher_voyage();
                disponibles.push_back(tabVoyageEnGroupe[i].getIdVoyage());   
        }
    }
    else
        cout << endl << "   Aucun groupe disponible " << endl << endl;
    return disponibles;
}

vector<string> voyagesEnGroupe::groupes_disponibles(Destination d)
{
    vector <string> disponibles;
    if (existe_groupes_disponibles(d))
    {
        cout << "Les groupes disponibles :  " << endl;
        for (int i =0; i< tabVoyageEnGroupe.size(); i++)
        {
            if ((tabVoyageEnGroupe[i].nb_participants() < 15) && (tabVoyageEnGroupe[i].getDestination() == d))
                tabVoyageEnGroupe[i].afficher_voyage();
                disponibles.push_back(tabVoyageEnGroupe[i].getIdVoyage());   
        }
    }
    else
        cout << endl << "   Aucun groupe disponible " << endl << endl;
    return disponibles;
}

vector<string> voyagesEnGroupe::tous_les_groupes()
{
    vector<string> v;
    for (int i=0; i<tabVoyageEnGroupe.size(); i++)
        v.push_back(tabVoyageEnGroupe[i].getIdVoyage());
    return v;
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

voyageEnGroupe& voyagesEnGroupe::getVoyage(const string& idVoy)
{
    if (existe(idVoy) != -1)
        return tabVoyageEnGroupe[existe(idVoy)];
}


void voyagesEnGroupe::annuler_voyage(const string& idVoy)
{
    if (existe(idVoy) != -1)
    {
        int pos = existe(idVoy);
        for (int i=pos; i<tabVoyageEnGroupe.size()-1;i++)
            tabVoyageEnGroupe[i] = tabVoyageEnGroupe[i+1];
        tabVoyageEnGroupe.pop_back();
    }
}