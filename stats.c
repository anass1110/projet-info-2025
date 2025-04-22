//pour les variantes INV_AGE_ASC et INV_NB_DESC 


#include <stdio.h>
#include <string.h>
#include "stats.h"

void afficher_quartiles_age(Animal *animaux, int nb) { // affiche le nombre total d'animaux et le quartile d'age
    if (nb == 0) {
        printf("Aucun animal a afficher.\n");
        return;
    }

    int ages[MAX_ANIMAUX]; //MAX_ANIMAUX on l'a défini à 50 dans animal.h
    for (int i = 0; i < nb; i++) {
        ages[i] = 2025 - animaux[i].annee_naissance;
    }

    for (int i = 0; i < nb - 1; i++) {
        for (int j = i + 1; j < nb; j++) {
            if (ages[i] > ages[j]) {
                int temp = ages[i];
                ages[i] = ages[j];
                ages[j] = temp;
            }
        }
    }

    printf("\nNombre total d'animaux : %d\n", nb);
    printf("Quartiles d'age :\n");

    int q1 = nb / 4;
    int q2 = nb / 2;
    int q3 = (3 * nb) / 4;

    printf("Q1 : %d ans\n", ages[q1]);
    printf("Q2 (mediane) : %d ans\n", ages[q2]);
    printf("Q3 : %d ans\n", ages[q3]);
}

// void pour afficher la nourriture journalière à faire