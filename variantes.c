// pour les variantes INV_AGE_ASC et INV_NB_DESC 

#include <stdio.h>
#include <string.h>
#include "variantes.h"
#include "couleurs.h"

void afficherTranchesAge(Animal *animaux, int nb) 
{
    if (nb == 0) {
        printf("Aucun animal à afficher.\n");
        return;
    }

    // initialisation des tranches d’âge
    int tranche1 = 0; // de 0 à 2 ans 
    int tranche2 = 0; // de 3 à 6 ans
    int tranche3 = 0; // de 7 à 10 ans
    int tranche4 = 0; // 11 ans et +
    int age;
    int anneeActuelle = 2025;

    for (int i = 0; i < nb; i++) {
        age = ageAnimal(animaux[i], anneeActuelle);

        if (age <= 2) {
            tranche1++;
        } 
        else if (age <= 6) {
            tranche2++;
        } 
        else if (age <= 10) {
            tranche3++;
        } 
        else {
            tranche4++;
        }
    }

    //  résultats
    printf("\nNombre total d'animaux : %d\n", nb);
    printf("Répartition par tranche d'âge :\n");
    printf("-> 0 - 2 ans : %d animaux\n", tranche1);
    printf("-> 3 - 6 ans : %d animaux\n", tranche2);
    printf("-> 7 - 10 ans : %d animaux\n", tranche3);
    printf("-> 11 et + ans : %d animaux\n", tranche4);
}


void afficher_NourritureJournaliere(Animal *animaux, int nb) 
{
    float total = 0.0;
    float totalHamsters = 0.0;
    float totalAutruches = 0.0;
    float totalChats = 0.0;
    float totalChiens = 0.0;
    int age;

    //tableau pour stocker les indices des espèces inconnues
    int nonReconnu[92];
    int nbNonReconnu = 0;

    for (int i = 0; i < nb; i++) {
        age = 2025 - animaux[i].annee_naissance;

        // règles précises selon l'espèce
        if (strcmp(animaux[i].espece, "hamster") == 0) {
            totalHamsters += 0.020; // 20g en kg
        } 
        else if (strcmp(animaux[i].espece, "autruche") == 0) {
            totalAutruches += 2.5;
        } 
        else if (strcmp(animaux[i].espece, "chat") == 0) {
            if (age < 2) {
                totalChats += 0.5; // dose fixe
            } else {
                totalChats += animaux[i].poids * 0.10; // 10% du poids
            }
        } 
        else if (strcmp(animaux[i].espece, "chien") == 0) {
            if (age < 2) {
                totalChiens += 0.5;
            } else {
                totalChiens += animaux[i].poids * 0.10;
            }
        } 
        else {
            //espèce non gérée donc on stocke l'indice pour les afficher plus tard
            nonReconnu[nbNonReconnu] = i;
            nbNonReconnu++;
        }
    }

    total = totalHamsters + totalAutruches + totalChats + totalChiens;

    //affichage du résultat
    printf("\nQuantité de croquettes nécessaire par jour :\n");
    printf("Hamsters : %.2f kg\n", totalHamsters);
    printf("Autruches : %.2f kg\n", totalAutruches);
    printf("Chats : %.2f kg\n", totalChats);
    printf("Chiens : %.2f kg\n", totalChiens);
    printf("Total : %.2f kg\n", total);

    //si on a des animaux inconnus on les signal
    if (nbNonReconnu > 0) {
        printf("\n" CLIGNOTANT IMPORTANT "⚠️  Animaux d'une autre espèce :\n" REINIT);
        for (int j = 0; j < nbNonReconnu; j++){
            int idx = nonReconnu[j];
            printf("- %s (ID : %d, espèce : %s)\n", 
                animaux[idx].nom, 
                animaux[idx].id, 
                animaux[idx].espece);
        }
    }
}
