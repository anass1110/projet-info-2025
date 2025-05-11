#ifndef COULEURS_H
#define COULEURS_H

// Nettoyage écran
#define clrscr() printf("\033[H\033[2J")

// Styles de texte
#define GRAS "\033[1m"
#define CLIGNOTANT "\033[5m"

// Couleurs du texte
#define TITRE "\033[1;34m"     // Bleu clair (menu principal)
#define INFO "\033[1;37m"      // Texte informatif blanc
#define ERREUR "\033[1;31m"    // Rouge pour les erreurs
#define SUCCES "\033[1;32m"    // Vert pour les succès
#define IMPORTANT "\033[1;33m" // Jaune pour les avertissements
#define SOUSTITRE "\033[1;36m" // Cyan clair (sous-titres)

// Réinitialisation
#define REINIT "\033[0m"

#endif


// Les gars j'ai mis bleu pr les titres, vert pour les ajouts ou les succès etc, 
//jaune pour les stats les avertissements etc et rouge pr les erreurs