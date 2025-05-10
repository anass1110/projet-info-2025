//pour les variantes INV_AGE_ASC et INV_NB_DESC 

#include <stdio.h>
#include <string.h>
#include "variantes.h"

void afficherTranchesAge(Animal *animaux, int nb) 
{
    if (nb == 0) {
        printf("Aucun animal à afficher.\n");
        return;
    }

    int tranche1 = 0; // de 0 à 2ans 
    int tranche2 = 0; // de 3 à 6
    int tranche3 = 0; // de 7 à 10
    int tranche4 = 0; // 11 ans et +
    int age;
    int anneeActuelle = 2025;

    for (int i = 0; i < nb; i++) {
        age = ageAnimal(animaux[i], anneeActuelle);

        if (age <= 2) {
            tranche1++;
        } else if (age <= 6) {
            tranche2++;
        } else if (age <= 10) {
            tranche3++;
        } else {
            tranche4++;
        }
    }

    printf("\nNombre total d'animaux : %d\n", nb);
    printf("Répartition par tranche d'âge :\n");
    printf("-> 0 - 2 ans : %d animaux\n", tranche1);
    printf("-> 3 - 6 ans : %d animaux\n", tranche2);
    printf("-> 7 - 10 ans : %d animaux\n", tranche3);
    printf("-> 11 et + ans : %d animaux\n", tranche4);
}




void afficher_NourritureJournaliere(Animal *animaux, int nb) 
{
    float total= 0.0;
    float total_hamsters = 0.0;
    float total_autruches = 0.0;
    float total_chats = 0.0;
    float total_chiens = 0.0;
    int age;
    for (int i= 0; i < nb; i++) {
        age= 2025 - animaux[i].annee_naissance;
        if (strcmp(animaux[i].espece, "hamster") == 0){ //strcmp compare les mots
            total_hamsters += 0.020; // 20g converti en kg
        } 
        else if(strcmp(animaux[i].espece, "autruche")== 0){
            total_autruches += 2.5; //2.5kg
        } 
        else if(strcmp(animaux[i].espece, "chat") ==0) {
            if (age < 2){
                total_chats += 0.5; //ici 0.5 kg
            } 
            else {
                total_chats += animaux[i].poids * 0.10; //le poids * 10%
            }
        } 
        else if (strcmp(animaux[i].espece, "chien") == 0) {
            if (age < 2){
                total_chiens += 0.5;
            } 
            else {
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
