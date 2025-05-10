

#ifndef INTERFACE_H
#define INTERFACE_H
#include "animal.h"
#include "couleurs.h"
#define MAX_INPUT 100

void titreMenu(char* titre);
void afficherErreur(char* message);
void afficherSucces(char* message);
void pauseAvantRetour();
void SauterLigne();
void afficherMenu();
void executerCommande(int choix, Animal *animaux, int *nb);

#endif