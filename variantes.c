//pour les variantes INV_AGE_ASC et INV_NB_DESC 

#include <stdio.h>
#include <string.h>
#include "variantes.h"

void afficherTranchesAge(Animal *animaux, int nb) { // affiche le nombre total d'animaux et le quartile d'age
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



void afficher_NourritureJournaliere(Animal *animaux, int nb) {
    float total= 0.0;
    float total_hamsters = 0.0;
    float total_autruches = 0.0;
    float total_chats = 0.0;
    float total_chiens = 0.0;
    int age;

    for (int i= 0; i < nb; i++) {
        age= 2025 - animaux[i].annee_naissance;

        if (strcmp(animaux[i].espece, "hamster") == 0) { //strcmp compare les mots
            total_hamsters += 0.020; // 20g converti en kg
        } 
        else if (strcmp(animaux[i].espece, "autruche")== 0) {
            total_autruches += 2.5; //2.5kg
        } 
        else if (strcmp(animaux[i].espece, "chat") ==0) {
            if (age < 2) {
                total_chats += 0.5; //ici 0.5 kg
            } else {
                total_chats += animaux[i].poids * 0.10; //le poids * 10%
            }
        } 
        else if (strcmp(animaux[i].espece, "chien") == 0) {
            if (age < 2) {
                total_chiens += 0.5;
            } else {
                total_chiens += animaux[i].poids * 0.10; // 10% de son poids
            }
        }
    }

    total= total_hamsters + total_autruches + total_chats + total_chiens;

    printf("\nQuantité de croquettes nécessaire par jour :\n");
    printf("Hamsters : %.2f kg\n", total_hamsters);
    printf("Autruches : %.2f kg\n", total_autruches);
    printf("Chats : %.2f kg\n", total_chats);
    printf("Chiens : %.2f kg\n", total_chiens);
    printf("Total : %.2f kg\n", total);
}
