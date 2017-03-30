//
//  fcts.c
//  recitifications
//
//  Created by IBN SEDDIK Abderrahmane on 27/01/2016.
//  Copyright © 2016 MacBook Pro. All rights reserved.
//

#include "fcts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//Declaration des fonctions des Encadrants


Encadrant * creer_encadrant(int  nbre_encadrant){
    Encadrant * Pencadrant=malloc(sizeof(Encadrant));
    Pencadrant->code=nbre_encadrant;
    
    printf("Entrer le nom de l'encadrant que vous souhaitez ajouter\n\t");
    scanf("%s",Pencadrant->nom);
    
    printf("Combien de parties du programme a t'il accompli :0 ou 1 ou 2 ou bien les 3 ?\n\t");
    int nbredeparties=0;
    scanf("%d",&nbredeparties);
    Pencadrant->partiesAccomplies=nbredeparties;
    if (nbredeparties<3){Pencadrant->statut=0;}
    else {Pencadrant->statut=1;}
    Pencadrant->nbreClasseEtdt=0;
    Pencadrant->nbreClasseFacilitateur=0;
    Pencadrant->nbreClasseNatio=0;
    Pencadrant->suivant=NULL;
    return Pencadrant;
}

Encadrant * inserer_encadrant(Encadrant * Pencadrant,Liste_encadrant * liste_encadrant){
    if (liste_encadrant->premier==NULL){liste_encadrant->premier=Pencadrant;}
    else {
        Encadrant * recherche=liste_encadrant->premier;
        while (recherche->suivant != NULL){
            recherche=recherche->suivant;
        }
        Pencadrant->suivant=NULL;
        recherche->suivant=Pencadrant;
        
    }
    return liste_encadrant->premier;
}

Encadrant * rechercher_encadrant(char nom[30],Liste_encadrant liste_encadrant){
    Encadrant * recherche=liste_encadrant.premier;
    while (recherche != NULL && strcmp(recherche->nom, nom) != 0){
        recherche=recherche->suivant;
    }
    return recherche;
}

/*
 
 Encadrant * recherche=liste_encadrant.premier;
 while (recherche != NULL && strcmp(recherche->nom, nom) != 0){
 recherche=recherche->suivant;
 }
 return recherche;
 
 */

Liste_encadrant * creer_liste_encadrants(){
    Liste_encadrant * liste_encadrant=malloc(sizeof(Liste_encadrant));
    liste_encadrant->premier=NULL;
    return liste_encadrant;
    
}



void afficher_encadrants(Liste_encadrant * liste_encadrants){
    Encadrant * encadrant=liste_encadrants->premier;
    while (encadrant != NULL)
    {
        printf("\n \t %s \t",encadrant->nom);
        encadrant=encadrant->suivant;
        
    }
}


void afficher_nbres_classes_encadrant(char nom[30],Liste_encadrant liste_encadrant){
    Encadrant *encadrant=rechercher_encadrant(nom,liste_encadrant);
    if (encadrant==NULL){
        printf("\nL'encadrant que vous cherchez ne figure pas dans la base de donnee, pensez a l'ajouter\n");
    }
    else {
        printf("\t\t\t classes etudiants \t\t classes facilitateurs \t\t classes facilitateurs nationaux\n ");
        printf("%s \t\t %d \t\t %d \t\t %d",nom,encadrant->nbreClasseEtdt,encadrant->nbreClasseFacilitateur,encadrant->nbreClasseNatio);}
    
}


void afficher_statut_encadrant(char nom[30],Liste_encadrant liste_encadrant){
    Encadrant * encadrant=rechercher_encadrant(nom,liste_encadrant);
    if (encadrant==NULL) printf("\n L'encadrant que vous cherchez ne figure pas dans la base donnee, pensez a l'ajouter");
    else {
        int statut=encadrant->statut;
        switch (statut) {
            case (0):
                printf("Le statut de %s est formateur normal",nom);
                break;
            case (1):
                printf("Le statut de %s est facilitateur tuteur",nom);
                break;
            case (2):
                printf("Le statut de %s est facilitateur national",nom);
                break;
            case  (3):
                printf("Le statut de %s est facilitateur regional",nom);
                break;
            default:
                break;
        }
        
    }
}

void afficher_encadrants_statut(int statut,Liste_encadrant liste_encadrant){
    Encadrant * encadrant=liste_encadrant.premier;
    for (encadrant=liste_encadrant.premier;encadrant != NULL;encadrant=encadrant->suivant)
    {
        if (encadrant->statut == statut)
        {printf ("\n %s \n",encadrant->nom );}
    }
}






