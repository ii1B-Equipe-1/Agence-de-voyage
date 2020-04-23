#include "gestionAgence.h"
using namespace std;

/***************************GESTION DES DESTINATIONS ******************/
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

Destination choisir_destination(Destinations& tabDestination)
{
    cout << endl;
    cout << " Les desstinations disponibles :  "<< endl << endl;
    cout << tabDestination << endl;
    cout << "Choisir une destination :" << endl << endl;
    string pays;
    string ville;
    Destination dest;
    do
    {
        cout << " Donner le pays ---> ";
        cin >> pays;
        cout << " Donner la vile ---> ";
        cin >> ville;
        dest.setPays(pays);
        dest.setVille(ville);
        if (tabDestination.existe(dest) == -1)
            cout << endl << "   Choix invalide, réessayez "<< endl << endl;
    } while (tabDestination.existe(dest) == -1);
    cout << endl << "La destination " << dest << " a été choisie." << endl << endl;
    return dest;
}

/******************** GESTIONS DES GROUPES *******************************/
void menu_gestion_groupe()
{
    cout << endl;
    cout << "   1- Afficher tous les groupes" << endl;
    cout << "   2- Afficher tous les groupes pour une destination donnée" << endl;
    cout << "   3- Créer un nouveau groupe " << endl;
    cout << "   4- Retour" << endl << endl;
}

void saisir_voyage_en_groupe(voyagesEnGroupe& tabVoyGroupe, Destinations& tabDest)
{
    string idVoy = generer_id_voyage_groupe(tabVoyGroupe);
    Destination dest = choisir_destination(tabDest);
    Date dep = saisir_date_depart();
    Date ret = saisir_date_retour(dep);
    voyageEnGroupe voy (idVoy, dest, dep, ret);
    tabVoyGroupe.ajouter_voyageEnGroupe(voy);
    cout << endl << " Le groupe suivant a bien été ajouté : "<< endl;
    voy.afficher_voyage();
    cout << endl;
}

void gerer_groupes(voyagesEnGroupe& tabVoyGroupe, Destinations& tabDest)
{
    int choix;
    do
    {
        menu_gestion_groupe();
        cout << "votre choix ---> ";
        cin >> choix;
        if (choix == 1)
        {
            tabVoyGroupe.afficher_groupes();
        }
        if (choix == 2)
        {
            Destination dest = choisir_destination(tabDest);
            tabVoyGroupe.afficher_groupes(dest);
        }
        if (choix == 3)
            saisir_voyage_en_groupe(tabVoyGroupe, tabDest);
    } 
    while  (choix != 4);
    
}




/********************    GESTION DES CLIENTS ******************************/
bool en_groupe(const string& id)
{
    if (id.substr(3) == "000")
        return false;
    return true;
}
string generer_id_voyage_seul(voyagesSeul& tabVoySeul)
{
    srand(time(0));
    string id;
    do
    {
        long x = rand() % 10000 + 89999;
        id = to_string(x);
        id = "000" + id;
    }
    while ( tabVoySeul.existe(id) != -1 );
    return id;
}

