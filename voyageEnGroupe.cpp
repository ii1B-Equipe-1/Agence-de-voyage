#include "voyageEnGroupe.h"
using namespace std;

voyageEnGroupe::voyageEnGroupe(const string& id, Destination dest, Date dep, Date ret)
:voyage(id,dest,dep,ret){}
voyageEnGroupe::~voyageEnGroupe(){};
int voyageEnGroupe::est_paticipant(string numPass)
{
    for (int i=0; i<participants.size(); i++)
        if (participants[i] == numPass)
            return i;
    return -1;
}

vector<string> voyageEnGroupe::getParticipants()
{
    return participants;
}

bool voyageEnGroupe::ajouter_participant(string numPass)
{
    if (participants.size() == 15)
        return false;
    else
    {
        participants.push_back(numPass);
        return true;
    }
    
}

void voyageEnGroupe::afficher_groupe()
{
        cout << "   -Destination :    " << Dest ;
        cout << "   -Date de depart : " << dateDepart ;
        cout << "   -Date de retour : " << dateRetour ;
        cout << "   -Le nombre de voyageurs actuel : " << participants.size()<< endl;
}

int voyageEnGroupe::nb_participants()
{
    return participants.size();
}