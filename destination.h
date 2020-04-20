#ifndef DESTINATION_H
#define DESTINATION_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Destination
{
    private:
        string Pays;
        string Ville;
    public:
        Destination();
        Destination(const string&, const string&); //constructeur
        ~Destination();
        string getPays();
        string getVille();
        void setPays(const string&);
        void setVille(const string&);
        bool operator==(const Destination&);
        friend ostream& operator<<(ostream&, const Destination&);
};


#endif