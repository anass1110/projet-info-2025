

#ifndef ANIMAL_H
#define ANIMAL_H
#define MAX_ANIMAUX 50


typedef struct {
    int id;
    char nom[50];
    char espece[20];
    int annee_naissance;
    float poids;
    char commentaire[255];
} Animal; // la structure de principale de l'animal

Animal saisir_animal(); 
void afficher_animal(Animal a); 
int age_animal(Animal a, int annee_actuelle); //calculer l'age avec l'anné de naissance et l'anné actu
void rechercher_animaux(Animal *animaux, int nb); // rechercher un animal dans le jeu et la base de donnés 

#endif