// Declaration des fonctions d'ajout d'etablissement








Etablissement * inserer_etab(Etablissement * etablissement,Liste_etabs * liste_etabs){
    Etablissement * recherche=liste_etabs->premier;
    if(recherche == NULL) liste_etabs->premier=etablissement;
    else{
        while (recherche->suivant != NULL){
            recherche=recherche->suivant;
        }
        etablissement->suivant=NULL;
        recherche->suivant=etablissement;
        
    }
    return etablissement;
}




void afficher_etabs(Liste_etabs liste_etabs){
    Etablissement * recherche=liste_etabs.premier;
    printf("\nNom \t\tPays\t\tVille\n");
    while(recherche!=NULL){
        printf("%s\t\t%s\t\t%s \n",recherche->nomEtab,recherche->pays,recherche->ville);
        recherche=recherche->suivant;
    }
    
}

Etablissement * creer_etablissement(){
    Etablissement * etab;
    etab=malloc(sizeof(Etablissement));
    printf("\n Entrez le nom de l'etablissement que vous souhaitez ajouter \n");
    scanf("%s",etab->nomEtab);
    printf("\n Entrez le pays de l'etablissement \n");
    scanf("%s",etab->pays);
    printf("\n Entrez la ville de l'etablissement \n");
    scanf("%s",etab->ville);
    return etab;}

Etablissement * rechercher_etab(char nom[30],Liste_etabs liste_etabs){
    Etablissement * etab=liste_etabs.premier;
    while (etab != NULL && strcmp(etab->nomEtab, nom) != 0){
        etab=etab->suivant;
    }
    return etab;
}


Liste_etabs * creer_liste_etabs(){
    Liste_etabs * liste_etabs=malloc(sizeof(Liste_etabs));
    liste_etabs->premier=NULL;
    return liste_etabs;
    
}

void afficher_matiere_etab(Etablissement * etab,Liste_formation *liste_formation){
    Formation * recherche;
    printf("\n\t la liste des matières enseignées dans cet établissement: ");
    for (recherche=liste_formation->premier; recherche!=NULL; recherche=recherche->suivant) {
        if (recherche->etab==etab)
        {
            printf("\n\t%s pour ",recherche->matiere);
            nature(recherche->nature);
        }
        
    }
}

void afficher_etabs_matiere(char matiere[30],Liste_formation * liste_formation)
{
    Formation * recherche;
    printf("\n\t la liste des établissements ou cette matière est enseignée: ");
    for (recherche=liste_formation->premier; recherche!=NULL; recherche=recherche->suivant) {
        if (strcasecmp(matiere, recherche->matiere)==0)
        {
            printf("\n\t\t%s",recherche->etab->nomEtab);
            printf("\n\tPays:\t%s",recherche->etab->pays);
            printf("\n\tVille:\t%s",recherche->etab->ville);
        }

}
}




// Declaration des fonctions des formations


Liste_formation * supprimer_formation(int numero,Liste_formation * liste_formation,Liste_encadrant * liste_encadrant)
{
    Formation * formation=liste_formation->premier;
    for (int i=1;i<numero-1;i++){
        formation=formation->suivant;
    }
    Formation * asuprimer=formation->suivant;
    formation->suivant=formation->suivant->suivant;
    sauvegarder_liste_formations(liste_formation);
    Encadrant * encadrant=asuprimer->encadrant;
    switch (formation->nature) {
        case 1 :
            encadrant->nbreClasseEtdt--;
            break;
        case 2 :
            encadrant->nbreClasseFacilitateur--;
            break;
        case 3:
            encadrant->nbreClasseNatio--;
            break;
        default:
            break;
    }
    sauvegarder_liste_encadrants(liste_encadrant);
    
    return  liste_formation;

    
}



