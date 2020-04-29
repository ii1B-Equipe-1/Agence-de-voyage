#include "date.h"
using namespace std;


/**** Les méthodes de la classes Date ****/
Date::Date(){};
Date::Date(int j, int m, int a)
{  
    Jour =j;
    Mois = m;
    Annee = a;
}

Date::~Date(){}

int Date::getJour()
{
    return Jour;
}

int Date::getMois()
{
    return Mois;
}

int Date::getAnnee()
{
    return Annee;
}

void Date::setDate(const int& j, const int& m, const int& a)
{
    Jour = j;
    Mois = m;
    Annee = a;
}

int Date::date_cmp(const Date& d)
{
    if (Annee > d.Annee)
        return 1;
    else if (Annee < d.Annee)
        return -1;
    else
        if (Mois > d.Mois)
            return 1;
        else if (Mois < d.Mois)
            return -1;
        else
            if (Jour > d.Jour)
                return 1;
            else if (Jour < d.Jour)
                return -1;
            else
                return 0;
}

bool Date::operator<(const Date& d)
{
    if (date_cmp(d) == -1)
        return true;
    return false;
}

bool Date::operator>(const Date& d)
{
    if (date_cmp(d) == 1)
        return true;
    return false;
}

bool Date::operator==(const Date& d)
{
    if (date_cmp(d) == 0)
        return true;
    return false;
}

void Date::retarder_date()
{
    cout << "La date actuelle :  "<< *this;
    cout << "--->  Donner la nouvelle date :  ";
    Date d;
    do
    {
        d = saisir_date();
        if ((d < *this) || (d == *this))
            cout << "Cette date n'est pas valide, réessayez :  ";
    }
    while ((d < *this) || (d == *this));
    *this = d;
}

ostream& Date::write(ostream& out)
{
    out << Jour << " " << Mois << " " << Annee;
    return out;
}

istream& Date::read(istream& in)
{
    in >> Jour >> Mois >> Annee;
    return in;
}






/*****************************************************************/
bool Date::Dans_printemps()
{
    if((Mois>=3)&&(Mois<=5))
        return true;
    else
        return false;
}
bool Date::Dans_automne()
{
    if((Mois>=9)&&(Mois<=11))
        return true;
    else
        return false;
}
bool Date::Dans_ete()
{
    if((Mois>=6)&&(Mois<=8))
        return true;
    else
        return false;
}
bool Date::Dans_hiver()
{
    if((Mois==12)||(Mois==1)||(Mois==2))
        return true;
    else
        return false;
}








//fonction amie de la classe Date
ostream& operator<<(ostream& output, const Date& d)
{
    if (d.Jour<10)
        output << "0" << d.Jour ;
    else
        output << d.Jour ;
    output << "/" ;

    if (d.Mois<10)
        output << "0" << d.Mois ;
    else
        output << d.Mois ;
    output << "/" << d.Annee << endl ;
    return output ; 
}





/**** Fonctions  ****/
Date date_systeme()
{
    //temps courant basé sur le temps systeme
    time_t tempsCourant = time(0);

    /* la structure tm contient la date est le temps sous forme
       de structure C                                        */                       
    tm* temps = localtime(&tempsCourant);
    
    /* on extrait les variables de la structure tm et on les affecte
       à des entiers */
    int j = temps->tm_mday;
    int m = 1 + temps->tm_mon;
    int a = 1900 + temps->tm_year;

    Date dateCourante(j,m,a);
    return dateCourante;
}

bool date_valide(int j, int m, int a)
{
    /*if ((a < date_systeme().getAnnee() - 100) || ( a > date_systeme().getAnnee() + 5 ))
        return false;*/
    switch (m)
    {
    //les mois ayant 31 jours
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: 
        if ((j>31)||(j<1))
            return false;
        break;
    //le mois de Fevrier
    case 2:
        if ((j==29) && (a%4 != 0))
            return false;
        else if((j==29) && (a%4 == 0))
            break;
        else if ((j>28) || (j<1))
            return false;
        break;
    // les mois ayant 30 jours
    case 4:
    case 6:
    case 9:
    case 11:
        if ((j>30) || (j<1))
            return false;
        break; 
    default:
        return false;
        break;
    }
    return true;
}

