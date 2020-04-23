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
        //cout << "Client :  " <<endl<< c.getClient(tabVoyage[i].getNumPasseport());
        tabVoyageSeul[i].afficher_voyage();
    }
}

voyageSeul& voyagesSeul::getVoyage(const string& idVoy)
{
    if (existe(idVoy) != -1)
        return tabVoyageSeul[existe(idVoy)];
}