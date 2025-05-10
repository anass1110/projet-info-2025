#include <stdio.h>
#include "animal.h"
#include "gestion_fichier.h"
#include "interface.h"
#include "variantes.h"

int main() 
{
    Animal animaux[MAX_ANIMAUX];
    int nbanimaux = 0;
    int choix = -1;

    nbanimaux = chargerAnimaux(animaux, MAX_ANIMAUX); // Charger les animaux depuis un fichier

    while (choix != 0) {  // continuer tant qu'on ne quitte pas
        afficherMenu(); // afficher le menu principal
        scanf("%d", &choix);
        while (getchar() != '\n'); // 🔧 correction ici : vider le buffer après scanf

        executerCommande(choix, animaux, &nbanimaux); // exécuter ce que l'utilisateur a demandé 
    }

    return 0;
}