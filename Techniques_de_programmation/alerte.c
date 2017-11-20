#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "alerte.h"

int genererCodeAlerte(/* Alerte **alerte, int *iCompteurAlerte */) {
  int iNombreGenere = 0;
  //int iExisteAlerte = 0;
  // int i = 0;

  iNombreGenere = rand() % 50001;

  /* do {
    nombreGenere = rand() % 3;
    for (i = 0; i < (*iCompteurAlerte); i++) {
      if (nombreGenere == (*alerte)[i].iCode) {
        existeAlerte = 1;
      }
    }
  }while (existeAlerte); */

  return iNombreGenere;
}

char * niveauAlerte() {
  char *cPtrNiveau = NULL;
  int iChoix = 0;

  cPtrNiveau = malloc(TAILLE_BUFFER_RETOUR * sizeof(char));

  if (cPtrNiveau == NULL) {
    printf("Erreur d'allocation memoire pour le niveau d'alerte\n");
    exit(EXIT_FAILURE);
  }

  do {
    printf("╔════════════════════════════════════════╗\n");
    printf("║                                        ║\n");
    printf("║                 NIVEAU                 ║\n");
    printf("║                                        ║\n");
    printf("╠════╦═══════════════════════════════════╣\n");
    printf("║    ║                                   ║\n");
    printf("║ 1  ║ NOMINAL                           ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 2  ║ URGENT                            ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 3  ║ URGENCE ABSOLUE                   ║\n");
    printf("║    ║                                   ║\n");
    printf("╚════╩═══════════════════════════════════╝\n");

    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        cPtrNiveau = "NOMINAL\n";
        break;
      case 2:
        cPtrNiveau = "URGENT\n";
        break;
        case 3:
        cPtrNiveau = "URGENCE ABSOLUE\n";
        break;
        default:
        printf("La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > 3);

  return cPtrNiveau;
}

char * typeAlerte() {
  char *cPtrType = NULL;
  int iChoix = 0;

  cPtrType = malloc(TAILLE_BUFFER_RETOUR * sizeof(char));

  if (cPtrType == NULL) {
    printf("Erreur d'allocation memoire pour le type d'alerte\n");
    exit(EXIT_FAILURE);
  }

  do {
    printf("╔════════════════════════════════════════╗\n");
    printf("║                                        ║\n");
    printf("║                  TYPE                  ║\n");
    printf("║                                        ║\n");
    printf("╠════╦═══════════════════════════════════╣\n");
    printf("║    ║                                   ║\n");
    printf("║ 1  ║ INCENDIE                          ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 2  ║ ACCIDENT DE LA ROUTE              ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 3  ║ ACCIDENT EN MER                   ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 4  ║ ACCIDENT EN MONTAGNE              ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 5  ║ MALAISE                           ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 6  ║ EXPLOSION                         ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 7  ║ ACCIDENT DE LA VIE                ║\n");
    printf("║    ║                                   ║\n");
    printf("╚════╩═══════════════════════════════════╝\n");


    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        cPtrType = "INCENDIE\n";
        break;
      case 2:
        cPtrType = "ACCIDENT ROUTE\n";
        break;
      case 3:
        cPtrType = "ACCIDENT MER\n";
        break;
      case 4:
        cPtrType = "ACCIDENT MONTAGNE\n";
        break;
      case 5:
        cPtrType = "MALAISE\n";
        break;
      case 6:
        cPtrType = "EXPLOSION\n";
        break;
      case 7:
        cPtrType = "ACCIDENT DE LA VIE\n";
        break;
      default:
        printf("La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > 7);

  return(cPtrType);
}

void ajouterAlerte(Alerte **alerte, int *iCompteurAlerte) {
  char sBuffer[TAILLE_BUFFER];
  int iTmpNombre = 0;
  char *cPtrType = NULL;
  char *cPtrNiveau = NULL;
  int i;

  i = *iCompteurAlerte;

  iTmpNombre = genererCodeAlerte();
  (*alerte)[i].iCode = iTmpNombre;

  printf("Type d'alerte :\n");
  cPtrType = typeAlerte();
  strcpy((*alerte)[i].cType, cPtrType);

  printf("Niveau d'alerte :\n");
  cPtrNiveau = niveauAlerte();
  strcpy((*alerte)[i].cNiveau, cPtrNiveau);

  printf("Lieu :\n");
  fgets(sBuffer, TAILLE_BUFFER, stdin);
  strcpy((*alerte)[i].cLieu, sBuffer);

  printf("Nombre de victimes :\n");
  scanf("%d%*c", &iTmpNombre);
  (*alerte)[i].iNombreVictimes = iTmpNombre;

  printf("Description :\n");
  fgets(sBuffer, TAILLE_BUFFER, stdin);
  strcpy((*alerte)[i].cDescription, sBuffer);

  (*alerte)[i].iEstTraiteParUnite = 0;
  (*alerte)[i].iCodeUniteQuiTraite = 0;

  printf("Alerte a été bien crée avec le code suivant : %d\n", (*alerte)[i].iCode);
}

void afficherToutesAlertes(Alerte **alerte, int *iCompteurAlerte) {
  int i = 0;

   if (*iCompteurAlerte == 0) {
    printf("Aucune alerte n'a été enregistrée\n");
    return;
  }

   for (i = 0; i < *iCompteurAlerte; i++) {
    printf("\n");
    printf("Code d'alerte : %d\n", (*alerte)[i].iCode);
    printf("Type d'alerte : %s", (*alerte)[i].cType);
    printf("Niveau d'alerte : %s", (*alerte)[i].cNiveau);
    printf("Lieu : %s", (*alerte)[i].cLieu);
    printf("Nombre de victimes : %d\n", (*alerte)[i].iNombreVictimes);
    printf("Description : %s", (*alerte)[i].cDescription);
    //printf("Alerte est traitée par une unité : ");
    //((*alerte)[i].iEstTraiteParUnite) == 0 ? printf("NON\n") : printf("OUI\n");
    printf("Les unités deployés : %d\n", (*alerte)[i].iCodeUniteQuiTraite);
  }
}

void afficherUneAlerte(Alerte **alerte, int *iCompteurAlerte) {
  int i = 0;
  int iCodeDonne = 0;
  int existeAlerte = 0;

  if (*iCompteurAlerte == 0) {
    printf("Aucune alerte n'a été enregistrée\n");
    return;
  }

  printf("Donnez le code d'alerte :\n");
  scanf("%d%*c", &iCodeDonne);

  for (i = 0; i < (*iCompteurAlerte); i++) {
    if (iCodeDonne == (*alerte)[i].iCode) {
      printf("\n");
      printf("Code d'alerte : %d\n", (*alerte)[i].iCode);
      printf("Type d'alerte : %s", (*alerte)[i].cType);
      printf("Niveau d'alerte : %s", (*alerte)[i].cNiveau);
      printf("Lieu : %s", (*alerte)[i].cLieu);
      printf("Nombre de victimes : %d\n", (*alerte)[i].iNombreVictimes);
      printf("Description : %s", (*alerte)[i].cDescription);
      //printf("Alerte est traitée par une unité : %d", (*alerte)[i].iNombreVictimes);
      //((*alerte)[i].iNombreVictimes) == 0 ? printf("NON\n") : printf("OUI\n");
      printf("Les unités deployés : %d", (*alerte)[i].iCodeUniteQuiTraite);
      existeAlerte = 1;
    }
  }
  if (!existeAlerte)
    printf("Alerte avec le code %d n'a pas été trouvée.\n", iCodeDonne);
}

void modifierAlerte(Alerte **alerte, int *iCompteurAlerte) {
  int i = 0;
  int iExisteAlerte = 0;
  char *cPtrType = NULL;
  char *cPtrNiveau = NULL;
  int iCodeDonne = 0;
  char sBuffer[TAILLE_BUFFER];
  int iTmpNombre = 0;

   if (*iCompteurAlerte == 0) {
    printf("Aucune alerte n'a été enregistrée\n");
    return;
  }

  printf("Donnez le code d'alerte :\n");
  scanf("%d%*c", &iCodeDonne);

   for (i = 0; i < *iCompteurAlerte; i++) {
    if (iCodeDonne == (*alerte)[i].iCode) {
      printf("Code d'alerte à modifier: %d\n", (*alerte)[i].iCode);

      printf("Type d'alerte :\n");
      cPtrType = typeAlerte();
      strcpy((*alerte)[i].cType, cPtrType);

      printf("Niveau d'alerte :\n");
      cPtrNiveau = niveauAlerte();
      strcpy((*alerte)[i].cNiveau, cPtrNiveau);

      printf("Lieu :\n");
      fgets(sBuffer, TAILLE_BUFFER, stdin);
      strcpy((*alerte)[i].cLieu, sBuffer);

      printf("Nombre de victimes :\n");
      scanf("%d%*c", &iTmpNombre);
      (*alerte)[i].iNombreVictimes = iTmpNombre;

      printf("Description :\n");
      fgets(sBuffer, TAILLE_BUFFER, stdin);
      strcpy((*alerte)[i].cDescription, sBuffer);

      iExisteAlerte = 1;
    }
  }
  if (!iExisteAlerte) {
    printf("Alerte avec le code %d n'a pas été trouvée.\n", iCodeDonne);
  } else {
    printf("Alerte avec le code %d a été bien modifiée.\n", iCodeDonne);
  }
}

void supprimerAlerte(Alerte **alerte, int *iCompteurAlerte) {
  int iCodeDonne = 0;
  int i = 0;
  int j = 0;
  int iNouvelleTaille = 0;

  if (*iCompteurAlerte == 0) {
   printf("Aucune alerte n'a été enregistrée\n");
   return;
  }

  printf("Donnez le code d'alerte pour la suppression :\n");
  scanf("%d%*c", &iCodeDonne);

  while (i < *iCompteurAlerte && iCodeDonne != (*alerte)[i].iCode) {
    i++;
  }

  if (i == *iCompteurAlerte) {
    printf("alerte n'a pas été trouvée.\n");
    return;
  } else {
    for (j = i; j < (*iCompteurAlerte); j++) {
        (*alerte)[j].iCode = (*alerte)[j+1].iCode;
        strcpy((*alerte)[j].cType, (*alerte)[j+1].cType);
        strcpy((*alerte)[j].cNiveau, (*alerte)[j+1].cNiveau);
        strcpy((*alerte)[j].cLieu, (*alerte)[j+1].cLieu);
        (*alerte)[j].iNombreVictimes = (*alerte)[j+1].iNombreVictimes;
        strcpy((*alerte)[j].cDescription, (*alerte)[j+1].cDescription);
    }
  }

  (*iCompteurAlerte)--;

  iNouvelleTaille = *iCompteurAlerte;

  *alerte = realloc(*alerte, ((TAILLE_INITIALE_DE_MALLOC_ALERTE+iNouvelleTaille) * sizeof(Alerte)));

  if (*alerte == NULL && *iCompteurAlerte > 0) {
    printf("Erreur de reallocation memoire après la suppression.\n");
    exit(EXIT_FAILURE);
  }

  printf("DEBUG: La mémoire a été realouée après la suppression\n");

  printf("Alerte avec le code %d a été bien supprimé\n", iCodeDonne);
}

void menuTraitementAlerte() {
  printf("╔════════════════════════════════════════╗\n");
  printf("║                                        ║\n");
  printf("║        TRAITEMENT D'UNE ALERTE         ║\n");
  printf("║                                        ║\n");
  printf("╠════╦═══════════════════════════════════╣\n");
  printf("║    ║                                   ║\n");
  printf("║ 1  ║ Afficher une alerte               ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 2  ║ Modifier une alerte               ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 3  ║ Afficher toutes les alertes       ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 4  ║ Supprimer une alerte              ║\n");
  printf("║    ║                                   ║\n");
  printf("╠════╬═══════════════════════════════════╣\n");
  printf("║ -2 ║ Retourner                         ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}

/*  LES UNITES */

void menuTraitementUnite() {
  printf("╔════════════════════════════════════════╗\n");
  printf("║                                        ║\n");
  printf("║            GESTION DES UNITES          ║\n");
  printf("║                                        ║\n");
  printf("╠════╦═══════════════════════════════════╣\n");
  printf("║    ║                                   ║\n");
  printf("║ 1  ║ Afficher une unité                ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 2  ║ Afficher toutes les unités        ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 3  ║ Modifier une unité                ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 4  ║ Supprimer une unité               ║\n");
  printf("║    ║                                   ║\n");
  printf("╠════╬═══════════════════════════════════╣\n");
  printf("║ -2 ║ Retourner                         ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}

int genererCodeUnite() {
  int iNombreGenere = 0;

  iNombreGenere = rand() % 50002 + 50001;

  return iNombreGenere;
}

char * moyenDeplacement() {
  char *ptrMoyenDeplacement = NULL;
  int iChoix = 0;

  ptrMoyenDeplacement = malloc(TAILLE_BUFFER_RETOUR * sizeof(char));

  if (moyenDeplacement == NULL) {
    printf("Erreur d'allocation memoire pour le moyen de deplacement\n");
    exit(EXIT_FAILURE);
  }

  do {
    printf("╔════════════════════════════════════════╗\n");
    printf("║                                        ║\n");
    printf("║          MOYEN DE DEPLACEMENT          ║\n");
    printf("║                                        ║\n");
    printf("╠════╦═══════════════════════════════════╣\n");
    printf("║    ║                                   ║\n");
    printf("║ 1  ║ ROUTE                             ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 2  ║ AIR                               ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 3  ║ MER                               ║\n");
    printf("║    ║                                   ║\n");
    printf("╚════╩═══════════════════════════════════╝\n");

    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        ptrMoyenDeplacement = "ROUTE\n";
        break;
      case 2:
        ptrMoyenDeplacement = "AIR\n";
        break;
        case 3:
        ptrMoyenDeplacement = "MER\n";
        break;
        default:
        printf("La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > 3);

  return ptrMoyenDeplacement;
}

char * niveauDisponibilite() {
  char *cPtrNiveauDisponibilite = NULL;
  int iChoix = 0;

  cPtrNiveauDisponibilite = malloc(TAILLE_BUFFER_RETOUR * sizeof(char));

  if (cPtrNiveauDisponibilite == NULL) {
    printf("Erreur d'allocation memoire pour le niveau de dispinibilite\n");
    exit(EXIT_FAILURE);
  }

  do {
    printf("╔════════════════════════════════════════╗\n");
    printf("║                                        ║\n");
    printf("║         NIVEAU DE DISPONIBILITE        ║\n");
    printf("║                                        ║\n");
    printf("╠════╦═══════════════════════════════════╣\n");
    printf("║    ║                                   ║\n");
    printf("║ 1  ║ ACTIVITE                          ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 2  ║ EN REPOS                          ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 3  ║ EN REAPROVISIONNEMENT             ║\n");
    printf("║    ║                                   ║\n");
    printf("╚════╩═══════════════════════════════════╝\n");

    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        cPtrNiveauDisponibilite = "ACTIVE\n";
        break;
      case 2:
        cPtrNiveauDisponibilite = "EN REPOS\n";
        break;
        case 3:
        cPtrNiveauDisponibilite = "EN REAPPROVISIONNEMENT\n";
        break;
        default:
        printf("La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > 3);

  return cPtrNiveauDisponibilite;
}

char * statutUnite() {
  char *cPtrStatutUnite = NULL;
  int iChoix = 0;

  cPtrStatutUnite  = malloc(TAILLE_BUFFER_RETOUR * sizeof(char));

  if (cPtrStatutUnite  == NULL) {
    printf("Erreur d'allocation memoire pour le statu unite\n");
    exit(EXIT_FAILURE);
  }

  do {
    printf("╔════════════════════════════════════════╗\n");
    printf("║                                        ║\n");
    printf("║                 STATUT                 ║\n");
    printf("║                                        ║\n");
    printf("╠════╦═══════════════════════════════════╣\n");
    printf("║    ║                                   ║\n");
    printf("║ 1  ║ EN ALERTE                         ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 2  ║ EN ROUTE                          ║\n");
    printf("║    ║                                   ║\n");
    printf("║ 3  ║ SUR OPERATION                     ║\n");
    printf("║    ║                                   ║\n");
    printf("╚════╩═══════════════════════════════════╝\n");

    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        cPtrStatutUnite  = "EN ALERTE\n";
        break;
      case 2:
        cPtrStatutUnite  = "EN ROUTE\n";
        break;
      case 3:
        cPtrStatutUnite  = "SUR OPERATION\n";
        break;
      default:
        printf("La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > 3);

  return cPtrStatutUnite ;
}

void creerUnite(Unites **unite, int *iCompteurUnite) {
  char sBuffer[TAILLE_BUFFER];
  int iTmpNombre = 0;
  char *cPtrStatutUnite = NULL;
  char *cPtrMoyenDeplacement = NULL;
  char *cPtrNiveauDisponibilite = NULL;
  int i;

  i = *iCompteurUnite;

  iTmpNombre = genererCodeUnite();
  (*unite)[i].iCode = iTmpNombre;

  printf("Nom d'unité :\n");
  fgets(sBuffer, TAILLE_BUFFER, stdin);
  strcpy((*unite)[i].cNom, sBuffer);

  printf("Moyen de deplacement :\n");
  cPtrMoyenDeplacement = moyenDeplacement();
  strcpy((*unite)[i].cMoyenDeplacement, cPtrMoyenDeplacement);

  printf("Niveau de disponibilité :\n");
  cPtrNiveauDisponibilite = niveauDisponibilite();
  strcpy((*unite)[i].cNiveauDisponibilite, cPtrNiveauDisponibilite);

  printf("Statut :\n");
  cPtrStatutUnite = statutUnite();
  strcpy((*unite)[i].cStatut, cPtrStatutUnite);

  printf("Base :\n");
  fgets(sBuffer, TAILLE_BUFFER, stdin);
  strcpy((*unite)[i].cBase, sBuffer);
  
  (*unite)[i].iUniteDisponible = 1;
  (*unite)[i].iDeployeeSurAlerte = 0;
  
  printf("Unité a été bien crée avec le code suivant : %d\n", (*unite)[i].iCode);
}

void afficherUneUnite(Unites **unite, int *iCompteurUnite) {
  int i = 0;
  int iCodeDonne = 0;
  int iExisteUnite = 0;

  if (*iCompteurUnite == 0) {
    printf("Aucune unité n'a été enregistrée\n");
    return;
  }

  printf("Donnez le code d'unité :\n");
  scanf("%d%*c", &iCodeDonne);

  for (i = 0; i < (*iCompteurUnite); i++) {
    if (iCodeDonne == (*unite)[i].iCode) {
      printf("\n");
      printf("Code d'unité : %d\n", (*unite)[i].iCode);
      printf("Nom d'unité : %s", (*unite)[i].cNom);
      printf("Moyen de deplacement : %s", (*unite)[i].cMoyenDeplacement);
      printf("Disponibilité : %s", (*unite)[i].cNiveauDisponibilite);
      printf("Satut : %s\n", (*unite)[i].cStatut);
      printf("Base : %s", (*unite)[i].cBase);
      printf("Deployée sur les alertes : %d\n", (*unite)[i].iDeployeeSurAlerte);
      iExisteUnite = 1;
    }
  }
  if (!iExisteUnite)
    printf("Unité avec le code %d n'a pas été trouvée.\n", iCodeDonne);
}

void afficherToutesUnites(Unites **unite, int *iCompteurUnite) {
  int i = 0;

   if (*iCompteurUnite == 0) {
    printf("Aucune alerte n'a été enregistrée\n");
    return;
  }

   for (i = 0; i < *iCompteurUnite; i++) {
    printf("\n");
    printf("Code d'unité : %d\n", (*unite)[i].iCode);
    printf("Nom d'unité : %s", (*unite)[i].cNom);
    printf("Moyen de deplacement : %s", (*unite)[i].cMoyenDeplacement);
    printf("Disponibilité : %s", (*unite)[i].cNiveauDisponibilite);
    printf("Statut : %s", (*unite)[i].cStatut);
    printf("Base : %s", (*unite)[i].cBase);
    printf("Deployée sur les alertes : %d\n", (*unite)[i].iDeployeeSurAlerte);
  }
}

void modifierUnite(Unites **unite, int *iCompteurUnite) {
  int i = 0;
  int iExisteUnite = 0;
  char *cPtrStatutUnite = NULL;
  char *cPtrMoyenDeplacement = NULL;
  char *cPtrNiveauDisponibilite = NULL;
  char sBuffer[TAILLE_BUFFER];
  int iCodeDonne = 0;
  int iTmpNombre = 0;

   if (*iCompteurUnite == 0) {
    printf("Aucune unité n'a été enregistrée\n");
    return;
  }

  printf("Donnez le code d'unité :\n");
  scanf("%d%*c", &iCodeDonne);

   for (i = 0; i < *iCompteurUnite; i++) {
    if (iCodeDonne == (*unite)[i].iCode) {
      printf("Code d'unité à modifier: %d\n", (*unite)[i].iCode);

      printf("Nom d'unité :\n");
      fgets(sBuffer, TAILLE_BUFFER, stdin);
      strcpy((*unite)[i].cNom, sBuffer);

      printf("Moyen de deplacement :\n");
      cPtrMoyenDeplacement = moyenDeplacement();
      strcpy((*unite)[i].cMoyenDeplacement, cPtrMoyenDeplacement);

      printf("Disponibilité :\n");
      cPtrNiveauDisponibilite = niveauDisponibilite();
      strcpy((*unite)[i].cNiveauDisponibilite, cPtrNiveauDisponibilite);

      printf("Statut :\n");
      cPtrStatutUnite = statutUnite();
      strcpy((*unite)[i].cStatut, cPtrStatutUnite);

      printf("Base :\n");
      fgets(sBuffer, TAILLE_BUFFER, stdin);
      strcpy((*unite)[i].cBase, sBuffer);

      iExisteUnite = 1;
    }
  }
  if (!iExisteUnite) {
    printf("Unité avec le code %d n'a pas été trouvée.\n", iCodeDonne);
  } else {
    printf("Unité avec le code %d a été bien modifiée.\n", iCodeDonne);
  }
}

void supprimerUnite(Unites **unite, int *iCompteurUnite) {
  int iCodeDonne = 0;
  int i = 0;
  int j = 0;
  int iNouvelleTaille = 0;

  if (*iCompteurUnite == 0) {
   printf("Aucune unité n'a été enregistrée\n");
   return;
  }

  printf("Donnez le code d'unité pour la suppression :\n");
  scanf("%d%*c", &iCodeDonne);

  while (i < *iCompteurUnite && iCodeDonne != (*unite)[i].iCode) {
    i++;
  }

  if (i == *iCompteurUnite) {
    printf("Unité n'a pas été trouvée.\n");
    return;
  } else {
    for (j = i; j < (*iCompteurUnite); j++) {
        (*unite)[j].iCode = (*unite)[j+1].iCode;
        strcpy((*unite)[j].cNom, (*unite)[j+1].cNom);
        strcpy((*unite)[j].cMoyenDeplacement, (*unite)[j+1].cMoyenDeplacement);
        strcpy((*unite)[j].cNiveauDisponibilite, (*unite)[j+1].cNiveauDisponibilite);
        strcpy((*unite)[j].cStatut, (*unite)[j+1].cStatut);
        strcpy((*unite)[j].cBase, (*unite)[j+1].cBase);
    }
  }

  (*iCompteurUnite)--;

  iNouvelleTaille = *iCompteurUnite;

  *unite = realloc(*unite, ((TAILLE_INITIALE_DE_MALLOC_UNITE+iNouvelleTaille) * sizeof(Unites)));

  if (*unite == NULL && *iCompteurUnite > 0) {
    printf("Erreur de reallocation memoire après la suppression.\n");
    exit(EXIT_FAILURE);
  }

  printf("DEBUG: La mémoire a été realouée après la suppression\n");

  printf("Unité avec le code %d a été bien supprimé\n", iCodeDonne);
}

void declancherAlerte(Alerte **alerte, Unites **unite, int *iCompteurAlerte, int *iCompteurUnite) {
  int i = 0;
  int iCodeDonneAlerte = 0;
  int iCodeDonneUnite = 0;
  int iTmpPositionAlerte = 0;
  int iTmpPositionUnite = 0;
  int iBoucleCompteurAlerte = 0;
  int iBoucleCompteurUnite = 0;
  int iChoix = 0;

  if (*iCompteurAlerte == 0) {
    printf("Aucune alerte n'a pas été enregistrée\n");
    return;
  }

  printf("Les alertes non traitées :\n");
  for (i = 0; i < *iCompteurAlerte; i++) {
    if ((*alerte)[i].iEstTraiteParUnite == 1)
      continue;
    printf("\n");
    printf("Code d'alerte : %d\n", (*alerte)[i].iCode);
    printf("Type d'alerte : %s", (*alerte)[i].cType);
    printf("Niveau d'alerte : %s", (*alerte)[i].cNiveau);
    printf("Lieu : %s", (*alerte)[i].cLieu);
    printf("Nombre de victimes : %d\n", (*alerte)[i].iNombreVictimes);
    printf("Description : %s", (*alerte)[i].cDescription);
    //printf("Alerte est traitée par une unité : ");
    //((*alerte)[i].iEstTraiteParUnite) == 0 ? printf("NON\n") : printf("OUI\n");
    printf("Les unités deployés : %d\n", (*alerte)[i].iCodeUniteQuiTraite);
    iBoucleCompteurAlerte++;
  }
  
  if (iBoucleCompteurAlerte == 0) {
    printf("Toutes les alertes sont traitées par les unités\n");
    return;
  }

  printf("\n\n");

  if (*iCompteurUnite == 0) {
    printf("Aucune unité n'a pas été enregistrée\n");
    return;
  }

  printf("Les unités disponibles :\n");
    for (i = 0; i < *iCompteurUnite; i++) {
      if ((*unite)[i].iUniteDisponible == 0)
        continue;
      printf("\n");
      printf("Code d'unité : %d\n", (*unite)[i].iCode);
      printf("Nom d'unité : %s", (*unite)[i].cNom);
      printf("Moyen de deplacement : %s", (*unite)[i].cMoyenDeplacement);
      printf("Disponibilité : %s", (*unite)[i].cNiveauDisponibilite);
      printf("Statut : %s", (*unite)[i].cStatut);
      printf("Base : %s", (*unite)[i].cBase);
      printf("Deployée sur les alertes : %d\n", (*unite)[i].iDeployeeSurAlerte);
      iBoucleCompteurUnite++;
  }

  if (iBoucleCompteurUnite == 0) {
    printf("Toutes les unités sont occuppées.\n");
    printf("CAS DE FORCE MAJEUR\n");
    printf("1. Faire intervenir les unités en repos ou -2 pour retourner\n");
    scanf("%d%*c", &iChoix);
    
    do {
      switch(iChoix) {
        case 1:
          for (i = 0; i < *iCompteurUnite; i++) {
            if ((*unite)[i].iEstEnRepos == 1) {
              printf("\n");
              printf("Code d'unité : %d\n", (*unite)[i].iCode);
              printf("Nom d'unité : %s", (*unite)[i].cNom);
              printf("Moyen de deplacement : %s", (*unite)[i].cMoyenDeplacement);
              printf("Disponibilité : %s", (*unite)[i].cNiveauDisponibilite);
              printf("Statut : %s", (*unite)[i].cStatut);
              printf("Base : %s", (*unite)[i].cBase);
              printf("Deployée sur les alertes : %d\n", (*unite)[i].iDeployeeSurAlerte);
            }
          }
          break;
        case -2:
          return;
          break;
        default:
          printf("La saisie n'est pas correcte.\n");
          break;
      }
  } while (iChoix != -2);
}

  printf("\n\n");
  
  printf("Donnez le code d'alerte :\n");
  scanf("%d%*c", &iCodeDonneAlerte);

  while (iTmpPositionAlerte < *iCompteurAlerte && iCodeDonneAlerte != (*alerte)[iTmpPositionAlerte].iCode) {
    iTmpPositionAlerte++;
  }
  
  if (iTmpPositionAlerte == *iCompteurAlerte) {
    printf("Alerte avec le code %d n'a pas été trouvée.\n", iCodeDonneAlerte);
    return;
  } 
  
  printf("Donnez code d'unité a envoyer : \n");
  scanf("%d%*c", &iCodeDonneUnite);

  while (iTmpPositionUnite < *iCompteurUnite && iCodeDonneUnite != (*unite)[iTmpPositionUnite].iCode) {
      iTmpPositionUnite++;
   }
  
  if (iTmpPositionUnite == *iCompteurUnite) {
    printf("Unité avec le code %d n'a pas été trouvée.\n", iCodeDonneUnite);
    return;
  } 
  (*alerte)[iTmpPositionAlerte].iCodeUniteQuiTraite = iCodeDonneUnite;
  (*alerte)[iTmpPositionAlerte].iEstTraiteParUnite = 1;
  (*unite)[iTmpPositionUnite].iDeployeeSurAlerte = iCodeDonneAlerte;
  (*unite)[iTmpPositionUnite].iUniteDisponible = 0;
}
