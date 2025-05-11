

#include <stdio.h>
#include <string.h>
#include <ctype.h> // pour tolower
#include "animal.h"
#include "interface.h"
#include <stdlib.h> // pour atoi


Animal saisirAnimal() 
{
    Animal a;

    // vérif du nom
    int nomValide = 0;
    while (!nomValide){
        printf("Nom : ");
        scanf(" %[^\n]", a.nom);
        nomValide = 1;

        for (int i = 0; a.nom[i] != '\0'; i++){
            char c = a.nom[i];
            if(!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '-' || c == '\'' || c == ' ')){
                nomValide = 0;
            }
        }

        if (!nomValide){
            printf(CLIGNOTANT GRAS IMPORTANT "❗ Merci d’écrire le prénom seulement en lettre sans espaces ou caractère spécial.\n" REINIT);
        }
    }

    // vérif de l'espèce
    int especeValide = 0;
    while (!especeValide){
        printf("Espece : ");
        scanf(" %[^\n]", a.espece);
        especeValide = 1;

        for (int i = 0; a.espece[i] != '\0'; i++){
            char c = a.espece[i];
            if(!((c >= 'A' && c <= 'Z')||  (c >='a' && c<='z')||  c =='-' || c =='\''
             || c == ' ')){
                especeValide = 0;
            }
        }

        if (!especeValide){
            printf(CLIGNOTANT GRAS IMPORTANT "❗ Merci d’entrer que des lettres sans chiffre ni caractère spécial.\n" REINIT);
        }
    }

    while (getchar() != '\n'); // vide le buffer

    char ligne[92];
    int valide = 0;
    while (!valide) {
        printf("Année de naissance : ");
        fgets(ligne, sizeof(ligne), stdin);

        if (ligne[strlen(ligne) - 1] == '\n'){
            ligne[strlen(ligne) - 1] = '\0';
        }

        // on vérifie que la saisie n'est pas vide
        if (ligne[0] == '\0') {
            valide = 0;
            afficherErreur("Saisie vide non autorisée.");
            continue;
        }

        // vérifie que c’est bien des chiffres
        valide = 1;
        for (int i = 0; ligne[i] != '\0'; i++) {
            if (ligne[i] < '0' || ligne[i] > '9'){
                valide = 0;
            }
        }

        if(!valide){
            afficherErreur("Saisie impossible, Veuillez entrer une année en chiffres, sans espace.");
        } else{
            a.annee_naissance = atoi(ligne);
            if (a.annee_naissance > 2025){
                afficherErreur("L’année de naissance ne peut pas être supérieure à 2025.");
                valide = 0;
            }
        }
    }

    char poidsTexte[92];
    int poidsValide = 0;
    while (!poidsValide) {
        printf("Poids : ");
        fgets(poidsTexte, sizeof(poidsTexte), stdin);

        if (poidsTexte[strlen(poidsTexte) - 1] == '\n') {
            poidsTexte[strlen(poidsTexte) - 1] = '\0';
        }

        // on bloque si l’utilisateur appuie juste sur Entrée
        if (poidsTexte[0] == '\0') {
            poidsValide = 0;
            afficherErreur("Le poids est obligatoire.");
            continue;
        }

        poidsValide = 1;
        int point = 0;

        for (int i = 0; poidsTexte[i] != '\0'; i++) {
            char c = poidsTexte[i];
            if (c == '.'){
                if (point){
                    poidsValide = 0;
                }
                point = 1;
            }
            else if(c < '0' || c > '9') {
                poidsValide = 0;
            }
        }

        if(!poidsValide){
            afficherErreur("Veuillez entrer un poids en chiffres, sans espaces(ex: 92 ou 92.5).");
        } else {
            a.poids = atof(poidsTexte);
        }
    }

    printf("Commentaire (facultatif) : ");
    fgets(a.commentaire, 255, stdin); // commentaire avec espaces donc fgets

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


int nvID(Animal *animaux, int nb){
    int maxID = 0;
    for (int i = 0; i < nb; i++){       // on parcourt tous les animaux pour trouver le plus grand ID
        if(animaux[i].id > maxID) {
            maxID = animaux[i].id;
        }
    }
    // pour que le nouveau soit le suivant du plus grands
    return maxID + 1;
}


void mettreEnMinuscules(char *chaine){
    int i = 0;
    while (chaine[i]){
        chaine[i] = tolower(chaine[i]);
        i++;
    }
}