string generer_id_voyage_groupe(voyagesEnGroupe& tabVoyGroupe)
{
    srand(time(0));
    string id;
    do
    {
        long x = rand() % 10000 + 89999;
        id = to_string(x);
        int nb = tabVoyGroupe.nb_voyagesEnGroupe() +1;
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
    while ( tabVoyGroupe.existe(id) != -1 );
    return id;
}


int existe(vector<string>& vect, const string& ch)
{
    for (int i=0; i < vect.size(); i++)
        if ( vect[i] == ch )
            return i;
    return -1;
}
string saisir_idVoyage_groupe( vector<string>& dispo)
{
    cout << endl << "Saisir l'id voyage du groupe choisi " << endl;
    string id;
    do
    {
        cin >> id;
        if (existe(dispo, id) == -1)
            cout << "Id incorrect ,réessayez ---> "; 
    }
    while (existe(dispo, id) == -1);
    return id;
}

void voyager_en_groupe(const string& numPass, clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDestinations)
{
    int choix;
    do
    {
        cout << endl << "   1- Afficher tous les groupes disponibles" << endl;
        cout << "   2- Afficher tous les groupes pour une certaine destination" << endl;
        cout << "   3- Retour" << endl << endl;
        cin >> choix;
        if (choix == 1)
        {
            vector<string> dispo = tabVoyGroupe.groupes_disponibles();
            if (dispo.size() != 0)
            {
                string idVoy = saisir_idVoyage_groupe(dispo);
                if (tabVoyGroupe.getVoyage(idVoy).est_paticipant(numPass) != -1)
                    cout << " Le client participe déja à ce voyage en groupe "<< endl << endl;
                else
                {
                    tabVoyGroupe.getVoyage(idVoy).ajouter_participant(numPass);
                    tabClient.getClient(numPass).ajouter_voyage(idVoy);
                    cout << endl << "  L'ajout au groupe a été bien effectué" << endl << endl;
                }
            }
        }
        if (choix == 2)
        {
            Destination dest = choisir_destination( tabDestinations) ;
            vector<string> dispo = tabVoyGroupe.groupes_disponibles(dest);
            if (dispo.size() != 0)
            {
                string idVoy = saisir_idVoyage_groupe(dispo);
                tabVoyGroupe.getVoyage(idVoy).ajouter_participant(numPass);
                tabClient.getClient(numPass).ajouter_voyage(idVoy);
                cout << endl << "  L'ajout au groupe a été bien effectué" << endl << endl;
            }
        }
    } while (choix != 3);    
}

void nouveau_voyage(const string& numPass, clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDestinations)
{
    int choix;
    do
    {
        cout << endl << "   1- Voyager seul" << endl;
        cout << "   2- Voyager en groupe" <<endl;
        cout << "   3- Retour" << endl << endl;
        cin >> choix;
        if (choix == 1)
        {
            Destination dest = choisir_destination(tabDestinations);
            Date dep = saisir_date_depart();
            Date ret = saisir_date_retour(dep);
            string idVoy = generer_id_voyage_seul(tabVoySeul);
            voyageSeul voyS (idVoy, numPass, dest, dep, ret);
            tabVoySeul.ajouter_voyageSeul(voyS);// ajout du voyage au tableau des voyages seul
            tabClient.getClient(numPass).ajouter_voyage(idVoy);// ajout de l'id voyage au tableau des voyages du client
            cout << endl <<  "Le voyage à bien été créé " << endl;
        }
        if (choix == 2)
            voyager_en_groupe(numPass, tabClient, tabVoySeul, tabVoyGroupe, tabDestinations);
    } while (choix != 3); 
}

void menu_ancien_client()
{
    cout << endl;
    cout << "   1- Nouveau voyage" << endl;
    cout << "   2- Afficher les voyages à venir" << endl;
    cout << "   3- Afficher tous les voyages" << endl;
    cout << "   4- Retour" << endl << endl; 
}

void afficher_voyages_client(const string& numPass, clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe)
{
    vector<string> voy = tabClient.getClient(numPass).getVoyagesClient();
    for (int i = 0; i < voy.size(); i++)
    {
        string idVoy = voy[i];
        if ( en_groupe(idVoy))
            tabVoyGroupe.getVoyage(idVoy).afficher_voyage();
        else
            tabVoySeul.getVoyage(idVoy).afficher_voyage();
    }
};

void afficher_futur_voyages_client(const string& numPass, clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe)
{
    vector<string> voy = tabClient.getClient(numPass).getVoyagesClient();
    for (int i = 0; i < voy.size(); i++)
    {
        string idVoy = voy[i];
        if ( en_groupe(idVoy))
            if (tabVoyGroupe.getVoyage(idVoy).getDateDepart() > date_systeme())
                tabVoyGroupe.getVoyage(idVoy).afficher_voyage();
        else
            if ( tabVoySeul.getVoyage(idVoy).getDateDepart() > date_systeme())
            tabVoySeul.getVoyage(idVoy).afficher_voyage();
    }
}

void gerer_ancien_client(const string& numPass, clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDestinations)
{
    int choix;
    do
    {
        menu_ancien_client();
        cin >> choix;
        switch (choix)
        {
            case 1:
                nouveau_voyage(numPass, tabClient, tabVoySeul, tabVoyGroupe, tabDestinations);
                break;
            case 2:
                afficher_futur_voyages_client(numPass, tabClient, tabVoySeul, tabVoyGroupe);
                break;
            case 3:
                afficher_voyages_client(numPass, tabClient, tabVoySeul, tabVoyGroupe);
                break;
            case 4:
                break;
            default:
                break;
        }

        } while (choix != 4);
}

void gerer_clients(clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDestinations)
{
    string numPass;
    cout << "  Donner un numéro passeport :" << endl;
    numPass = saisir_numPasseport();
    // si c'est un ancien client :
    if (tabClient.existe(numPass) != -1)
        gerer_ancien_client(numPass, tabClient, tabVoySeul, tabVoyGroupe, tabDestinations);
    
    
    if ( tabClient.existe(numPass) == -1)
    {
        //ajout du nouveau client
        tabClient.saisir_client(numPass);
        //nouveau voyage
        nouveau_voyage(numPass, tabClient, tabVoySeul, tabVoyGroupe, tabDestinations);
        
        //on répéte la meme chose que pour un ancien client
        gerer_ancien_client(numPass, tabClient, tabVoySeul, tabVoyGroupe, tabDestinations);
    }
}