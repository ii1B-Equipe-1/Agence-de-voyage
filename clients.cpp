
#include "clients.h"
using namespace std;

/**** Méthodes de la classe clients ****/
clients::clients(){};
clients::~clients(){};

int clients::existe(const string& numPass)
{
    for (int i=0; i<tabClient.size(); i++)
        if (tabClient[i].getNumPasseport() == numPass)
            return i;
    return -1;
}

bool clients::ajouter_client( client c )
{
    if (existe(c.getNumPasseport()) != -1)
        return false;
    else
    {
            tabClient.push_back(c);
            return true;
    } 
}

bool clients::supprimer_client(const string& numPass)
{
    if (existe(numPass) == -1)
        return false;
    else
    {
        int pos = existe(numPass);
        for (int i=pos; i < tabClient.size()-1; i++)
            tabClient[i] = tabClient[i+1];
        tabClient.pop_back();
        return true;
    }
}

void clients::saisir_client()
{
    cout << "--->  Donner le nom du client : ";
    string n;
    cin >> n;
    cout << "--->  Donner le prénom du client : " ;
    string p;
    cin >> p;
    string numPass = saisir_numPasseport();
    cout << "--->  Donner la date de naissance (jj/mm/aaaa) : ";
    Date naissance;
    do
    {
        naissance = saisir_date();
        if (!est_dateNaissance(naissance))
            cout << "La date n'est pas valide, réessayez : ";
    } while (!est_dateNaissance(naissance));
    
    client c(numPass, n, p, naissance);
    if (ajouter_client(c))
        cout << "Le client a bien été ajouté." << endl;
    else
        cout << "Une erreur s'est produite lors de l'ajout du client." << endl;
}

client& clients::getClient(string numPass)
{
    int pos = existe(numPass);
    if (pos != -1)
        return tabClient[pos];
}

client& clients::get_ieme_client(int i)
{
    return tabClient[i];
}