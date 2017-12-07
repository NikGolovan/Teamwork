#include <stdio.h>
#include "set.h"

int main() {
  SET set;

  set = setVide();
  printf("Le set a été bien initialisé et ");

  if (!estVide(set))
    printf("il n'est pas vide.\n");
  else
    printf("il est vide.\n");

  ajouter(&set, 5);

  afficherElements(set);

  if (!estVide(set))
    enlever(&set, 5);
  else
    printf("La suppression ne peut pas être effectuée car le SET est vide.\n");

  if (!estVide(set))
    afficherElements(set);
  else
    printf("Le set est vide.\n");

  ajouter(&set, 3);
  ajouter(&set, 8);

  if (!appartient(set, 3))
    ajouter(&set, 3);
  else
    printf("Element déjà existe dans le set. Veuillez insérer un autre.\n");

  if (!estVide(set))
    enlever(&set, 23);
  else
    printf("La suppression ne peut pas être effectuée car le SET est vide.\n");

  if (!estVide(set))
    afficherElements(set);
  else
    printf("Le set est vide.\n");

  return 0;
}
