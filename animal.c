

#include <stdio.h>
#include <string.h>
#include <ctype.h> // pour tolower
#include "animal.h"
#include "interface.h"

Animal saisirAnimal() 
{
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
    
    if(a.commentaire[strlen(a.commentaire) - 1] == '\n'){ 
        a.commentaire[strlen(a.commentaire) - 1] = '\0';
    }// pour que la phrase ne finisse pas par un espace

    return a;
}

void afficherAnimal(Animal a) 
{
    printf("ID : %d\n", a.id);
    printf("Nom : %s\n", a.nom);
    printf("Espece : %s\n", a.espece);
    printf("Naissance : %d\n", a.annee_naissance);
    printf("Poids : %.2f kg\n", a.poids);
    if (strlen(a.commentaire) > 0) {
        printf("Commentaire : %s\n", a.commentaire);
    }
}

int ageAnimal(Animal a, int annee_actuelle) 
{
    return annee_actuelle - a.annee_naissance;
}


int nvID(Animal *animaux, int nb) {
    int max_id = 0;
    for (int i = 0; i < nb; i++) {
        if (animaux[i].id > max_id) {
            max_id = animaux[i].id;
        }
    }
    return max_id + 1;
}


void mettreEnMinuscules(char *chaine) {
    int i = 0;
    while (chaine[i]) {
        chaine[i] = tolower(chaine[i]);
        i++;
    }
}

void rechercherAnimaux(Animal *animaux, int nb) 
{
    char nom[50];
    char espece[20];
    int ageMin = 0, ageMax = 100;
    int filtreNom = 0, filtreEspece = 0, filtreAge = 0;
    int trouve = 0;
    char rep;
    int choixAge;
    int age;

    printf("Souhaitez-vous rechercher par nom ? (O/N) : ");
    scanf(" %c", &rep);
    if (rep == 'O' || rep == 'o') {
        filtreNom = 1;
        printf("Nom : ");
        scanf("%s", nom);
        if (!motValide(nom)) {
            afficherErreur("Nom invalide (lettres uniquement). Recherche annulée.");
            return;
        }
        mettreEnMinuscules(nom);
    }

    printf("Souhaitez-vous rechercher par espèce ? (O/N) : ");
    scanf(" %c", &rep);
    if (rep == 'O' || rep == 'o') {
        filtreEspece = 1;
        printf("Espèce : ");
        scanf("%s", espece);
        if (!motValide(espece)) {
            afficherErreur("Espèce invalide (lettres uniquement). Recherche annulée.");
            return;
        }
        mettreEnMinuscules(espece);
    }

    printf("Souhaitez-vous rechercher par type d'âge ? (O/N) : ");
scanf(" %c", &rep);
if (rep == 'O' || rep == 'o') {
    printf("Quel type ?\n");
    printf("1 = Jeune (<2 ans)\n");
    printf("2 = Senior (>10 ans)\n");
    printf("3 = Adulte (entre 2 et 10 ans)\n");
    scanf("%d", &choixAge);

    if (choixAge == 1) {
        filtreAge = 1;
        ageMax = 1;
    } else if (choixAge == 2) {
        filtreAge = 1;
        ageMin = 11;
    } else if (choixAge == 3) {
        filtreAge = 1;
        ageMin = 2;
        ageMax = 10;
    } else {
        afficherErreur("Type d'âge non reconnu. Aucun filtre d'âge ne sera appliqué.");
        return; // pour stopper la fonction parce que sinon elle printf tous les animaux
    }
}


    printf("\nRésultats :\n");

    for (int i = 0; i < nb; i++) {
        age = ageAnimal(animaux[i], 2025);

        char nomAnimal[50];
        char especeAnimal[20];
        strcpy(nomAnimal, animaux[i].nom);
        strcpy(especeAnimal, animaux[i].espece);
        mettreEnMinuscules(nomAnimal);
        mettreEnMinuscules(especeAnimal);

        int okNom = !filtreNom || strcmp(nomAnimal, nom) == 0;
        int okEspece = !filtreEspece || strcmp(especeAnimal, espece) == 0;
        int okAge = !filtreAge || (age >= ageMin && age <= ageMax);

        if (okNom && okEspece && okAge) {
            afficherAnimal(animaux[i]);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun animal trouvé.\n");
    }
}

int estLettre(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}


int motValide(char *mot) {
    int i = 0;
    while (mot[i]) {
        if (!estLettre(mot[i])) {
            return 0;
        }        
        i++;
    }
    return 1;
}

