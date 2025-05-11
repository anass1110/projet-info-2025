#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "interface.h"
#include "gestion_fichier.h"
#include "variantes.h"

int main() {
    Animal animaux[MAX_ANIMAUX];
    int nb = chargerAnimaux(animaux, MAX_ANIMAUX);
    int choix;

    afficherBienvenue(); // ✅ Affiche le chien de bienvenue au démarrage

    do {
        afficherMenu();

        char ligne[100];
        fgets(ligne, sizeof(ligne), stdin);

        if (ligne[0] == '\n') continue;

        int valide = 1;
        for (int i = 0; ligne[i] != '\0' && ligne[i] != '\n'; i++) {
            if (ligne[i] < '0' || ligne[i] > '9') {
                valide = 0;
            }
        }

        if (!valide) {
            afficherErreur("Merci de taper un nombre pour votre choix.");
            pauseAvantRetour();
            continue;
        }

        choix = atoi(ligne);
        executerCommande(choix, animaux, &nb);

    } while (choix != 0);

    return 0;
}
