#include "menuPrincipal.h"
using namespace std;

void menu_principal(clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDest)
{
    int choix;
    do
    {
        cout<<"BIENVENUE CHEZ NOTRE AGENCE DE VOYAGE"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<" 1/GESTION AGENCE:"<<endl;
        cout<<" 2/AFFICHER LES STATISTIQUES:"<<endl;
        cout<<" 3/QUITTER"<<endl<<endl;
        cout<<"VOTRE CHOIX ---> ";
        cin >> choix;
        switch(choix)
        {
            case 1 :
                gerer_agence(tabClient, tabVoySeul, tabVoyGroupe, tabDest);
            break;
            case 2 :
                afficher_statistiques(tabClient, tabVoySeul, tabVoyGroupe, tabDest);
            break;
            case 3 :
                break;
            default :
                cout<<"MAUVAIS CHOIX VEUILLEZ SAISIR DE NOUVEAU LE NUMERO";
        }
    }while(choix!=3);
}


void gerer_agence(clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDest)
{
    int choix;
    do
    {
        cout << endl << endl;
        cout<<"GESTION AGENCE: "<<endl;
        cout<<"----------------"<<endl;
        cout<<" 1/GERER LES DESTINATIONS:"<<endl;
        cout<<" 2/GERER LES GROUPES:"<<endl;
        cout<<" 3/ESPACE CLIENT:"<<endl;
        cout<<" 4/AFFICHER TOUS LES VOYAGES DE L'AGENCE"<<endl;
        cout<<" 5/RETARDER TOUS LES VOYAGES POUR UNE DATE DONNÉE " << endl;
        cout<<" 6/DONNER LA LISTE DES VOYAGES PAR PAYS:"<<endl;
        cout<<" 7/TIRAGE QU SORT POUR UN CLIENT GAGNANT:"<<endl;
        cout<<" 8/RETOUR"<<endl<<endl;
        cout<<"VOTRE CHOIX :";
        cin>>choix;
        switch(choix)
        {
            case 1 :
                gerer_destinations(tabDest);
            break;
            case 2 :
                gerer_groupes(tabVoyGroupe, tabDest, tabClient);
            break;
            case 3 :
                gerer_clients(tabClient, tabVoySeul, tabVoyGroupe,tabDest);
            break;
            case 4 :
                afficher_tous_les_voyages(tabVoySeul, tabVoyGroupe, tabClient);
            break;
            case 5 :
                retarder_tous_les_voyages(tabVoySeul, tabVoyGroupe);
            break;
            case 6 :
                liste_voyages_pays(tabVoySeul, tabVoyGroupe, tabDest);
            break;
            case 7 :
                client_gagnant(tabVoySeul, tabVoyGroupe,tabClient, tabDest);
            break;
            case 8 :
                break;
            default :
                cout<<"MAUVAIS CHOIX VEUILLEZ SAISIR DE NOUVEAU LE NUMERO";

        }
    }while(choix!=8);
}


void afficher_statistiques(clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDest)
{
    int choix;

    do
    {
        cout<<"AFFICHER LES STATISTIQUES:"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<" 1/AFFICHER LE NOMBRE TOTAL DE VOYAGE EFFECTUE PAR L'AGENCE DEPUIS SA CREATION:"<<endl;
        cout<<" 2/AFFICHER LE NOMBRE MOYEN DES VOYAGES ANNUELS:"<<endl;
        cout<<" 3/AFFICHER CONSECUTIVEMENT LE NOMBRE DE VOYAGES EFFECTUES PENDANT CHAQUE SAISON DANS UNE ANNEE:"<<endl;
        cout<<" 4/AFFICHER LA PERIODE DU TEMPS DURANT LAQUELLE L'AGENCE A LE PLUS DE DEMANDES:"<<endl;
        cout<<" 5/AFFICHER LA PERIODE DU TEMPS DURANT LAQUELLE L'AGENCE A LE MOINS DE DEMANDES:"<<endl;
        cout<<" 6/AFFICER LE NOMBRE DES CLIENTS DISTINCTS DE L'AGENCE DEPUIS SA CREATION:"<<endl;
        cout<<" 7/AFFICHER LA TRANCHE D'AGES LA PLUS FREQUENTE DE LA CLIENTELE:"<<endl;
        cout<<"8/QUITTER"<<endl<<endl;
        cout<<"VOTRE CHOIX :";
        cin>>choix;
        switch(choix)
        {
            case 1 :
            break;
            case 2 :
            break;
            case 3 :
            break;
            case 4 :
            break;
            case 5 :
            break;
            case 6 :
            break;
            case 7 :
            break;
            case 8 :
            break;
            default :
                cout<<"MAUVAIS CHOIX VEUILLEZ SAISIR DE NOUVEAU LE NUMERO";
        }
    }while(choix!=8);
}