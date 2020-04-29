#include "statistiquesAgence.h"
using namespace std;


vector<int> vecteur_unique(vector<int> a,vector<int> b)
{
    vector<int> uniq;
    for(int i=0;i<a.size();i++)
        uniq.push_back(a[i]);
    for(int i=0;i<b.size();i++)
    {
        int f=0;
        for(int j=0;j<uniq.size();j++)
            if(b[i]==uniq[j])
                f=1;
        if(f==0)
            uniq.push_back(b[i]);
    }
    return uniq;
}
int maximale(vector<int> a)
{
    int maxi=a[0];
    for(int i=0;i<a.size();i++)
        if(a[i]>maxi)
            maxi=a[i];
    return maxi;
}
int minimale(vector<int> a)
{
    int mini=a[0];
    for(int i=0;i<a.size();i++)
        if(a[i]<mini)
            mini=a[i];
    return mini;
}
vector<int> nbre_occurence(int a,vector<int> b)
{
    vector<int> occurence;
    for(int i=0;i<b.size();i++)
        if(b[i]==a)
            occurence.push_back(i);
    return occurence;
}
void mois_correspondant(int i)
{
    switch (i)
    {
        case 0:cout<<"janvier ";break;
        case 1:cout<<"fevrier ";break;
        case 2:cout<<"mars ";break;
        case 3:cout<<"avril ";break;
        case 4:cout<<"mai ";break;
        case 5:cout<<"juin ";break;
        case 6:cout<<"juillet ";break;
        case 7:cout<<"aout ";break;
        case 8:cout<<"septembre ";break;
        case 9:cout<<"octobre ";break;
        case 10:cout<<"novembre ";break;
        case 11:cout<<"decembre ";break;
    }
}
void la_periode_la_plus_demandee_par_annee(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul)
{
    vector<int> ans_grps;
    vector<int> ans_seuls;
    ans_grps=voy_en_grps.liste_des_annees();
    ans_seuls=voy_seul.liste_des_annees();
    vector<int> tout_annee;
    tout_annee=vecteur_unique(ans_grps,ans_seuls);
    for(int i=0;i<tout_annee.size();i++)
    {
        cout<<"Pour l'annee "<<tout_annee[i]<<" : "<<endl;//pour chaque ans
        vector<int> mois;
        vector<int> mois1;
        mois=voy_seul.nbre_desvoyages_seules_chaquemois(tout_annee[i]);
        mois1=voy_en_grps.nbre_desvoyages_engroupes_chaquemois(tout_annee[i]);
        vector<int> mois2;
        for(int j=0;j<mois.size();j++)
            mois2.push_back(mois1[j]+mois[j]);
        int nbre_des_voyages_maximales=maximale(mois2);
        vector<int> occurence=nbre_occurence(nbre_des_voyages_maximales,mois2);
        if(occurence.size()==1)
        {
            cout<<"On a effectue un nombre de voyages maximale est egale a "<<nbre_des_voyages_maximales<<"durant le mois de ";
            mois_correspondant(occurence[0]);
            cout<<endl;
        }

        else
        {
            cout<<"On a effectue un nombre de voyages maximale est egale a "<<nbre_des_voyages_maximales<<"durant les mois de ";
            for(int k=0;k<occurence.size();k++)
                mois_correspondant(occurence[k]);
            cout<<endl;
        }
    }
}
void la_periode_la_moins_demandee_par_annee(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul)
{
    vector<int> ans_grps;
    vector<int> ans_seuls;
    ans_grps=voy_en_grps.liste_des_annees();
    ans_seuls=voy_seul.liste_des_annees();
    vector<int> tout_annee;
    tout_annee=vecteur_unique(ans_grps,ans_seuls);
    for(int i=0;i<tout_annee.size();i++)
    {
        cout<<"Pour l'annee "<<tout_annee[i]<<" : "<<endl;
        vector<int> mois;
        vector<int> mois1;
        mois=voy_seul.nbre_desvoyages_seules_chaquemois(tout_annee[i]);
        mois1=voy_en_grps.nbre_desvoyages_engroupes_chaquemois(tout_annee[i]);
        vector<int> mois2;
        for(int j=0;j<mois.size();j++)
            mois2.push_back(mois1[j]+mois[j]);
        int nbre_des_voyages_minimales=minimale(mois2);
        vector<int> occurence=nbre_occurence(nbre_des_voyages_minimales,mois2);
        if(occurence.size()==1)
        {
            cout<<"On a effectue un nombre de voyages minimale est egale a "<<nbre_des_voyages_minimales<<"durant le mois de ";
            mois_correspondant(occurence[0]);
            cout<<endl;
        }

        else
        {
            cout<<"On a effectue un nombre de voyages minimale est egale a "<<nbre_des_voyages_minimales<<"durant les mois de ";
            for(int k=0;k<occurence.size();k++)
                mois_correspondant(occurence[k]);
            cout<<endl;
        }
    }
}
void afficher_lesvoyages_chaque_saison(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul)
{
    vector<int> ans_grps;
    vector<int> ans_seuls;
    ans_grps=voy_en_grps.liste_des_annees();
    ans_seuls=voy_seul.liste_des_annees();
    vector<int> tout_annee;
    tout_annee=vecteur_unique(ans_grps,ans_seuls);
    for(int i=0;i<tout_annee.size();i++)
    {
        cout<<"Pour l'annee "<<tout_annee[i]<<" : "<<endl;
        vector<int> saison=voy_en_grps.nbre_desvoyages_engroupes_chaquesaison(tout_annee[i]);
        vector<int> saison1=voy_seul.nbre_desvoyages_seules_chaquesaison(tout_annee[i]);
        vector<int> saison2;
        for(int i=0;i<saison.size();i++)
            saison2.push_back(saison1[i]+saison[i]);
        cout<<"le nombre des voyages effectue  pour la saison d'hiver de cette annee est egale a"<<saison2[0]<<endl;
        cout<<"le nombre des voyages effectue  pour la saison de printemps de cette annee est egale a"<<saison2[1]<<endl;
        cout<<"le nombre des voyages effectue  pour la saison d'ete de cette annee est egale a"<<saison2[2]<<endl;
        cout<<"le nombre des voyages effectue  pour la saison d'automne de cette annee est egale a"<<saison2[3]<<endl;
    }
}
void afficher_lesvoyages_seuls_chaque_saison(voyagesSeul& voy_seul)//les voyages seules seulements
{
    vector<int> ans_seuls;
    ans_seuls=voy_seul.liste_des_annees();
    for(int i=0;i<ans_seuls.size();i++)
    {
        cout<<"Pour l'annee "<<ans_seuls[i]<<" : "<<endl;
        vector<int> saison1=voy_seul.nbre_desvoyages_seules_chaquesaison(ans_seuls[i]);
        cout<<"le nombre des voyages seuls effectue  pour la saison d'hiver de cette annee est egale a"<<saison1[0]<<endl;
        cout<<"le nombre des voyages seuls effectue  pour la saison de printemps de cette annee est egale a"<<saison1[1]<<endl;
        cout<<"le nombre des voyages seuls effectue  pour la saison d'ete de cette annee est egale a"<<saison1[2]<<endl;
        cout<<"le nombre des voyages seuls effectue  pour la saison d'automne de cette annee est egale a"<<saison1[3]<<endl;
    }
}
void afficher_lesvoyagesengroupes_chaque_saison(voyagesEnGroupe& voy_en_grps)
{
    vector<int> ans_grps;
    ans_grps=voy_en_grps.liste_des_annees();
    for(int i=0;i<ans_grps.size();i++)
    {
        cout<<"Pour l'annee "<<ans_grps[i]<<" : "<<endl;
        vector<int> saison=voy_en_grps.nbre_desvoyages_engroupes_chaquesaison(ans_grps[i]);
        cout<<"le nombre des voyages en groupes effectue  pour la saison d'hiver de cette annee est egale a"<<saison[0]<<endl;
        cout<<"le nombre des voyages en groupes effectue  pour la saison de printemps de cette annee est egale a"<<saison[1]<<endl;
        cout<<"le nombre des voyages en groupes effectue  pour la saison d'ete de cette annee est egale a"<<saison[2]<<endl;
        cout<<"le nombre des voyages en groupes effectue  pour la saison d'automne de cette annee est egale a"<<saison[3]<<endl;
    }
}
void afficher_lemoyen_annuel_des_voyages(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul)
{
    vector<int> ans_grps;
    vector<int> ans_seuls;
    ans_grps=voy_en_grps.liste_des_annees();
    ans_seuls=voy_seul.liste_des_annees();
    vector<int> tout_annee;
    tout_annee=vecteur_unique(ans_grps,ans_seuls);
    int nbre_des_voyages;
    nbre_des_voyages=voy_en_grps.nb_voyagesEnGroupe()+voy_seul.nb_voyagesSeul();
    float moyen=(nbre_des_voyages/(tout_annee.size()));
    cout<<" Le nombre moyen des voyages annuels est egale a : "<<moyen<<endl;
}
void afficher_lemoyen_annuel_des_voyages_engroupes(voyagesEnGroupe& voy_en_grps)
{
    vector<int> ans_grps;
    ans_grps=voy_en_grps.liste_des_annees();
    int nbre_des_voyages;
    nbre_des_voyages=voy_en_grps.nb_voyagesEnGroupe();
    float moyen=(nbre_des_voyages/(ans_grps.size()));
    cout<<" Le nombre moyen des voyages en groupes annuels est egale a : "<<moyen<<endl;
}
void afficher_lemoyen_annuel_des_voyages_seuls(voyagesSeul& voy_seul)
{
    vector<int> ans_seuls;
    ans_seuls=voy_seul.liste_des_annees();
    int nbre_des_voyages;
    nbre_des_voyages=voy_seul.nb_voyagesSeul();
    float moyen=(nbre_des_voyages/(ans_seuls.size()));
    cout<<" Le nombre moyen des voyages seuls annuels est egale a : "<<moyen<<endl;
}
int somme_tableau(vector<int> a)
{
    int s=0;
    for(int i=0;i<a.size();i++)
        s+=a[i];
    return s;
}
void afficher_lemoyen_mensuel_des_voyages(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul)
{
    vector<int> ans_grps;
    vector<int> ans_seuls;
    ans_grps=voy_en_grps.liste_des_annees();
    ans_seuls=voy_seul.liste_des_annees();
    vector<int> tout_annee;
    tout_annee=vecteur_unique(ans_grps,ans_seuls);
    for(int i=0;i<tout_annee.size();i++)
    {
        vector<int> saison=voy_en_grps.nbre_desvoyages_engroupes_chaquesaison(tout_annee[i]);
        vector<int> saison1=voy_seul.nbre_desvoyages_seules_chaquesaison(tout_annee[i]);
        vector<int> saison2;
        for(int i=0;i<saison.size();i++)
            saison2.push_back(saison1[i]+saison[i]);
        int somme=somme_tableau(saison2);
        float moyen_mensuel;
        moyen_mensuel=somme/12;
        cout<<"Pour l'annee "<<tout_annee[i]<<" le nombre moyen des voyages mensuels est egale a : "<<moyen_mensuel;
    }
}
void afficher_lemoyen_mensuel_des_voyages_engroupes(voyagesEnGroupe& voy_en_grps)
{
    vector<int> ans_grps;
    ans_grps=voy_en_grps.liste_des_annees();
    for(int i=0;i<ans_grps.size();i++)
    {
        vector<int> saison=voy_en_grps.nbre_desvoyages_engroupes_chaquesaison(ans_grps[i]);
        int somme=somme_tableau(saison);
        float moyen_mensuel;
        moyen_mensuel=somme/12;
        cout<<"Pour l'annee "<<ans_grps[i]<<" le nombre moyen des voyages en groupes mensuels est egale a : "<<moyen_mensuel;
    }
}
void afficher_lemoyen_mensuel_des_voyages_seuls(voyagesSeul& voy_seul)
{
    vector<int> ans_seuls;
    ans_seuls=voy_seul.liste_des_annees();
    for(int i=0;i<ans_seuls.size();i++)
    {
        vector<int> saison1=voy_seul.nbre_desvoyages_seules_chaquesaison(ans_seuls[i]);
        int somme=somme_tableau(saison1);
        float moyen_mensuel;
        moyen_mensuel=somme/12;
        cout<<"Pour l'annee "<<ans_seuls[i]<<" le nombre moyen des voyages seuls mensuels est egale a : "<<moyen_mensuel;
    }
}
