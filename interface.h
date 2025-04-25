

#ifndef INTERFACE_H
#define INTERFACE_H

#include "animal.h"
#include "couleurs.h"

#define MAX_INPUT 100

void afficher_menu_principal();
void afficher_entete(const char* titre); //const c'est pour éviter que le message soit modifié (par sécurité)
void afficher_message_erreur(const char* message);
void afficher_message_succes(const char* message);
void afficher_ligne_separateur();
void executer_commande(int choix, Animal *animaux, int *nb);

#endif