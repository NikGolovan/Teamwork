#ifndef UNITE_H
#define UNITE_H
#include <stdio.h>

#define TAILLE_INITIALE_DE_MALLOC_UNITE 3
#define UNITE_EN_REPOS "Disponibilité : EN REPOS"
#define NOM_DE_FICHIER_UNITES "unites.txt"
#define TAILLE_DE_CODE_GENERE_50002 50002
#define CHOIX_MAX_MOYEN_DEPLACEMENT 3
#define CHOIX_MAX_NIVEAU_DISPONIBILITE 3
#define CHOIX_MAX_STATUT_UNITE 3

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
int genererCodeUnite();
void mettreUniteEnRepos(Unites **unite, int *iCompteurUnite);
void unitesStatiques(Unites **unite, int *iCompteurUnite);
void consulterUnitesDeployees(Unites **unite, int *iCompteurUnite);
void imprimerLesUnites(Unites **unite, int *iCompteurUnite);
void chargerLesUnites(Unites **unite, int *iCompteurUnite);

#endif
