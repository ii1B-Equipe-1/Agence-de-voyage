#include "destination.h"
using namespace std;

/**** Méthodes de la classe Destination ****/
Destination::Destination(const string& p, const string& v)
{
    Pays = p;
    Ville = v;
}

Destination::~Destination(){}

string Destination::getPays()
{
    return Pays;
}

string Destination::getVille()
{
    return Ville;
}

void Destination::setPays(const string& p)
{
    Pays = p;
}

void Destination::setVille(const string& v)
{
    Ville = v;
}

bool Destination::operator==(const Destination& dest)
{
    if ((Pays==dest.Pays) && (Ville == dest.Ville))
        return true;
    return false;
}

ostream& operator<<(ostream& output, const Destination& dest)
{
    output << dest.Pays << ", " << dest.Ville;
    return output ;
}

/**** Méthodes de la classe Destinations ****/

Destinations::Destinations(){};

Destinations::~Destinations(){};

int Destinations::existe(const Destination& dest)
{
    for(int i=0; i<tabDestination.size(); i++)
        if (tabDestination[i] == dest)
            return i;
    return -1;
}

bool Destinations::ajouter_destination(const Destination& dest)
{
    if (existe(dest) == -1)
    {
        tabDestination.push_back(dest);
        return true;
    }
    return false;
}

bool Destinations::supprimer_destination(const Destination& dest)
{
    if (existe(dest) != -1)
    {
        int pos = existe(dest);
        for (int i=pos; i<tabDestination.size()-1; i++)
            tabDestination[i] = tabDestination [i+1];
        tabDestination.pop_back();
        return true;
    }
    return false;
        
}

ostream& operator<<(ostream& output, const Destinations& d)
{
    if (d.tabDestination.empty())
        output << "   *  Aucune destination" << endl;
    else
    {
        for (int i=0; i < d.tabDestination.size(); i++)
            output << "   *  " << d.tabDestination[i] << endl;
        return output;
    }
}


void Destinations::saisir_destination()
{
    cout << "Les destinations actuelles :" << endl;
    cout << *this <<endl ;
    cout <<"--->  Donner le pays de la destination à ajouter :  ";
    string p;
    cin >> p;
    cout << "--->  Donner le nom de la ville :  ";
    string v;
    cin >> v;
    Destination dest (p, v);
    if (ajouter_destination(dest))
        cout << "La destination " << dest <<" à bien été ajoutée" << endl;
    else
        cout << "La destination " << dest <<" n'a pas pu être ajoutée" << endl;
}

void Destinations::enlever_destination()
{
    cout << "Les destinations actuelles :" << endl;
    cout << *this << endl;
    cout <<"Donner le pays de la destination à enlever :  ";
    string p;
    cin >> p;
    cout << "Donner le nom de la ville :  ";
    string v;
    cin >> v;
    Destination dest (p, v);
    if (supprimer_destination(dest))
        cout << "La destination " << dest <<" à bien été enlevée" << endl;
    else
        cout << "La destination " << dest <<" n'a pas pu être enlevée" << endl;
}