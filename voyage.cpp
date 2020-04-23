#include "voyage.h"
using namespace std;

voyage::voyage(){};
voyage::voyage(const string& id, Destination d, Date dep, Date ret)
{
    idVoyage = id;
    Dest = d;
    dateDepart = dep;
    dateRetour = ret;
}

string voyage::getIdVoyage()
{
    return idVoyage;
}


Destination voyage::getDestination()
{
    return Dest;
}

Date voyage::getDateDepart()
{
    return dateDepart;
}


Date voyage::getDateRetour()
{
    return dateRetour;
}

void voyage::afficher_voyage()
{
    cout << "   *IdVoyage       : " << idVoyage << endl;
    cout << "   -Destination    : " << Dest << endl;
    cout << "   -Date de depart : " << dateDepart;
    cout << "   -Date de retour : " << dateRetour;
}
