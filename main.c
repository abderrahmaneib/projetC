//
//  main.c
//  recitifications
//
//  Created by IBN SEDDIK Abderrahmane on 27/01/2016.
//  Copyright © 2016 MacBook Pro. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"fcts.c"

int main(int argc, const char * argv[]) {

    
   int choix, choix_1_4,choix_1,choix_2,choix_3,choix_4,total_etudiant,retour,i=1,nbre_Encadrant=0;
    char nom_formateur[30],nom_formateur_1_5[30],nom_etab[30],matiere[30],nom_rech_etab[30];
    Encadrant * encadrant,*encadrant_1_5;
    Etablissement *etab=NULL;
    Formation * recherche_formation=NULL,*formation;


   
    Liste_encadrant * liste_encadrant=importer_encadrants();
     Liste_etabs * liste_etabs=importer_etab();
    Liste_formation * liste_formation=importer_formations(liste_encadrant, liste_etabs);



    system("clear");
    printf("\n\n\n\n\n ");
    printf("\tENSIAS\t\t\t\t\t2015/2016\n");
    printf("\t \t Projet: Gestion des formateurs. Réalisé par :");
    printf("\n\t\t\t IBN SEDDIK Abderrahmane");


    

        printf("\n\n \t appuyez sur une touche pour continuer...");
        fflush(stdin);
        getchar();
    

    do {
    retour=2;
    system("clear");
    printf("\n\n\n\n\n\n\n");
    printf("\n\n \t\t\t\t 1- Gérer les formateurs");
    printf("\n \t\t\t\t 2- Gérer les formations");
    printf("\n \t\t\t\t 3- Gérer les établissements");
    printf("\n \t\t\t\t 4-Sortir");
    printf("\n\n");
    do {
        printf("\n\n\t Entrez le numéro correspondant à votre choix\t");
        fflush(stdin);
        scanf("%d",&choix);}
    while(choix !=1 && choix !=2 && choix!=3 && choix!=4);
    system("clear");
    if (choix == 1){
        printf("\n\n\n\n\n\n\n");
        printf("\n\n \t\t\t\t 1- Ajouter un formateur");
        printf("\n \t\t\t\t 2- Chercher un formateur");
        printf("\n \t\t\t\t 3- Afficher la liste des formateurs");
        printf("\n \t\t\t\t 4- Afficher les formateurs par statut");
        printf("\n \t\t\t\t 5- Ajouter une accréditation à un formateur");
        printf("\n \t\t\t\t 6-Sortir");
        printf("\n\n");
        do {
            printf("\n\n\t Entrez le numéro correspondant à votre choix\t");
            fflush(stdin);
            scanf("%d",&choix_1);}
        while(choix_1 !=1 && choix_1 !=2 && choix_1!=3 && choix_1!=4 && choix_1!=5 && choix_1!=6);
        system("clear");
        switch (choix_1) {
            case 1:
                nbre_Encadrant=(nombre_encadrants(liste_encadrant)+1);
                encadrant=creer_encadrant(nbre_Encadrant);
                encadrant=inserer_encadrant(encadrant, liste_encadrant);
                sauvegarder_liste_encadrants(liste_encadrant);
                printf("Le formateur a été ajouté avec succès");
                break;
            case 2:
                printf("\t\t Entrez le nom du formateur que vous voulez chercher\n\t");
                scanf("%s",nom_formateur);
                encadrant=rechercher_encadrant(nom_formateur, *liste_encadrant);
                if (encadrant == NULL) printf("\n\t Le formateur est introuvable, pensez à l'ajouter.\n");
                else {
                    printf("\t\tle formateur a été trouvé\n");
                    printf("\t code: \t %d \n",encadrant->code);
                    printf("\t nom: \t %s\n",encadrant->nom);
                    printf("\t nombres de parties accomplies: \t %d\n",encadrant->partiesAccomplies);
                    printf("\t statut: \t");
                    statut(encadrant->statut);
                    printf("\n");
                    printf("\t nombre de classes d'étudiants formés: \t %d\n",encadrant->nbreClasseEtdt);
                    printf("\t nombre de classes de formateurs tuteurs : \t %d\n",encadrant->nbreClasseFacilitateur);
                    printf("\t nombre de classes de formateurs nationaux : \t %d\n",encadrant->nbreClasseNatio);
                }
                break;
            case 3:
                printf("\n\tla liste de tout les formateurs\n");
                afficher_encadrants(liste_encadrant);
                break;
            case 4:
                printf("\n\n\n\n\n\n\n");
                printf("\n\n \t\t\t\t 1- afficher les formateurs");
                printf("\n \t\t\t\t 2- afficher les facilitateurs tuteurs");
                printf("\n \t\t\t\t 3- Afficher les facilitateurs nationaux");
                printf("\n \t\t\t\t 4- Afficher les facilitateurs régionaux");
                printf("\n \t\t\t\t 5-Sortir");
                printf("\n\n");
                do {
                    printf("\n\n\t Entrez le numéro correspondant à votre choix\t");
                    fflush(stdin);
                    scanf("%d",&choix_1_4);}
                while(choix_1_4 !=1 && choix_1_4 !=2 && choix_1_4!=3 && choix_1_4!=4 && choix_1_4!=5);
                switch (choix_1_4) {
                    case 1:
                        printf("\n\t\tEncadrants:\n");
                        afficher_encadrants_statut(0,*liste_encadrant);
                        break;
                    case 2:
                        printf("\n\t Facilitateurs tuteurs:\n");
                        afficher_encadrants_statut(1,*liste_encadrant);
                        break;
                    case 3:
                        printf("\n\t Facilitateurs nationaux:\n");
                        afficher_encadrants_statut(2,*liste_encadrant);
                        break;
                    case 4:
                        printf("\n\t Facilitateurs régionaux:\n");
                        afficher_encadrants_statut(3,*liste_encadrant);
                        break;
                    case 5:
                        break;
                        
                    default:
                        break;
                }
                break;
            case 5:
                printf("\n\n\t Entrez le nom du formateur\t");
                fflush(stdin);
                scanf("%s",nom_formateur_1_5);
                encadrant_1_5=rechercher_encadrant(nom_formateur_1_5,*liste_encadrant);
                if (encadrant_1_5==NULL) printf("\n L'encadrant est introuvable, pensez à l'ajouter");
                else {
                    printf("\t\tle formateur a été trouvé\n");
                    printf("\t code: \t %d \n",encadrant_1_5->code);
                    printf("\t nom: \t %s\n",encadrant_1_5->nom);
                    printf("\t nombres de parties accomplies: \t %d\n",encadrant_1_5->partiesAccomplies);
                    printf("\t statut: \t");
                    statut(encadrant_1_5->statut);
                    printf("\n");
                    printf("\t nombre de classes d'étudiants formés: \t %d\n",encadrant_1_5->nbreClasseEtdt);
                    printf("\t nombre de classes de formateurs tuteurs : \t %d\n",encadrant_1_5->nbreClasseFacilitateur);
                    printf("\t nombre de classes de formateurs nationaux : \t %d\n",encadrant_1_5->nbreClasseNatio);
                    update_vers_tuteur(encadrant_1_5);
                    printf("\n");
                    update_vers_national(encadrant_1_5);
                    printf("\n");
                    update_vers_regional(encadrant_1_5);
                    printf("\n");
                    printf("\t Opération terminée. In n'y a plus rien à ajouter\n");
                    
                    
                }
                break;


            default:
                break;
        }
        
        
    
    }//accolade de fin de if du choix de 1 du menu principal
    if (choix==2) {
        system("clear");
        printf("\n\n\n\n\n");
        printf("\n\n \t\t\t\t 1- Ajouter une formation");
        printf("\n \t\t\t\t 2-Afficher les formations pour les étudiants");
        printf("\n \t\t\t\t 3- Afficher les formations pour les facilitateurs tuteurs");
        printf("\n \t\t\t\t 4- Afficher les formations pour les facilitateurs nationaux");
        printf("\n \t\t\t\t 5- Afficher les établissements où une matière est enseignée");
        printf("\n \t\t\t\t 6- Sortir");
        printf("\n\n");
        do {
            printf("\n\n\t Entrez le numéro correspondant à votre choix\t");
            fflush(stdin);
            scanf("%d",&choix_2);}
        while(choix_2 !=1 && choix_2 !=2 && choix_2!=3 && choix_2!=4 && choix_2 !=5 && choix_2!=6);
        system("clear");
        switch (choix_2) {
            case 1:
                formation=creer_formation(*liste_encadrant, *liste_etabs);

                if(formation != NULL){
                formation=inserer_formation(liste_formation, formation);

                encadrant=update_nbre_classe(formation);
                update_vers_tuteur(encadrant);

                update_vers_national(encadrant);
                update_vers_regional(encadrant);

                sauvegarder_liste_encadrants(liste_encadrant);

                sauvegarder_liste_formations(liste_formation);}

                break;
                
                
            case 2:
                afficher_formations_etdt(liste_formation);
                break;
            case 3:
                afficher_formations_tuteurs(liste_formation);
                
                break;
            case 4:
                afficher_formations_nationaux(liste_formation);
                    break;
            case 5:
                fflush(stdin);
                printf("\nEntrez la matière que vous cherchez:\t");
                scanf("%s",matiere);
                afficher_etabs_matiere(matiere, liste_formation);
                
                
                break;
            /*
            case 6:
                
                 
                 for(Formation * formation=liste_formation->premier;formation !=NULL; formation=formation->suivant)
                {
                    printf("\t\tFormation numéro: %d\n",i);
                    printf("Nom du l'encadrant:\t%s \nEtablissement:\t%s\nNombre de bénéficiaires:\t %d\nSemestre:\t%d\n",formation->encadrant->nom,formation->etab->nomEtab,formation->nbreEleve,formation->semestre);
                    printf("Formation pour:\t");
                    nature(formation->nature);
                    printf("\n\n\n");
                    i++;
                    
                }
                do
                {
                printf("\n Entrez le numéro de la formation à supprimer:\t\t");
                fflush(stdin);
                scanf("%d",&choix_2_5);
                }
                while (choix_2_5>i-1);
                supprimer_formation(choix_2_5, liste_formation,liste_encadrant);
        
                break;
                */
                default:
            break;}
        }//accolade de fin de if du choix 2 du menu principal
    if (choix==3){
        printf("\n\n\n\n\n\n\n");
        printf("\n\n \t\t\t\t 1- Ajouter un établissement");
        printf("\n \t\t\t\t 2-Afficher les établissements");
        printf("\n \t\t\t\t 3- Afficher les formations passees dans un établissement");
        printf("\n \t\t\t\t 4- Afficher le nombre d'étudiants d'un établissement");
        printf("\n \t\t\t\t 5-Afficher les matières enseignées dans un établissement:");
        printf("\n \t\t\t\t 6-Sortir");
        printf("\n\n");
        do {
            printf("\n\n\t Entrez le numéro correspondant à votre choix\t");
            fflush(stdin);
            scanf("%d",&choix_3);}
        while(choix_3 !=1 && choix_3 !=2 && choix_3!=3 && choix_3!=4 && choix_3 !=5 && choix_3!=6);
        system("clear");
        switch (choix_3) {
            case 1:
                etab=creer_etablissement();
                etab=inserer_etab(etab, liste_etabs);
                sauvegarder_liste_etabs(liste_etabs);
                printf("\t L'établissement a été ajouté avec succès\n");
                break;
            case 2:
                afficher_etabs(*liste_etabs);
                break;
            case 3:
                printf("Entrez le nom de l'établissement\t");
                fflush(stdin);
                scanf("%s",nom_etab);
                etab=rechercher_etab(nom_etab, *liste_etabs);
                if(etab == NULL) printf("\nl'établissement est introuvable. Pensez à l'ajouter.\n");
                else {
                    for(recherche_formation=liste_formation->premier;recherche_formation != NULL;recherche_formation=recherche_formation->suivant)
                    {  if (recherche_formation->etab == etab) {
                        printf("\n \t formation pour :\t");
                        nature(recherche_formation->nature);
                        printf("\n \t formateur:\t%s",recherche_formation->encadrant->nom);
                        printf("\n\t nombre d'élèves:\t%d",recherche_formation->nbreEleve);
                        printf("\n\t semestre:\t %d\n\n",recherche_formation->semestre);
                        }
                    }
                }
                break;
            case 4:
                printf("\nEntrez le nom de l'établissement\t");
                fflush(stdin);
                scanf("%s",nom_etab);
                etab=rechercher_etab(nom_etab, *liste_etabs);
                if(etab == NULL) printf("\nl'établissement est introuvable. Pensez à l'ajouter.\t");
                else {
                    total_etudiant=0;
                    for(recherche_formation=liste_formation->premier;recherche_formation != NULL;recherche_formation=recherche_formation->suivant){
                    if (strcmp(nom_etab,recherche_formation->etab->nomEtab)== 0) {
                        total_etudiant+=recherche_formation->nbreEleve;
                    }}
                    printf("\n\n \t Le nombre total des étudiants de cet établissement est %d\t\n\n",total_etudiant);
                }
                break;
            case 5:
                printf("\nEntrez l'établissement\t");
                fflush(stdin);
                scanf("%s",nom_rech_etab);
                if(rechercher_etab(nom_rech_etab,*liste_etabs)==NULL)
                {
                    printf("\nCet établissement est introuvable");
                    break;
                }
                
                afficher_matiere_etab(rechercher_etab(nom_rech_etab,*liste_etabs), liste_formation);
                break;
            case 6:
                break;
            default:
                break;
        }
        
    
    }//accolade de fin de if du choix 3
        if (choix ==4) return 0;
        printf("\n\n\n\t\tPour revenir au menu, appuyez sur 0\n  ");
        printf("\t\t Pour sortir appuyer sur une autre touche\n");
        fflush(stdin);
        scanf("%d",&retour);
        if(retour != 0)
            return(0);
    } while(retour == 0);

    fflush(stdin);
   getchar();

    return 0;
}


