#include <stdio.h>
#include <string.h>
#include "gestion_fichier.h"

int chargerAnimaux(Animal *animaux, int max)
{
    FILE *f = fopen("animaux.txt", "r");
    if (f == NULL) {
        return 0; // Aucun fichier au début, c'est normal
    }

    int i = 0;
    while (i < max && fscanf(f, "%d %s %s %d %f ", &animaux[i].id, animaux[i].nom, animaux[i].espece, &animaux[i].annee_naissance, &animaux[i].poids) == 5){
        fgets(animaux[i].commentaire, 255, f);// Lire commentaire jusqu'à fin de ligne
        int len = strlen(animaux[i].commentaire);// Supprimer le \n à la fin
        if (len > 0 && animaux[i].commentaire[len - 1] == '\n') {
            animaux[i].commentaire[len - 1] = '\0';
        }
        i++;
    }
    fclose(f);
    return i;
}

void sauvegarderAnimaux(Animal *animaux, int n)
{
    FILE *f = fopen("animaux.txt", "w");
    if (f == NULL){
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %s %s %d %.2f %s\n", animaux[i].id, animaux[i].nom, animaux[i].espece, animaux[i].annee_naissance, animaux[i].poids, animaux[i].commentaire);
    }
    fclose(f);
}

int supprimerAnimalID(Animal *animaux, int *nb, int id)
{
    for (int i = 0; i < *nb; i++){
        if (animaux[i].id == id){
            for (int j = i; j < *nb - 1; j++){
                animaux[j] = animaux[j + 1];
            }
            (*nb)--;
            return 1;
        }
    }
    return 0;
}