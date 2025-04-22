

#include <stdio.h>
#include <string.h>
#include "animal.h"

Animal saisir_animal() {
    Animal a;

    printf("Nom : ");
    scanf("%s", a.nom);

    printf("Espece : ");
    scanf("%s", a.espece);

    printf("Annee de naissance : ");
    scanf("%d", &a.annee_naissance);

    printf("Poids : ");
    scanf("%f", &a.poids);

    getchar(); // pour gérer l'espace en trop pour que fget lis la phrase après
    printf("Commentaire (facultatif) : ");
    fgets(a.commentaire, 255, stdin); // on veut rentrer des espaces donc fgets c'est mieux que scanf

    if (a.commentaire[strlen(a.commentaire) - 1] == '\n') { 
        a.commentaire[strlen(a.commentaire) - 1] = '\0';
    }// pour que la phrase ne finisse pas par un espace

    return a;
}

void afficher_animal(Animal a) {
    printf("ID : %d\n", a.id);
    printf("Nom : %s\n", a.nom);
    printf("Espece : %s\n", a.espece);
    printf("Naissance : %d\n", a.annee_naissance);
    printf("Poids : %.2f kg\n", a.poids);

    if (strlen(a.commentaire) > 0) {
        printf("Commentaire : %s\n", a.commentaire);
    }
}

int age_animal(Animal a, int annee_actuelle) {
    return annee_actuelle - a.annee_naissance;
}

// faire le void pour rechercher un animal dans la base de données