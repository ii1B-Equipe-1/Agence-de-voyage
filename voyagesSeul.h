#ifndef voyageSeulS_H
#define voyageSeulS_H

#include "voyageSeul.h"
#include <vector>
using namespace std;

class voyagesSeul
{
    private:
        vector<voyageSeul> tabVoyageSeul;
    public:
        voyagesSeul();
        ~voyagesSeul();
        int existe(string);
        bool ajouter_voyageSeul(voyageSeul);
        void afficher_voyagesSeul(clients&);
};

#endif 