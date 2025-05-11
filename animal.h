#ifndef ANIMAL_H
#define ANIMAL_H
#define MAX_ANIMAUX 50

typedef struct{
    int id;
    char nom[50];
    char espece[20];
    int annee_naissance;
    float poids;
    char commentaire[255];
} Animal; // la structure de principale de l'animal

Animal saisirAnimal(); 
void afficherAnimal(Animal a); 
int ageAnimal(Animal a, int annee_actuelle); //calculer l'age avec l'anné de naissance et l'anné actu
int nvID(Animal *animaux, int nb);
void mettreEnMinuscules(char *chaine);
void rechercherAnimaux(Animal *animaux, int nb); // rechercher un animal dans le jeu et la base de donnés 

#endif