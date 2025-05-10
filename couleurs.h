#ifndef COULEURS_H
#define COULEURS_H
#include <stdio.h>

// Effacement écran comme dans le tuto du pdf
#define clrscr() printf("\033[2J\033[H")

// Couleur texte 
#define TXT_NOIR    "\033[30m"
#define TXT_ROUGE   "\033[31m"
#define TXT_VERT    "\033[32m"
#define TXT_JAUNE   "\033[33m"
#define TXT_BLEU    "\033[34m"
#define TXT_MAGENTA "\033[35m"
#define TXT_CYAN    "\033[36m"
#define TXT_BLANC   "\033[37m"

// Couleur fond 
#define FOND_NOIR    "\033[40m"
#define FOND_ROUGE   "\033[41m"
#define FOND_VERT    "\033[42m"
#define FOND_JAUNE   "\033[43m"
#define FOND_BLEU    "\033[44m"
#define FOND_MAGENTA "\033[45m"
#define FOND_CYAN    "\033[46m"
#define FOND_BLANC   "\033[47m"

// Spécial 
#define GRAS         "\033[1m"
#define SOULIGNE     "\033[4m"
#define CLIGNOTANT   "\033[5m"
#define INVERSE      "\033[7m"
#define REINIT       "\033[0m"

// Couleur personnalisé
#define TITRE      TXT_BLEU GRAS
#define SOUSTITRE  TXT_VERT
#define IMPORTANT  TXT_JAUNE GRAS
#define ERREUR     TXT_ROUGE GRAS
#define SUCCES     TXT_VERT GRAS
#define INFO       TXT_CYAN

#endif

// Les gars j'ai mis bleu pr les titres, vert pour les ajouts ou les succès etc, 
//jaune pour les stats les avertissements etc et rouge pr les erreurs