//utilisée aussi pour vérifier le numPasseport
bool est_numerique(const string& s)
{
    for (int i=0; i < s.length(); i++)
        if (!isdigit(s[i]))
            return false;
    return true;
}
bool format_date(const string& d)
{
    if (d.length() != 10)
        return false;    
    if ((d[2] != '/') || d[5] != '/')
        return false;
    if (!est_numerique( d.substr(0,2)))
        return false;
    if (!est_numerique( d.substr(3,2)))
        return false;
    if (!est_numerique( d.substr(6,4)))
        return false;
    return true;
}

Date saisir_date()
{
    string d;
    int j, m, a;
    do
    {
        cin >> d;
        if (!format_date(d))
            cout << "Veuilliez respecter le format jj/mm/aaaa :  ";
        else
        {
            j = stoi(d.substr(0,2));
            m = stoi(d.substr(3,2));
            a = stoi(d.substr (6));
            if (!date_valide(j,m,a))
                cout << "Date invalide ! Réessayez :  "; 
        }
    } while ((!date_valide(j,m,a)) || !format_date(d));
    Date date(j, m, a);
    return date;
}

bool est_dateNaissance(Date d)
{
    if  (( d < date_systeme()) && (d.getAnnee() > date_systeme().getAnnee() - 150 ))
        return true;
    else
        return false;    
}

Date saisir_date_depart()
{
    cout << "--->  Donner la date de départ :  ";
    Date dep;
    do
    {
        dep = saisir_date();
        if (dep < date_systeme())
            cout << "La date fournie est invalide, réessayez : ";
    }
    while (dep < date_systeme());  
    
    return dep;  
}


Date saisir_date_retour(Date dep)
{
    cout << " Donner la date de retour ( la durée minimale du voyage est de 7 jours ) :  " << endl;
    cout << "   --->  ";
    Date retour;
    do
    {
        retour = saisir_date();
        if (difference_date(dep,retour) < 7)
        {
            cout << "La date fournie est invalide, réessayez : " << endl;
            cout << "   --->  ";
        }
    } 
    while (difference_date(dep,retour) < 7);  
    return retour;  
}

bool annee_bissextile (int annee)
{
    if (( annee % 4 == 0) && ((annee % 100 != 0) || ( annee % 400 ==0)))
        return true;
    return false;
}

int difference_date(Date d1, Date d2)
{
    int j1 = d1.getJour();
    int m1 = d1.getMois();
    int a1 = d1.getAnnee();

    int j2 = d2.getJour();
    int m2 = d2.getMois();
    int a2 = d2.getAnnee();
    
    int cumJours[] = {0,31,59,90,120,151,181,212,243,273,304,334};
    int cumJoursBissextile[] = {0,31,60,91,121,152,182,213,244,274,305,335};
    int nbJours = 0;
    if (d1.getAnnee() == d2.getAnnee())
        if (annee_bissextile(d1.getAnnee()))
            return abs((cumJoursBissextile[m2-1]+j2 - (cumJoursBissextile[m1-1]+j1)));
        else
            return abs((cumJours[m2-1]+j2) - (cumJours[m1-1]+j1));     
    if (annee_bissextile(a1))
        nbJours += 366 - (cumJoursBissextile[m1]+j1);
    else
        nbJours += 365 - (cumJours[m1]+j1);

    int annee = a1 +1;
    while (annee < a2)
    {
        if (annee_bissextile(annee))
            nbJours += 366;
        else
            nbJours += 365;
        annee++;       
    }
    if (annee_bissextile(a2))
        nbJours += cumJoursBissextile[m2-1] + j2;
    else
        nbJours += cumJours[m2-1] + j2;
    return abs(nbJours);
}