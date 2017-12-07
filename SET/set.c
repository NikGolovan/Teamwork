#include <stdio.h>
#include <stdlib.h>
#include "set.h"

/*
  initialisation du set
  @params: aucun
  retourne: le set
*/
SET setVide() {
  SET set;
  set = NULL;
  return(set);
}
/*
  vérification si le set est vide. Retourne 1 si VRAI et 0 sinon
  @params: fa fonction prend le set en paramètre
  retourne: soit 1 (vrai) soit 0 (faux) si le set est vide
*/
int estVide(SET set) {
  return(set == NULL);
}
/*
  vérification si un élément est appartient à set en utilisant le parcours
  @params: fa fonction prend le set en paramètre et un untier qui
  correspond à l'élément à comparer
  retourne: soit 1 (vrai) soit 0 (faux) si élément existe déjà dans le set
*/
int appartient(SET set, int element) {
  Cellule *iter = set;
  int elementExiste = 0;

  while (iter != NULL) {
    if (iter->element == element)
      return 1;
    iter = iter->suivant;
  }
  return 0;
}
/*
  ajout d'un élémenet dans le set
  @params: fa fonction prend le pointeur du set en paramètre et un untier qui
  correspond à l'élément
  retourne: rien
*/
void ajouter(SET *set, int element) {
  SET tmp;

  tmp = malloc(sizeof(Cellule)); /* allocation de la mémoire dynamiquement pour le set */

  if(tmp == NULL) {
    printf("Erreur d'allocation mémoire\n");
    exit(-1);
  }

  tmp->element = element;
  tmp->suivant = *set;
  *set = tmp;

  printf("L'élément %d a été bien ajouté dans le set.\n", element);
}
/*
  affiche les tous éléments du set en utilisant le parcours
  @params: fa fonction prend le set en paramètre
  retourne: rien
*/
void afficherElements(SET set) {
  Cellule *iter = set;
  int nombreElt = 0; /* compte le nombre d'éléments dans le set */

  printf("Les éléments du set sont : ");
  while (iter != NULL) {
    printf("%d ", iter->element);
    iter = iter->suivant;
    nombreElt++;
  }
  printf("\n");
  if (nombreElt > 1)
    printf("Il y a %d éléments dans le set au total.\n", nombreElt);
  else
    printf("Il y a %d élément dans le set au total.\n", nombreElt);
}
/*
  suppression d'un élément du set en utilisant le parcours
  @params: fa fonction prend le pointeur du set en paramètre et un untier qui
  correspond à l'élément à supprimmer
  retourne: rien
*/
void enlever(SET *set, int valeur) {
  Cellule *positionActuelle, *positionAvant;

  /* Pour le premiere noeud, nous disons qu'il n'y a pas d'élément avant */
  positionAvant = NULL;

 /* Le parcours du SET */
 for (positionActuelle = *set;
   positionActuelle != NULL;
   positionAvant = positionActuelle, positionActuelle = positionActuelle->suivant) {

  if (positionActuelle->element == valeur) {  /* si l'élément a été trouvé */
    if (positionAvant == NULL) {
      /* Nous mettons à jours le pointeur */
      *set = positionActuelle->suivant;
    } else {
      /* Nous mettons à jours la position du pointeur */
      positionAvant->suivant = positionActuelle->suivant;
    }
    /* La liberation de la mémoire */
    free(positionActuelle);

    printf("L'élément a été bien supprimé du set.\n");

    /* Arrêt l'execution de la fonction */
    return;
  } else {
    printf("L'élément %d pour la suppression n'a pas été trouvé.\n", valeur);
    /* Arrêt l'execution de la fonction */
    return;
    }
  }
}
