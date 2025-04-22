

#ifndef GESTION_FICHIER_H
#define GESTION_FICHIER_H

#include "animal.h"

int charger_animaux(Animal *animaux, int max);
void sauvegarder_animaux(Animal *animaux, int n);
int supprimer_animal_par_id(Animal *animaux, int *nb, int id);

#endif