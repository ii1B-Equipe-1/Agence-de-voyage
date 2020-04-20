#include "voyageSeul.h"
using namespace std;

voyageSeul::voyageSeul(){};
voyageSeul::voyageSeul(const string& id,const string& numPass, Destination d, Date dep, Date ret)
:voyage(id, d, dep, ret)
{
    //idVoyage = id;
    numPasseport = numPass;
    //Dest = d;
    //dateDepart = dep;
    //dateRetour = ret;
}


string voyageSeul::getNumPasseport()
{
    return numPasseport;
}


void voyageSeul::afficher_voyage(clients& c )
{
    cout << c.getClient(numPasseport);
    voyage::afficher_voyage();
}