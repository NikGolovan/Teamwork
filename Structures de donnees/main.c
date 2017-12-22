#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

int main(int argc, char const *argv[]) {
  Arbre arbre1, arbre2, arbre3, arbre4, arbre5;
  Noeud noeud1, noeud2;
  Foret foret;

  foret = NULL;

  noeud1.element = 25;
  noeud1.nb_sous_arbres = 0;
  //noeud1.fils = malloc(MAX * sizeof(Noeud));

  noeud2.element = 19;
  noeud2.nb_sous_arbres = 0;
  //noeud2.fils = malloc(MAX * sizeof(Noeud));

  arbre1 = NULL;
  if (estArbreVide(arbre1)) {
    printf("Initialisation ARBRE : OK\n");
  }

  if (estArbreVide(arbre1))
    printf("Arbre est vide.\n");
  else
    printf("La racine est : %d\n", racineArbre(arbre1).element);


  arbre1 = construireArbre(noeud1, foret);

  arbre3 = NULL;

  arbre4 = NULL;

  arbre5 = NULL;


// mettre noeud1 en racine et foret en sous-arbres

  noeud1.element = 45;
  noeud1.nb_sous_arbres = 0;

  foret = insererArbre(foret, 1, arbre1);

  arbre3 = construireArbre(noeud1, foret);

//idem

  noeud1.element = 13;
  noeud1.nb_sous_arbres = 0;

  foret = insererArbre(foret, 2, arbre3);

  arbre4 = construireArbre(noeud1, foret);

//idem

  noeud1.element = 8;
  noeud1.nb_sous_arbres = 0;

  foret = insererArbre(foret, 3, arbre4);

  arbre5 = construireArbre(noeud1, foret);

// verifier nb abres dans foret

  printf("coucou : %d\n", nombreArbres(foret));

  if (estArbreVide(arbre1))
    printf("Arbre est vide.\n");
  else
    printf("La racine arbre1 est : %d\n", racineArbre(arbre1).element);

  if (estArbreVide(arbre5))
    printf("Arbre est vide.\n");
  else
    printf("La racine arbre5 est : %d\n", racineArbre(arbre5).element);

// mettre tous les sous-arbres de arbre5 dans foret

  foret = listeSousArbres(arbre5);

  // verifier nb abres dans foret

  printf("coucou : %d\n", nombreArbres(foret));

// afficher le ieme arbre de foret

  printf("Racine arbre 3 = %d\n", racineArbre(iemeArbre(foret, 4)).element);


  return 0;
}
