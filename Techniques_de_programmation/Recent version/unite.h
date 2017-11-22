#ifndef UNITE_H
#define UNITE_H
#include <stdio.h>

#define TAILLE_INITIALE_DE_MALLOC_UNITE 3
#define TAILLE_INITIALE_DE_MALLOC_UNITE 3
#define TAILLE_BUFFER 150
#define TAILLE_BUFFER_RETOUR 30

typedef struct {
  int iCode;
  char cNom[TAILLE_BUFFER];
  char cMoyenDeplacement[TAILLE_BUFFER];
  char cNiveauDisponibilite[TAILLE_BUFFER];
  char cStatut[TAILLE_BUFFER];
  char cBase[TAILLE_BUFFER];
  int iCompteurRepos;
  int iEstEnRepos;
  int iUniteDisponible;
  int iDeployeeSurAlerte;
} Unites;

void creerUnite(Unites **unite, int *compteurUnite);
void afficherUneUnite(Unites **unite, int *compteurUnite);
void afficherToutesUnites(Unites **unite, int *compteurUnite);
void modifierUnite(Unites **unite, int *compteurUnite);
void supprimerUnite(Unites **unite, int *compteurUnite);
char * moyenDeplacement();
char * niveauDisponibilite();
char * statutUnite();
int genererCodeUnite(/*Unites **unite, int *compteurUnite*/);
void mettreUniteEnRepos(Unites **unite, int *iCompteurUnite);


#endif
