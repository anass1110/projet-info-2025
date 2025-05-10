#include <stdio.h>
#include "interface.h"
#include "animal.h"
#include "variantes.h"
#include "gestion_fichier.h"
#include "couleurs.h"

void titreMenu(char* titre) 
{
    clrscr(); // Efface l’écran et défini dans couleurs.h
    printf(FOND_JAUNE TITRE "🐾 %s 🐾\n" REINIT, titre);
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
    printf("\n"); // simple saut de ligne
}

void pauseAvantRetour() {
    printf("\nAppuyez sur Entrée pour continuer...");
    getchar(); getchar(); 
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
            animaux[*nb] = saisirAnimal();
            animaux[*nb].id = nvID(animaux, *nb);
            (*nb)++;
            afficherSucces("Animal ajouté !");
        }
        

    } 

    else if (choix == 2){
        rechercherAnimaux(animaux, *nb);
        pauseAvantRetour();

    } 

    else if (choix == 3) {
        printf("ID de l'animal à supprimer : ");
        scanf("%d", &id);
        if (supprimerAnimalID(animaux, nb, id)){
            afficherSucces("Animal supprimé !");
        } 
        else {
            afficherErreur("Animal non trouvé !");
        }

        pauseAvantRetour();

    }
    else if (choix == 4){
        sauvegarderAnimaux(animaux, *nb);
        afficherSucces("Données sauvegardées !");
        pauseAvantRetour();
    } 
    else if (choix == 5){
        afficherTranchesAge(animaux, *nb);
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
        afficherErreur("Option non reconnue.");
    }
}