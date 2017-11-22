#ifndef ALERTE_H
#define ALERTE_H
#include <stdio.h>

#define DESCRIPTION_TAILLE 150
#define TAILLE_INITIALE_DE_MALLOC_ALERTE 3
#define TAILLE_INITIALE_DE_MALLOC_UNITE 3
#define TAILLE_BUFFER 150
#define TAILLE_BUFFER_RETOUR 30

typedef struct {
  int iCode;
  char cType[TAILLE_BUFFER];
  char cNiveau[TAILLE_BUFFER];
  char cLieu[TAILLE_BUFFER];
  int iNombreVictimes;
  char cDescription[TAILLE_BUFFER];
  int iEstTraiteParUnite;
  int iCodeUniteQuiTraite;
} Alerte;

void ajouterAlerte(Alerte **alerte, int *compteurAlerte);
void afficherUneAlerte(Alerte **alerte, int *compteurAlerte);
void afficherToutesAlertes(Alerte **alerte, int *compteurAlerte);
void modifierAlerte(Alerte **alerte, int *compteurAlerte);
void supprimerAlerte(Alerte **alerte, int *compteurAlerte);
char * typeAlerte();
char * niveauAlerte();
int genererCodeAlerte(/*Alerte **alerte, int *compteurAlerte*/);
void menuTraitementAlerte();

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
void menuTraitementUnite();
void mettreUniteEnRepos(Unites **unite, int *iCompteurUnite);

void declancherAlerte(Alerte **alerte, Unites **unite, int *iCompteurAlerte, int *iCompteurUnite);

#endif