Formation * creer_formation(Liste_encadrant liste_encadrant,Liste_etabs liste_etabs){
    Formation * formation=malloc(sizeof(Formation));
    printf("\nEntrez la matière\t");
    char matiere[30];
    scanf("%s",matiere);
    strcpy(formation->matiere, matiere);
    printf("\nEntrez le nom du formateur\t");
    char nom[30];
    scanf("%s",nom);
    Encadrant * encadrant=rechercher_encadrant(nom, liste_encadrant);
    if (encadrant != NULL) {formation->encadrant=encadrant ;}
    else {
        printf("\nErreur : le formateur n'existe pas. Veuillez ajouter d'abord l'encadrant.\n");
        return NULL;
    }
    Etablissement * etab;
    printf("\nEntrez l'etablissement ou s'est deroulee la formation\t");
    scanf("%s",nom);
    etab=rechercher_etab(nom,liste_etabs);
    if (etab == NULL) {
        printf("\nl'etablissement n'existe pas dans la base de donnee, veuillez l'ajouter d'abord\n");
        return NULL;
    }
    else {
        formation->etab=etab;
    }
    int statut=encadrant->statut;
    if (statut<2){formation->nature=1 ; }
    else if (statut == 2){
        printf("\nEntrez la nature de la formation comme suit :\n \t 1-si elle est destinee aux eleves. \n \t 2-si elle est destinee aux facilitateurs tuteurs. \t ");
        int nature;
        scanf("%d",&nature);
        formation->nature=nature;
    }
    else {printf("\nEntrez la nature de la formation comme suit :\n \t 1-si elle est destinee aux eleves. \n \t 2-si elle est destinee aux facilitateurs tuteurs. \n \t 3-si elle est destinee aux facilitatuers nationaux.\t");
        int nature;
        scanf("%d",&nature);
        formation->nature=nature;}
    printf("\nEntrez le semestre dans lequel cette formation s'est deroulee: \n \t 1-Pour semestre 1. \n \t 2-pour semestre 2.\t");
    scanf("%d",&(formation->semestre));
    printf("\nEntrez le nombre de beneficiaires de cette formation\t");
    scanf("%d",&formation->nbreEleve);
    formation->suivant=NULL;
    return formation;
}


Formation * inserer_formation(Liste_formation * liste_formation,Formation * formation){
    if (liste_formation->premier == NULL) {liste_formation->premier=formation;
        return formation;
    }
    else {
        Formation * recherche=liste_formation->premier;
        while (recherche->suivant != NULL){
            recherche=recherche->suivant;
        }
        formation->suivant=NULL;
        recherche->suivant=formation;
        return formation;
    }
}

Liste_formation * creer_liste_formations(){
    Liste_formation *liste_formation=malloc(sizeof(Liste_formation));
    liste_formation->premier=NULL;
    return liste_formation;
    
}

void afficher_formations_etdt(Liste_formation * liste_formation){
    Formation * recherche_formation;
    for(recherche_formation=liste_formation->premier;recherche_formation != NULL;recherche_formation=recherche_formation->suivant){
        if (recherche_formation->nature==1){
            printf("\n\n\tMatière:\t%s",recherche_formation->matiere);
            printf("\n\tFormateur:\t%s\t",recherche_formation->encadrant->nom);
            printf("\n\tEtablissement:\t%s",recherche_formation->etab->nomEtab);
            printf("\n\tNombre d'étudiants:\t%d",recherche_formation->nbreEleve);
            printf("\n\tSemestre:\t%d",recherche_formation->semestre);
            printf("\n\n");
        }
    }
}
void afficher_formations_tuteurs(Liste_formation * liste_formation){
    Formation *recherche_formation;
    for(recherche_formation=liste_formation->premier;recherche_formation != NULL;recherche_formation=recherche_formation->suivant){
        if (recherche_formation->nature==2){
            printf("\n\n\tMatière:\t%s",recherche_formation->matiere);
            printf("\n\tFormateur:\t%s\t",recherche_formation->encadrant->nom);
            printf("\n\tEtablissement:\t%s",recherche_formation->etab->nomEtab);
            printf("\n\tNombre de formateurs bénéficiaires:\t%d",recherche_formation->nbreEleve);
            printf("\n\tSemestre:\t%d",recherche_formation->semestre);
            printf("\n\n");}}
}

void afficher_formations_nationaux(Liste_formation * liste_formation){
    Formation *recherche_formation;
    for(recherche_formation=liste_formation->premier;recherche_formation != NULL;recherche_formation=recherche_formation->suivant){
        if (recherche_formation->nature==3){
            printf("\n\n\tMatière:\t%s",recherche_formation->matiere);
            printf("\n\tFormateur:\t%s\t",recherche_formation->encadrant->nom);
            printf("\n\tEtablissement:\t%s",recherche_formation->etab->nomEtab);
            printf("\n\tNombre de formateurs beneficiaires:\t%d",recherche_formation->nbreEleve);
            printf("\n\tSemestre:\t%d",recherche_formation->semestre);
            printf("\n\n");
            
        }
    }
}

