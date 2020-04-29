#include "voyagesSeul.h"
using namespace std;

voyagesSeul::voyagesSeul(){};
voyagesSeul::~voyagesSeul(){};

int voyagesSeul::existe(string idVoy)
{
    for (int i=0; i < tabVoyageSeul.size(); i++)
        if (tabVoyageSeul[i].getIdVoyage() == idVoy)
            return i;
    return -1;
}

bool voyagesSeul::ajouter_voyageSeul(voyageSeul v)
{
    if (existe(v.getIdVoyage()) == -1)
    {
        tabVoyageSeul.push_back(v);
        return true;
    }
    return false;
}

void voyagesSeul::afficher_voyagesSeul(clients& c)
{
    for (int i=0; i < tabVoyageSeul.size(); i++)
    {
        cout << "Client :  " <<endl<< c.getClient(tabVoyageSeul[i].getNumPasseport());
        tabVoyageSeul[i].afficher_voyage();
    }
}

voyageSeul& voyagesSeul::getVoyage(const string& idVoy)
{
    if (existe(idVoy) != -1)
        return tabVoyageSeul[existe(idVoy)];
}

vector<string> voyagesSeul::afficher_voyages_client(const string& numPass)
{
    vector<string> vect;
    for (int i=0; i < tabVoyageSeul.size(); i++)
        if (tabVoyageSeul[i].getNumPasseport() == numPass)
        {
            tabVoyageSeul[i].afficher_voyage();
            vect.push_back(tabVoyageSeul[i].getIdVoyage());
        }
    return vect;
}

vector<string> voyagesSeul::afficher_futur_voyages_client(const string& numPass)
{
    vector<string> vect;
    for (int i=0; i < tabVoyageSeul.size(); i++)
        if ((tabVoyageSeul[i].getNumPasseport() == numPass) && (tabVoyageSeul[i].getDateDepart() > date_systeme()))
        {
            tabVoyageSeul[i].afficher_voyage();
            vect.push_back(tabVoyageSeul[i].getIdVoyage());
        }
    return vect;
}

bool voyagesSeul::annuler_voyage(const string& idVoy)
{
    int pos = existe(idVoy);
    if (pos == -1)
        return false;
    if (existe(idVoy)!=-1)
    {
        for (int i=pos; i<tabVoyageSeul.size()-1;i++)
            tabVoyageSeul[i]=tabVoyageSeul[i+1];
        tabVoyageSeul.pop_back();
        return true;
    }   
}