#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

int estArbreVide(Arbre arbre) {
  return(arbre == NULL);
}

int estForetVide(Foret foret) {
  return(foret == NULL);
}

Noeud racineArbre(Arbre arbre) {
  return(*arbre);
}

int nombreArbres(Foret foret) {
  int nombre = 0;

  while (foret != NULL) {
    foret = foret->suivant;
    nombre++;
  }
  return(nombre);
}

Arbre construireArbre(Noeud noeud, Foret foret) {
  Arbre arbre = NULL;
  Foret F = foret;
  int nombre, i;

  arbre = malloc(sizeof(Noeud));
  arbre->element = noeud.element;
  arbre->nb_sous_arbres = nombreArbres(foret);
  nombre = arbre->nb_sous_arbres;
  for (i = 1; i <= nombre; i++) {
    arbre->fils[i] = foret->un_arbre;
    foret = foret->suivant;
  }
  return(arbre);
}

/* void afficherForet(Foret foret) {
  int i = 0;
  if (!estForetVide(foret)) {
    printf("%d\n", racineArbre(foret->un_arbre));
    for (i = 0; i < nombreArbres(foret); i++) {
      afficherForet(foret->suivant);
    }
  }
} */

Arbre iemeArbre(Foret foret, int rang) {
  int i = 0;

  if (rang == 1) {
    return(foret->un_arbre);
  } else {
    for (i = 1; i < rang-1; i++) {
      foret = foret->suivant;
    }
    return(foret->un_arbre);
  }
}


Foret listeSousArbres(Arbre arbre) {
  Foret F, foret;
  int i, n;

  F = malloc(sizeof(Tree));
  n = arbre->nb_sous_arbres;
  if (n == 0)
    F = NULL;
  else {
    foret = F;
    for (i = 1; i <= n; i++) {
      foret->un_arbre = arbre->fils[i];
      foret->suivant = malloc(sizeof(Tree));
      foret = foret->suivant;
    }
    foret = NULL;
  }
  return F;
}


Foret insererArbre(Foret foret, int i, Arbre arbre) {
  int k;
  Foret la_premiere, la_nouvelle, actuelle, la_precedente;

  if (i == 1) {
    la_premiere = malloc(sizeof(Foret));
    la_premiere->un_arbre = arbre;
    la_premiere->position = 1;
    la_premiere->suivant = foret;
    foret = la_premiere;
  } else {
    actuelle = foret;
    for (k = 0; k < i-1; k++) {
      la_precedente = actuelle;
      actuelle = actuelle->suivant;
    }
    la_nouvelle = malloc(sizeof(Foret));
    la_precedente->suivant = la_nouvelle;
    la_nouvelle->un_arbre = arbre;
    la_nouvelle->suivant = actuelle;
  }
  return foret;
}


int rechercherSousArbre(Arbre arbre) {


}