// Declaration des fonctions de mise à jour






Encadrant * update_nbre_classe(Formation * formation){
    if (formation == NULL) {return NULL;}
    else {Encadrant * encadrant=formation->encadrant;
    int nature=formation->nature;
    if (nature ==1){encadrant->nbreClasseEtdt++;}
    if (nature==2) {encadrant->nbreClasseFacilitateur++;}
    if(nature==3){encadrant->nbreClasseNatio++;}
    return encadrant;
    }}


void update_vers_tuteur(Encadrant * encadrant){
    if (encadrant == NULL) {return;}
    if (encadrant->statut==0){
        char accomplissement[4];
        printf("\n%s a-t'il accompli les 3 parties du programme ? : oui/non \t",encadrant->nom);
        scanf("%s",accomplissement);
        if (strcmp(accomplissement,"oui")==0) {encadrant->statut++;
            printf("\nVous devez féliciter le formateur %s, il est maintenant facilitateur tuteur !\t",encadrant->nom);
        }
        
    }
}


void update_vers_national(Encadrant * encadrant){
    if (encadrant == NULL) {return;}
    if (encadrant->nbreClasseEtdt > 2 && encadrant->statut==1){
        printf("\n%s a-t-il suivi la formation pour devenir national ? oui/non\t",encadrant->nom);
        char accomplissement[4];
        scanf("%s",accomplissement);
        if (strcmp(accomplissement,"oui") == 0){
            encadrant->statut=2;
            printf("\nVous devez féliciter le formateur %s, il est maintenant facilitateur national !\n",encadrant->nom);
        }
    }
}



void update_vers_regional(Encadrant * encadrant){
    if (encadrant == NULL) {return;}
    if(encadrant->statut==2){
        if(encadrant->nbreClasseEtdt>3 && encadrant->nbreClasseFacilitateur>2){
            printf("\n%s a-t-il suivi la formation pour devenir formateur regional (accreditation de type 1)? oui/non\t",encadrant->nom);
            char accomplissement[4];
            scanf("%s",accomplissement);
            if (strcmp(accomplissement,"oui")== 0){
                encadrant->statut++;
                printf("\nVous devez féliciter le formateur %s, il est maintenant facilitateur regional\n",encadrant->nom);
            }
        }
    }
    
}







// Declaration des fonctions des fichiers

/*
void sauvegarder_nbre_encadrant(int nbre_encadrant){
    FILE * fichier=NULL;
    fichier=fopen("nbre_encadrants", "w+");
    fprintf(fichier,"%d",nbre_encadrant);
    fclose(fichier);
    }
int importer_nbre_encadrant(){
    FILE * fichier=NULL;
    int nbre_encadrant;
    fichier=fopen("nbre_encadrants","r");
    fscanf(fichier,"%d",&nbre_encadrant);
    return nbre_encadrant;
    
}*/
void sauvegarder_liste_encadrants(Liste_encadrant * liste_encadrants){
    FILE *fichier = NULL;
    Encadrant * encadrant = NULL;
    
    fichier = fopen("encadrants.txt","w+");
    if(fichier == NULL)
    {
        printf("Erreur !");
        return;
    }
    
    
    for(encadrant =  liste_encadrants->premier; encadrant != NULL; encadrant=encadrant->suivant)
        fprintf(fichier,"%d\n%s\n%d\n%d\n%d\n%d\n%d\n\n",encadrant->code,encadrant->nom,encadrant->statut,encadrant->nbreClasseEtdt,encadrant->nbreClasseFacilitateur,encadrant->nbreClasseNatio,encadrant->partiesAccomplies);
    
    fclose(fichier);
    return;
}

Liste_encadrant * importer_encadrants(){
    Liste_encadrant * liste_encadrants=creer_liste_encadrants();
    FILE * fichier=NULL;
    fichier=fopen("encadrants.txt","r");
    if (fichier==NULL) {return NULL;}
    while (!feof(fichier))
    {   Encadrant * encadrant=malloc(sizeof(Encadrant));
        fscanf(fichier,"%d\n%s\n%d\n%d\n%d\n%d\n%d\n\n",&encadrant->code,encadrant->nom,&encadrant->statut,&encadrant->nbreClasseEtdt,&encadrant->nbreClasseFacilitateur,&encadrant->nbreClasseNatio,&encadrant->partiesAccomplies);
        encadrant=inserer_encadrant(encadrant, liste_encadrants);
    }
    fclose(fichier);
    return liste_encadrants;
}

