#ifndef ARBRE_H
#define ARBRE_H
#include <stdio.h>

#define MAX 50

typedef int Element;
typedef int Position;

typedef struct un_noeud {
  Element element;
  int nb_sous_arbres;
  struct un_noeud *fils[MAX];
} Noeud;

typedef Noeud *Arbre;

typedef struct a_tree {
  Arbre un_arbre;
  Position position;
  struct a_tree *suivant;
} Tree;

typedef Tree *Foret;

int estArbreVide(Arbre arbre); /* fait */
int estForetVide(Foret foret); /* fait */
Noeud racineArbre(Arbre arbre); /* fait */
Foret listeSousArbres(Arbre arbre); /* fait */
Arbre iemeArbre(Foret foret, int i); /* fait */
int nombreArbres(Foret foret); /* fait */
Arbre construireArbre(Noeud noeud, Foret foret); /* fait */
int rechercherSousArbre(Arbre arbre);
Foret insererArbre(Foret foret, int i, Arbre arbre); /* fait */


#endif
