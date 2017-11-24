#ifndef ALERTE_H
#define ALERTE_H
#include <stdio.h>

#define TAILLE_INITIALE_DE_MALLOC_ALERTE 3
#define TAILLE_BUFFER 150
#define TAILLE_BUFFER_RETOUR 30
#define NOM_DE_FICHIER_ALERTES "alertes.txt"

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
void alertesStatiques(Alerte **alerte, int *iCompteurAlerte);
void imprimerLesAlertes(Alerte **alerte, int *iCompteurAlerte);
void chargerLesAlertes(Alerte **alerte, int *iCompteurAlerte);

#endif
