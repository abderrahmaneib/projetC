//
//  fcts.h
//  recitifications
//
//  Created by IBN SEDDIK Abderrahmane on 27/01/2016.
//  Copyright © 2016 MacBook Pro. All rights reserved.
//

#ifndef fcts_h
#define fcts_h

#include <stdio.h>
//Encadrants
//Etablissements
//Formations
//mises_a_jour
//fichiers



// header des fonctions Encadrants




typedef struct Encadrant Encadrant;
struct Encadrant{
    int code;
    char nom[30];
    int statut;              //le statut actuel du formateur (tuteur ou regional ou national)
    int nbreClasseEtdt;      //nbre de classe detudiants quil a enseigne
    int nbreClasseFacilitateur;
    int nbreClasseNatio;
    int partiesAccomplies;     //combien de parties il a suivi du programme pour facilitateur tuteur
    Encadrant * suivant;
};


typedef struct Liste_encadrant Liste_encadrant;
struct Liste_encadrant{
    Encadrant *premier;
};


Encadrant * creer_encadrant(int  nbre_encadrant);
Encadrant * inserer_encadrant(Encadrant * Pencadrant,Liste_encadrant * liste_encadrant);
Encadrant * rechercher_encadrant(char nom[30],Liste_encadrant liste_encadrant);
Liste_encadrant * creer_liste_encadrants();
void afficher_encadrants(Liste_encadrant * liste_encadrants);
void afficher_nbres_classes_encadrant(char nom[30],Liste_encadrant liste_encadrant);
void afficher_statut_encadrant(char nom[30],Liste_encadrant liste_encadrant);
void afficher_encadrants_statut(int statut,Liste_encadrant liste_encadrant);



// header des fonctions etabs



typedef struct Etablissement Etablissement;
struct Etablissement{
    char nomEtab[30];
    char ville[20];
    char pays[20];
    Etablissement * suivant;
    
};

typedef struct Liste_etabs Liste_etabs;
struct Liste_etabs{
    Etablissement * premier;
};

Etablissement * inserer_etab(Etablissement * etablissement,Liste_etabs * liste_etabs);
void afficher_etabs(Liste_etabs liste_etabs);
Etablissement * creer_etablissement();
Etablissement * rechercher_etab(char nom[30],Liste_etabs liste_etabs);
Liste_etabs * creer_liste_etabs();


//header des fonctions Formations


typedef struct Formation Formation;
struct Formation{
    char matiere[30];
    int nature; // formation pour les etudians ? ou bien facilitateur tuteur ? etc...
    int semestre; // le semestre de la formation
    Encadrant * encadrant;
    Etablissement * etab;
    int nbreEleve;   //le nombre des beneficiaires de la formation
    
    Formation * suivant;
};
typedef struct Liste_formation Liste_formation;
struct Liste_formation {
    Formation * premier;
};


Formation * creer_formation(Liste_encadrant liste_encadrant,Liste_etabs liste_etabs);
Formation * inserer_formation(Liste_formation * liste_formation,Formation * formation);
Liste_formation * creer_liste_formations();
void afficher_formations_etdt(Liste_formation * liste_formation);
void afficher_formations_tuteurs(Liste_formation * liste_formation);
void afficher_formations_nationaux(Liste_formation * liste_formation);



//header des fonctions de mises à jour



Encadrant * update_nbre_classe(Formation * formation);
void update_vers_tuteur(Encadrant * encadrant);
void update_vers_national(Encadrant * encadrant);
void update_vers_regional(Encadrant * encadrant);


//header des fonctions des fichiers



void sauvegarder_liste_encadrants(Liste_encadrant * liste_encadrants);
Liste_encadrant * importer_encadrants();


void sauvegarder_liste_etabs(Liste_etabs *liste_etabs);
Liste_etabs * importer_etab();


void sauvegarder_liste_formations(Liste_formation * Liste_formation);
Liste_formation * importer_formations(Liste_encadrant * liste_encadrant,Liste_etabs * liste_etabs);

void sauvegarder_nbre_encadrant();
int importer_nbre_encadrant();

void nature(int nature);

#endif /* fcts_h */
