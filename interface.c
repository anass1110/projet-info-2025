#include <stdio.h>
#include <string.h>    // pour strlen()
#include <stdlib.h> // pour atoi()
#include "interface.h"
#include "animal.h"
#include "variantes.h"
#include "gestion_fichier.h"
#include "couleurs.h"

void titreMenu(char* titre) 
{
    clrscr(); // Efface l’écran et défini dans couleurs.h
    printf(TITRE "🐾 %s 🐾\n" REINIT, titre);
}

void afficherErreur(char* message) 
{
    printf(ERREUR "❌ Erreur : %s\n" REINIT, message);
}

void afficherSucces(char* message) 
{
    printf(SUCCES "✅ Succès : %s\n" REINIT, message);
}

void SauterLigne() 
{
    printf("\n"); 
}

void pauseAvantRetour()     // pour absorber les \n et attendre le Entrée de l'utilisateur
{
    printf("\nAppuyez sur Entrée pour continuer...");
    getchar(); getchar();   // le premier getchar absorbe l’ancien \n, le deuxième attend l'ntrée de l'utilisateur
}


void afficherMenu() 
{
    titreMenu("ChenYl-Tech - Menu Principal");
    printf(SOUSTITRE "Que souhaitez-vous faire ?\n" REINIT);
    printf("1. Ajouter un animal 🐶\n");
    printf("2. Rechercher un animal 🔍\n");
    printf("3. Supprimer un animal ❌\n");
    printf("4. Sauvegarder les données 💾\n");
    printf("5. Afficher l’inventaire par âge 📊\n");
    printf("6. Calculer la nourriture quotidienne 🍖\n");
    printf("0. Quitter ❎\n");
    SauterLigne();
    printf("Votre choix : ");
}

void executerCommande(int choix, Animal *animaux, int *nb) 
{
    int id;

    if (choix == 1){
        if (*nb >= MAX_ANIMAUX){
            afficherErreur("Refuge plein !");
        } 
        else{
            animaux[*nb] = saisirAnimal();            // On remplit une nouvelle case du tableau
            animaux[*nb].id = nvID(animaux, *nb);     // Génération automatique d’un nv ID qui existait pas
            (*nb)++;                                   // Incrémentation du nombre total d'animaux
            afficherSucces("Animal ajouté !");
        }

    } 

    else if (choix == 2){
        rechercherAnimaux(animaux, *nb);      
        pauseAvantRetour();                   // Pause pour lire les résultats avant retour au menu

    } 

    else if (choix == 3){
        // sécurisation de la saisie de l'ID à supprimer
        char saisieID[100];
        int idValide = 0;

        while (!idValide){
            printf("ID de l'animal à supprimer : ");
            fgets(saisieID, sizeof(saisieID), stdin);

            if (saisieID[strlen(saisieID) - 1] == '\n'){
                saisieID[strlen(saisieID) - 1] = '\0';     // enlever le \n à la fin si il existe
            }

            idValide = 1;
            for (int i = 0; saisieID[i] != '\0'; i++){
                if (saisieID[i] < '0' || saisieID[i] > '9'){ // on vérifie que chaque caractère est un chiffre
                    idValide = 0;
                }
            }

            if (!idValide){
                printf(CLIGNOTANT GRAS IMPORTANT "❗ Merci de saisir uniquement des chiffres pour l'ID, sans espaces.\n" REINIT);
            }else {
                id = atoi(saisieID);  // conversion de la chaîne vers int seulement si c’est bien un nombre
            }
        }

        if (supprimerAnimalID(animaux, nb, id)){ 
            afficherSucces("Animal supprimé !");
        } 
        else{
            afficherErreur("Animal non trouvé !");
        }

        pauseAvantRetour(); // attendre avant de revenir au menu

    }

    else if (choix == 4){
        sauvegarderAnimaux(animaux, *nb);      // Sauvegarde dans le fichier animaux.txt
        afficherSucces("Données sauvegardées !");
        pauseAvantRetour();
    } 

    else if (choix == 5){
        afficherTranchesAge(animaux, *nb);     // Affiche le nombre d’animaux par tranche d’âge
        pauseAvantRetour();
    } 
    else if (choix == 6) {
        afficher_NourritureJournaliere(animaux, *nb); 
        pauseAvantRetour();
    } 

    else if (choix == 0){
        printf(INFO "Fermeture du programme. À bientôt !\n" REINIT); 
    } 
    else{
        afficherErreur("Option non reconnue."); // que si le choix esy invalide
    }
}


void afficherBienvenue()
{
    clrscr();

    printf(TITRE
    "⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣠⣶⠚⠛⠿⠷⠶⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⢀⣴⠟⠉⠀⠀⢠⡄⠀⠀⠀⠀⠀⠉⠙⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⢀⡴⠛⠁⠀⠀⠀⠀⠘⣷⣴⠏⠀⠀⣠⡄⠀⠀⢨⡇⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠺⣇⠀⠀⠀⠀⠀⠀⠀⠘⣿⠀⠀⠘⣻⣻⡆⠀⠀⠙⠦⣄⣀⠀⠀⠀⠀\n"
    "⠀⠀⠀⢰⡟⢷⡄⠀⠀⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢻⠶⢤⡀\n"
    "⠀⠀⠀⣾⣇⠀⠻⣄⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣀⣴⣿\n"
    "⠀⠀⢸⡟⠻⣆⠀⠈⠳⢄⡀⠀⠀⡼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠶⠶⢤⣬⡿⠁\n"
    "⠀⢀⣿⠃⠀⠹⣆⠀⠀⠀⠙⠓⠿⢧⡀⠀⢠⡴⣶⣶⣒⣋⣀⣀⣤⣶⣶⠟⠁⠀\n"
    "⠀⣼⡏⠀⠀⠀⠙⠀⠀⠀⠀⠀⠀⠀⠙⠳⠶⠤⠵⣶⠒⠚⠻⠿⠋⠁⠀⠀⠀⠀\n"
    "⢰⣿⡇⠀⠀⠀⠀⠀⠀⠀⣆⠀⠀⠀⠀⠀⠀⠀⢠⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⢿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠘⣦⡀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣷⡄⠀⠀⠀⠀⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⡀⠀⠀⠀⢸⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "\nBonjour, bienvenue dans notre chenil ! 🐶\n"
    REINIT);

    SauterLigne();
    pauseAvantRetour();
}