void rechercherAnimaux(Animal *animaux, int nb) 
{
    char nom[92];
    char espece[92];
    int ageMin = 0, ageMax = 92;
    int filtreNom = 0, filtreEspece = 0, filtreAge = 0;
    int trouve = 0;
    char rep;
    int choixAge;
    int age;

    // on demande si on veut filtrer par nom
    int choixValide = 0;    
    while (!choixValide){
        printf("Souhaitez-vous rechercher par nom ? (O/N) : ");
        scanf(" %c", &rep);
        while (getchar() != '\n');
        if(rep == 'O' || rep == 'o' || rep == 'N' || rep == 'n') {
            choixValide = 1;
        } else{
            printf(CLIGNOTANT GRAS IMPORTANT "❗ Merci de taper uniquement O ou N.\n" REINIT);
        }
    }
    // si oui, on saisit le nom et on vérifie qu’il est valide
    if (rep == 'O' || rep == 'o') {
        filtreNom = 1;
        int nomValide = 0;
        while(!nomValide){
            printf("Nom : ");
            fgets(nom, sizeof(nom), stdin);

            // on enlève le saut de ligne à la fin pr éviter les bugs
            if(nom[strlen(nom) - 1] == '\n'){
                nom[strlen(nom) - 1] = '\0';
            }

            mettreEnMinuscules(nom); // on met en minuscules pour comparer après
            nomValide = 1;
            for(int i = 0; nom[i] != '\0'; i++) {
                char c = nom[i];
                if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '-' || c == '\'' || c == ' ')) {
                    nomValide = 0;
                }
            }

            if (!nomValide){
                afficherErreur("❗ Merci d’écrire uniquement des lettres sans accents ni caractères spéciaux.");
            }
        }
    }
    // on demande si on veut filtrer par espèce
    choixValide = 0;
    while (!choixValide){
        printf("Souhaitez-vous rechercher par espèce ? (O/N) : ");
        scanf(" %c", &rep);
        while (getchar() != '\n');
        if (rep == 'O' || rep == 'o' || rep == 'N' || rep == 'n'){
            choixValide = 1;
        } else{
            printf(CLIGNOTANT GRAS IMPORTANT "❗ Merci de taper uniquement O ou N.\n" REINIT);
        }
    }
    // si oui on fait pareil pour l'espèce
    if (rep == 'O' || rep == 'o') {
        filtreEspece = 1;
        int especeValide = 0;

        while (!especeValide){
            printf("Espèce : ");
            scanf("%s", espece);
            mettreEnMinuscules(espece);
            especeValide = 1;
            for (int i = 0; espece[i] != '\0'; i++) {
                char c = espece[i];
                if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '-' || c == '\'' || c == ' ')) {
                    especeValide = 0;
                }
            }
            if (!especeValide) {
                afficherErreur("❗ Merci d’écrire uniquement des lettres sans accents ni caractères spéciaux.");
            }
        }
    }

    // même chose mais pour les tranches d’âge
    choixValide = 0;
    while (!choixValide) {
        printf("Souhaitez-vous rechercher par type d'âge ? (O/N) : ");
        scanf(" %c", &rep);
        while (getchar() != '\n');

        if (rep == 'O' || rep == 'o' || rep == 'N' || rep == 'n') {
            choixValide = 1;
        } else {
            printf(CLIGNOTANT GRAS IMPORTANT "❗ Merci de taper uniquement O ou N.\n" REINIT);
        }
    }

    if (rep == 'O' || rep == 'o') {
        printf("Quel type ?\n");
        printf("1 = Jeune (<2 ans)\n");
        printf("2 = Senior (>10 ans)\n");
        printf("3 = Adulte (entre 2 et 10 ans)\n");

        int saisieAgeValide = 0;
        char ligne[100];
        while (!saisieAgeValide) {
            printf("Choix : ");
            fgets(ligne, sizeof(ligne), stdin);

            if (ligne[strlen(ligne) - 1] == '\n') {
                ligne[strlen(ligne) - 1] = '\0';
            }
            int estEntier = 1;
            for (int i = 0; ligne[i] != '\0'; i++) {
                if (ligne[i] < '0' || ligne[i] > '9') {
                    estEntier = 0;
                }
            }
            if (!estEntier) {
                printf(CLIGNOTANT GRAS IMPORTANT "❗ Saisie invalide. Veuillez taper un nombre (1, 2 ou 3).\n" REINIT);
                continue;
            }
            choixAge = atoi(ligne);
            if (choixAge == 1) {
                filtreAge = 1;
                ageMax = 1;
                saisieAgeValide = 1;
            } else if (choixAge == 2) {
                filtreAge = 1;
                ageMin = 11;
                saisieAgeValide = 1;
            } else if (choixAge == 3) {
                filtreAge = 1;
                ageMin = 2;
                ageMax = 10;
                saisieAgeValide = 1;
            } else {
                printf(CLIGNOTANT GRAS IMPORTANT "❗ Veuillez choisir uniquement entre 1, 2 ou 3.\n" REINIT);
            }
        }
    }

    // maintenant on affiche les résultats
    printf("\nRésultats :\n");

    for (int i = 0; i < nb; i++) {
        age = ageAnimal(animaux[i], 2025);

        char nomAnimal[92];
        char especeAnimal[92];
        strcpy(nomAnimal, animaux[i].nom);
        strcpy(especeAnimal, animaux[i].espece);
        mettreEnMinuscules(nomAnimal);
        mettreEnMinuscules(especeAnimal);
        // on vérifie que l’animal correspond aux filtres choisis
        int okNom = !filtreNom || strcmp(nomAnimal, nom) == 0;
        int okEspece = !filtreEspece || strcmp(especeAnimal, espece) == 0;
        int okAge = !filtreAge || (age >= ageMin && age <= ageMax);

        if (okNom && okEspece && okAge) {
            afficherAnimal(animaux[i]);
            trouve = 1;
        }
    }

    if (!trouve){
        printf("Aucun animal trouvé.\n");
    }
}
