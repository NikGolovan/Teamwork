#ifndef ALERTE_H
#define ALERTE_H
#include <stdio.h>

#define LIEU_TAILLE 150
#define DESCRIPTION_TAILLE 150
#define TAILLE_TYPE 21
#define TAILLE_NIVEAU 21
#define TAILLE_INITIALE_DE_MALLOC_ALERTE 3
#define TAILLE_INITIALE_DE_MALLOC_UNITE 3
#define TAILLE_BUFFER 150

#define TAILLE_MOYEN_DEPLACEMENT 21
#define TAILLE_NIVEAU_DISPONIBILITE 21
#define TAILLE_STATUT 21
#define TAILLE_BASE 50
#define TAILLE_NOM_UNITE 30

typedef struct {
  int iCode;
  char cType[TAILLE_TYPE];
  char cNiveau[TAILLE_NIVEAU];
  char cLieu[LIEU_TAILLE];
  int iNombreVictimes;
  char cDescription[DESCRIPTION_TAILLE];
} Alerte;

void ajouterAlerte(Alerte **alerte, int *compteurAlerte);
void afficherUneAlerte(Alerte **alerte, int *compteurAlerte);
void afficherToutesAlertes(Alerte **alerte, int *compteurAlerte);
void modifierAlerte(Alerte **alerte, int *compteurAlerte);
void supprimerAlerte(Alerte **alerte, int *compteurAlerte);
char * typeAlerte();
char * niveauAlerte();
int genererCodeAlerte(/*Alerte **alerte, int *compteurAlerte*/);

typedef struct {
  int iCode;
  char cNom[TAILLE_NOM_UNITE];
  char cMoyenDeplacement[TAILLE_MOYEN_DEPLACEMENT];
  char cNiveauDisponibilite[TAILLE_NIVEAU_DISPONIBILITE];
  char cStatut[TAILLE_STATUT];
  char cBase[TAILLE_BASE];
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

#endif
