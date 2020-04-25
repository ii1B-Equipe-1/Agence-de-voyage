#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

//La classe date
class Date
{
    private:
        int Jour;
        int Mois;
        int Annee;
    public:
        Date();
        Date(int,int,int);
        ~Date();
        int getJour();
        int getMois();
        int getAnnee();
        void setDate(const int&,const int&,const int&);
        int date_cmp(const Date& d);     //retourne 1 si *this>d, 0 si *this = d et -1 sinon
        bool operator<(const Date& d);   // 
        bool operator>(const Date& d);   //    opérateurs de comparaisons des dates
        bool operator==(const Date& d);  //
        void retarder_date(); //change la date à partir du clavier
        friend ostream& operator<<(ostream&, const Date&); //affichage sous la forme "jj/mm/aaaa"
};



//Fonctions sur les dates
Date date_systeme();        //retourne la date systeme
bool date_valide(int,int,int); //vérifie si les valeur de jour, mois et année sont valides
bool est_numerique(const string&); //vérifie si une chaine est numérique
bool format_date(const string&); // vérifie si une chaine est de la forma jj/mm/aaaa
Date saisir_date();     //saisir une datee à partir du clavier
bool est_dateNaissance(Date); //vérifie que la date de naissance est dans le passé (càd < date systeme)

Date saisir_date_depart();
Date saisir_date_retour(Date); //date de retour > date de départ
bool annee_bissextile(int);
int difference_date(Date, Date); //calcule la durée en jours entre deux dates
#endif