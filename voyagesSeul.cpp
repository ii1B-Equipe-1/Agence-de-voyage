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

bool voyagesSeul::est_vide()
{
    if (tabVoyageSeul.size()==0)
        return true;
    return false;
}

void voyagesSeul::retarder_voyages_seul(Date dep)
{
    int nbRet = 0;
    for (int i=0; i < tabVoyageSeul.size(); i++)
        if (tabVoyageSeul[i].getDateDepart() == dep)
        {
            tabVoyageSeul[i].retarder_voyage();
            nbRet++;
        }
    if (nbRet == 0)
        cout << " Aucun voyage seul n'a été retardé"<< endl << endl;
    else
        cout << " " << nbRet << " voyages seul ont été retardé" << endl << endl;
}

void voyagesSeul::liste_voyages_pays(Destination dest)
{
    bool test = false;
    for (int i=0; i < tabVoyageSeul.size(); i++)
        if (tabVoyageSeul[i].getDestination() == dest)
        {
            tabVoyageSeul[i].afficher_voyage();
            test = true;
        }
    if (test == false)
        cout << "  * Aucun voyage seul vers cette destination pour le moment " << endl;
}



void voyagesSeul::writeToFile()
{

    ofstream out;
    out.open("fichier_voyagesSeul");
    out << tabVoyageSeul.size() << endl;
    for (int i=0; i<tabVoyageSeul.size();i++)
    {
        tabVoyageSeul[i].write(out);
        out << endl;
    }
    out.close();
}

void voyagesSeul::readFile()
{
    ifstream in;
    in.open("fichier_voyagesSeul");
    int nb;
    in >> nb;
    for (int i=0; i < nb; i++)
    {
        voyageSeul voy;
        voy.read(in);
        tabVoyageSeul.push_back(voy);
    }
    in.close();
}
