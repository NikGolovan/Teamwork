#ifndef SET_H
#define SET_H
#include <stdio.h>

/* declaration de la structure de données d'une liste chaînée */
typedef struct Cell {
  int element;
  struct Cell *suivant;
} Cellule;

/* declaration du pointeur sur la Cellule */
typedef Cellule *SET;

/* declaration des opérations utilisées pour la gestion d'un set  */
SET setVide();
int estVide(SET set);
int appartient(SET set, int element);
void ajouter(SET *set, int element);
void enlever(SET *set, int element);
void afficherElements(SET set);

#endif
