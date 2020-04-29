#include "client.h"
#include "clients.h"
#include "voyage.h"
#include "voyageSeul.h"
#include "voyagesSeul.h"
#include "voyageEnGroupe.h"
#include "voyagesEnGroupe.h"
#include "destination.h"
#include "destinations.h"
#include "date.h"
#include "gestionAgence.h"

#include "fstream"

#include <iostream>
using namespace std;

int main()
{
    //les 4 conteneurs sur lesquelles les modifications auront lieu
    Destinations tabDestinations;
    clients tabClient;
    voyagesSeul tabVoyageSeul;
    voyagesEnGroupe tabVoyageEngroupe;



    //charger les conteneurs à partir des fichiers s'ils existent
    //sinon on crée les fichiers
    tabDestinations.readFile();


    //exécution du programme
    gerer_destinations(tabDestinations);
    //gerer_groupes(tabVoyageEngroupe, tabDestinations, tabClient);
    //gerer_clients(tabClient,tabVoyageSeul,tabVoyageEngroupe,tabDestinations);


    //enregistrer les 4 conteneurs dans les fichiers
    tabDestinations.writeToFile();
}