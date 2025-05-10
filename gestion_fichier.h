

#ifndef GESTION_FICHIER_H
#define GESTION_FICHIER_H
#include "animal.h"

int chargerAnimaux(Animal *animaux, int max);
void sauvegarderAnimaux(Animal *animaux, int n);
int supprimerAnimalID(Animal *animaux, int *nb, int id);

#endif