void sauvegarder_liste_etabs(Liste_etabs *liste_etabs){
    
    FILE *fichier = NULL;
    Etablissement * etab = NULL;
    
    fichier = fopen("etablissements.txt","w");
    if(fichier == NULL)
    {
        printf("Erreur !");
        return;
    }
    
    
    for(etab =  liste_etabs->premier; etab != NULL; etab=etab->suivant)
        fprintf(fichier,"%s\n%s\n%s\n\n",etab->nomEtab,etab->ville,etab->pays);
    
    fclose(fichier);
    return;
}

Liste_etabs * importer_etab(){
    Liste_etabs * liste_etabs=creer_liste_etabs();
    FILE * fichier=NULL;
    fichier=fopen("etablissements.txt", "r");
    if (fichier==NULL) {return NULL;}
    while (!feof(fichier))
    {
        Etablissement* etab=malloc(sizeof(Etablissement));
        fscanf(fichier,"%s\n%s\n%s\n\n",etab->nomEtab,etab->pays,etab->ville);
        etab=inserer_etab(etab,liste_etabs);
        
    }
    fclose(fichier);
    return liste_etabs;
}


void sauvegarder_liste_formations(Liste_formation * liste_formation){
    FILE *fichier = NULL;
    Formation * formation=NULL;
    fichier = fopen("formations.txt","w");
    if(fichier == NULL)
    {
        printf("Erreur !");
        return;
    }
    for (formation=liste_formation->premier;formation!=NULL;formation=formation->suivant)
       { fprintf(fichier,"%s\n%d\n%d\n%s\n%s\n%d\n\n",formation->matiere,formation->nature,formation->semestre,formation->encadrant->nom,formation->etab->nomEtab,formation->nbreEleve);
       }
    fclose(fichier);
    return;
    
}

Liste_formation * importer_formations(Liste_encadrant * liste_encadrant,Liste_etabs * liste_etabs){
    
    Liste_formation * liste_formation=creer_liste_formations();
    
    FILE * fichier=NULL;
    fichier=fopen("formations.txt", "r");
    if (fichier==NULL) {return NULL;}
    while (!feof(fichier))
    {
        Formation * formation=malloc(sizeof(Formation));
        char nom[30];
        char nom_etab[30];
        fscanf(fichier,"%s\n%d\n%d\n%s\n%s\n%d\n\n",formation->matiere,&formation->nature,&formation->semestre,nom,nom_etab,&formation->nbreEleve);
        Encadrant * encadrant=rechercher_encadrant(nom,*liste_encadrant);
        Etablissement * etab=rechercher_etab(nom_etab,*liste_etabs);
        formation->etab=etab;
        formation->encadrant=encadrant;
        formation=inserer_formation(liste_formation,formation);
        
    }
    fclose(fichier);
    return liste_formation;
}




// fonctions pour le main;


int  afficher_menu_principal(){
    system("clear");
    printf("\n\n\n\n\n\n\n");
    printf("\n\n \t\t\t\t 1- Gerer les formateurs");
    printf("\n \t\t\t\t 2- Gerer les formations");
    printf("\n \t\t\t\t 3- Gerer les etablissements");
    printf("\n \t\t\t\t 4- Informations administratives");
    printf("\n \t\t\t\t 5-Sortir");
    printf("\n\n");
    int choix;
    do {
        printf("\n\n\t Entrez le numero correspondant a votre choix");
        fflush(stdin);
        scanf("%d",&choix);}
    while(choix !=1 && choix !=2 && choix!=3 && choix!=4 && choix !=5);
    return choix;

}


void statut(int statut){
    switch (statut) {
        case 0:
            printf("Encadrant");
            break;
        case 1:
            printf("Formateur");
            break;
        case 2:
            printf("Formateur tuteur");
            break;
        case 3:
            printf("Formateur national");
            break;
        case 4:
            printf("Formateur regional");
            break;
        default:
            break;
    }

}

void nature(int nature){
    switch (nature) {
        case 1:
            printf("Eleves");
            break;
        case 2:
            printf("Facilitateurs tuteurs");
            break;
        case 3:
            printf("Facilitateurs nationaux");
            break;
        default:
            break;
    }
}

int nombre_encadrants(Liste_encadrant * liste_encadrant){
    int nombre_encadrants=0;
    Encadrant * recherche=liste_encadrant->premier;
    while (recherche != NULL)
    {
        nombre_encadrants++;
        recherche=recherche->suivant;
    }
    return nombre_encadrants;
}
