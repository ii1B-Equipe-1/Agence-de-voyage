#include "client.h"
using namespace std;

/**** méthodes de la classe client ****/
client::client(const string& numP, const string& n, const string& pren, Date dateN)
{
    numPasseport = numP ;
    Nom = n ;
    Prenom = pren ;
    DateNaissance = dateN;
}

client::client(){};

client::~client(){};

string client::getNumPasseport()
{
    return numPasseport;
}

string client::getNom()
{
    return Nom;
}

string client::getPrenom()
{
    return Prenom;
}

Date client::getDateNaissance()
{
    return DateNaissance;
}

int client::participe_au_voyage(string idVoy)
{
    for (int i=0; i < VoyagesClient.size(); i++)
        if ( VoyagesClient[i] == idVoy )
            return i;
    return -1;
}
bool client::ajouter_voyage(string idVoy)
{
    if (!participe_au_voyage(idVoy))
        VoyagesClient.push_back(idVoy);
}

ostream& operator<<(ostream& output, const client& c)
{
    output << "   * " << c.Prenom << " " << c.Nom << endl;
    output << "   * Passeport: " << c.numPasseport << endl;
    output << "   * Date de naissance: " << c.DateNaissance << endl;
}

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


/**** autres fonctions ****/
bool est_majus(const string& s)
{
    for (int i=0; i < s.length(); i++)
        if (!isupper(s[i]))
            return false;
    return true;
}
bool est_numPasseport(const string& s) // à vérifier le format correcte du numPass .....
{
    // 3 lettres majuscules + 5 chiffres
    if (s.length() != 8)
        return false;
    if (!est_majus(s.substr(0,3)))
        return false;
    if (!est_numerique(s.substr(3)))
        return false;
    return true;
}
string saisir_numPasseport()
{
    string numPass;
    cout <<"--->  Donner le numéro de passeport  : ";
    do
    {
        cin >> numPass;
        if (!est_numPasseport(numPass))
            cout << "Le numéro que vous avez entré n'est pas conforme au format demandé ! Réessayez :  ";
    } while (!est_numPasseport(numPass));
    return numPass;
}