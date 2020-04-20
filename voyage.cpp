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
    cout << "   -Destination    : " << Dest << endl;
    cout << "   -Date de depart : " << dateDepart;
    cout << "   -Date de retour : " << dateRetour;
}

/**** autres fonctions ****/
//sans vérifier l'unicité !!!
string generer_id_voyage(bool EnGroupe, int nbVoyGroupe)
{
    srand(time(0));
    string id;
    if (!EnGroupe)
    {
        long x = rand() % 10000 + 89999;
        id = to_string(x);
        id = "000" + id;
    }
    if (EnGroupe)
    {
        long x = rand() % 10000 + 89999;
        id = to_string(x);
        int nb = nbVoyGroupe +1;
        string ch = to_string(nb);
        string ch1;
        if (nb < 10)
        {
            ch1 = "00"+ch;
        }
        if ((nb<100) && (nb >= 10))
        {
            ch1 = "0"+ch;
        }
        if ((nb >=100))
        {
            ch1 = ch;
        }
        id = ch1 + id;
    }
    return id;
}