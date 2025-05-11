#include <stdio.h>
#include <string.h>
#include "gestion_fichier.h"

int chargerAnimaux(Animal *animaux, int max)
{
    FILE *f = fopen("animaux.txt", "r");
    if (f == NULL) {
        return 0; // aucun fichier trouvé au départ → c’est normal si c’est le premier lancement
    }
    int i = 0;
    // on lit chaque ligne du fichier tant qu'on n’a pas dépassé max
    while (i < max && fscanf(f, "%d %s %s %d %f ", 
            &animaux[i].id, 
            animaux[i].nom, 
            animaux[i].espece, 
            &animaux[i].annee_naissance, 
            &animaux[i].poids) == 5){

        fgets(animaux[i].commentaire, 255, f); // on récupère le commentaire (tout le reste de la ligne)
        // on enlève le \n à la fin du commentaire
        int len = strlen(animaux[i].commentaire);
        if (len > 0 && animaux[i].commentaire[len - 1] == '\n') {
            animaux[i].commentaire[len - 1] = '\0';
        }
        i++;
    }

    fclose(f);
    return i; // on retourne combien d’animaux on a chargés
}


void sauvegarderAnimaux(Animal *animaux, int n)
{
    FILE *f = fopen("animaux.txt", "w");
    if (f == NULL){
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }
    // on écrit chaque animal sur une ligne avec tous ses champs
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %s %s %d %.2f %s\n", 
            animaux[i].id, 
            animaux[i].nom, 
            animaux[i].espece, 
            animaux[i].annee_naissance, 
            animaux[i].poids, 
            animaux[i].commentaire);
    }

    fclose(f);
}


int supprimerAnimalID(Animal *animaux, int *nb, int id)
{
    // on cherche l'animal avec le bon id
    for (int i = 0; i < *nb; i++){
        if (animaux[i].id == id){
            
            // on décale tous les suivants vers la gauche
            for (int j = i; j < *nb - 1; j++){
                animaux[j] = animaux[j + 1];
            }

            (*nb)--; // on diminue le nombre d’animaux
            return 1; // suppression réussie
        }
    }

    return 0; // on n’a rien trouvé
}