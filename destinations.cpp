#include "destinations.h"


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
    //cout << "Les destinations actuelles :" << endl;
    //cout << *this <<endl ;
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
    //cout << "Les destinations actuelles :" << endl;
    //cout << *this << endl;
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



//méthodes permettant à l'utilisateur de gérer les destinations possibles

void menu_gestion_destinations()
{   cout << endl ;
    cout << "   1- Afficher les destinations actuelles" << endl ;
    cout << "   2- Ajouter une destination" << endl ;
    cout << "   3- Supprimer une destination" << endl;
    cout << "   4- Retour au menu précédent" << endl << endl; 
}
void gerer_destinations(Destinations& tabDestination)
{
    int choix;
    do
    {
        menu_gestion_destinations();
        cout << "votre choix ---> ";
        cin >> choix;
        switch (choix)
        {
        case 1:
            cout << tabDestination ; break;
        case 2:
            tabDestination.saisir_destination(); break;
        case 3:
            tabDestination.enlever_destination(); break;
        case 4: break;
        default:
            cout << "Choix invalide, réessayez" << endl ; 
        }
    }
    while (choix != 4);
    
}