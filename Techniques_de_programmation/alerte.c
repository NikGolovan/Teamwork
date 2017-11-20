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

  cPtrNiveau = malloc(TAILLE_INITIALE_DE_MALLOC_ALERTE * sizeof(char));

  if (cPtrNiveau == NULL) {
    printf("Erreur d'allocation memoire pour le niveau d'alerte\n");
    exit(EXIT_FAILURE);
  }

  do {
    printf("╔═══════════════════════════════════╗\n");
    printf("║                                   ║\n");
    printf("║           NIVEAU ALERTE           ║\n");
    printf("║                                   ║\n");
    printf("╠════╦══════════════════════════════╣\n");
    printf("║    ║                              ║\n");
    printf("║ 1  ║ NOMINAL                      ║\n");
    printf("║    ║                              ║\n");
    printf("║ 2  ║ URGENT                       ║\n");
    printf("║    ║                              ║\n");
    printf("║ 3  ║ URGENCE ABSOLUE              ║\n");
    printf("║    ║                              ║\n");
    printf("╚════╩══════════════════════════════╝\n");

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

  cPtrType = malloc(TAILLE_INITIALE_DE_MALLOC_ALERTE * sizeof(char));

  if (cPtrType == NULL) {
    printf("Erreur d'allocation memoire pour le type d'alerte\n");
    exit(EXIT_FAILURE);
  }

  do {
    printf("╔═══════════════════════════════════╗\n");
    printf("║                                   ║\n");
    printf("║            TYPE ALERTE            ║\n");
    printf("║                                   ║\n");
    printf("╠════╦══════════════════════════════╣\n");
    printf("║    ║                              ║\n");
    printf("║ 1  ║ INCENDIE                     ║\n");
    printf("║    ║                              ║\n");
    printf("║ 2  ║ ACCIDENT DE LA ROUTE         ║\n");
    printf("║    ║                              ║\n");
    printf("║ 3  ║ ACCIDENT EN MER              ║\n");
    printf("║    ║                              ║\n");
    printf("║ 4  ║ ACCIDENT EN MONTAGNE         ║\n");
    printf("║    ║                              ║\n");
    printf("║ 5  ║ MALAISE                      ║\n");
    printf("║    ║                              ║\n");
    printf("║ 6  ║ EXPLOSION                    ║\n");
    printf("║    ║                              ║\n");
    printf("║ 7  ║ ACCIDENT DE LA VIE           ║\n");
    printf("║    ║                              ║\n");
    printf("╚════╩══════════════════════════════╝\n");


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

  printf("Code d'alerte :\n");
  //scanf("%d%*c", &tmpNombre);
  iTmpNombre = genererCodeAlerte();
  (*alerte)[i].iCode = iTmpNombre;

  printf("Type d'alerte :\n");
  //fgets(tmpChaine, LIEU_TAILLE, stdin);
  //scanf("%s%*c", tmpChaine);
  cPtrType = typeAlerte();
  strcpy((*alerte)[i].cType, cPtrType);

  printf("Niveau d'alerte :\n");
  //fgets(tmpChaine, LIEU_TAILLE, stdin);
  //scanf("%s%*c", tmpChaine);
  cPtrNiveau = niveauAlerte();
  strcpy((*alerte)[i].cNiveau, cPtrNiveau);

  printf("Lieu :\n");
  fgets(sBuffer, TAILLE_BUFFER, stdin);
  //scanf("%s%*c", tmpChaine);
  strcpy((*alerte)[i].cLieu, sBuffer);

  printf("Nombre de victimes :\n");
  scanf("%d%*c", &iTmpNombre);
  (*alerte)[i].iNombreVictimes = iTmpNombre;

  printf("Description :\n");
  fgets(sBuffer, TAILLE_BUFFER, stdin);
  //scanf("%s%*c", tmpChaine);
  strcpy((*alerte)[i].cDescription, sBuffer);

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
    printf("DEBUG: i = %d\n", i);
    //scanf("%*c");
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

  *alerte = realloc(*alerte, (*iCompteurAlerte * sizeof(Alerte)));

  if (*alerte == NULL && *iCompteurAlerte > 0) {
    printf("Erreur de reallocation memoire après la suppression.\n");
    exit(EXIT_FAILURE);
  }

  printf("DEBUG: La mémoire a été realouée après la suppression\n");

  printf("Alerte avec le code %d a été bien supprimé\n", iCodeDonne);
}

/*  LES UNITES */

int genererCodeUnite() {
  int iNombreGenere = 0;

  iNombreGenere = rand() % 50002 + 50001;

  return iNombreGenere;
}

char * moyenDeplacement() {
  char *ptrMoyenDeplacement = NULL;
  int iChoix = 0;

  ptrMoyenDeplacement = malloc(21 * sizeof(char));

  if (moyenDeplacement == NULL) {
    printf("Erreur d'allocation memoire pour le moyen de deplacement\n");
    exit(EXIT_FAILURE);
  }

  do {
    printf("╔═══════════════════════════════════╗\n");
    printf("║                                   ║\n");
    printf("║        MOYEN DE DEPLACEMENT       ║\n");
    printf("║                                   ║\n");
    printf("╠════╦══════════════════════════════╣\n");
    printf("║    ║                              ║\n");
    printf("║ 1  ║ ROUTE                        ║\n");
    printf("║    ║                              ║\n");
    printf("║ 2  ║ AIR                          ║\n");
    printf("║    ║                              ║\n");
    printf("║ 3  ║ MER                          ║\n");
    printf("║    ║                              ║\n");
    printf("╚════╩══════════════════════════════╝\n");

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

  cPtrNiveauDisponibilite = malloc(21 * sizeof(char));

  if (cPtrNiveauDisponibilite == NULL) {
    printf("Erreur d'allocation memoire pour le niveau de dispinibilite\n");
    exit(EXIT_FAILURE);
  }

  do {
    printf("╔═══════════════════════════════════╗\n");
    printf("║                                   ║\n");
    printf("║       NIVEAU DE DISPONIBILITE     ║\n");
    printf("║                                   ║\n");
    printf("╠════╦══════════════════════════════╣\n");
    printf("║    ║                              ║\n");
    printf("║ 1  ║ ACTIVE                       ║\n");
    printf("║    ║                              ║\n");
    printf("║ 2  ║ EN REPOS                     ║\n");
    printf("║    ║                              ║\n");
    printf("║ 3  ║ EN REAPPROVISIONNEMENT       ║\n");
    printf("║    ║                              ║\n");
    printf("╚════╩══════════════════════════════╝\n");

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

  cPtrStatutUnite  = malloc(21 * sizeof(char));

  if (cPtrStatutUnite  == NULL) {
    printf("Erreur d'allocation memoire pour le statu unite\n");
    exit(EXIT_FAILURE);
  }

  do {
    printf("╔═══════════════════════════════════╗\n");
    printf("║                                   ║\n");
    printf("║              STATUT               ║\n");
    printf("║                                   ║\n");
    printf("╠════╦══════════════════════════════╣\n");
    printf("║    ║                              ║\n");
    printf("║ 1  ║ EN ALERTE                    ║\n");
    printf("║    ║                              ║\n");
    printf("║ 2  ║ EN ROUTE                     ║\n");
    printf("║    ║                              ║\n");
    printf("║ 3  ║ SUR OPERATION                ║\n");
    printf("║    ║                              ║\n");
    printf("╚════╩══════════════════════════════╝\n");

    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        cPtrStatutUnite  = "ACTIVE\n";
        break;
      case 2:
        cPtrStatutUnite  = "EN REPOS\n";
        break;
        case 3:
        cPtrStatutUnite  = "EN REAPPROVISIONNEMENT\n";
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

  printf("Code d'alerte :\n");
  iTmpNombre = genererCodeUnite();
  (*unite)[i].iCode = iTmpNombre;

  printf("Nom d'unité :\n");
  fgets(sBuffer, TAILLE_BUFFER, stdin);
  strcpy((*unite)[i].cNom, sBuffer);

  printf("Moyen de deplacement :\n");
  cPtrMoyenDeplacement = moyenDeplacement();
  strcpy((*unite)[i].cMoyenDeplacement, cPtrMoyenDeplacement);

  printf("Niveau de disponobilité :\n");
  cPtrNiveauDisponibilite = moyenDeplacement();
  strcpy((*unite)[i].cNiveauDisponibilite, cPtrNiveauDisponibilite);

  printf("Statut :\n");
  cPtrStatutUnite = statutUnite();
  strcpy((*unite)[i].cStatut, cPtrStatutUnite);

  printf("Base :\n");
  fgets(sBuffer, TAILLE_BUFFER, stdin);
  strcpy((*unite)[i].cBase, sBuffer);

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
      printf("Disponobilité : %s", (*unite)[i].cNiveauDisponibilite);
      printf("Satut : %s\n", (*unite)[i].cStatut);
      printf("Base : %s", (*unite)[i].cBase);
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
    printf("Disponobilité : %s", (*unite)[i].cNiveauDisponibilite);
    printf("Statut : %s\n", (*unite)[i].cStatut);
    printf("Base : %s", (*unite)[i].cBase);
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

      printf("Disponobilité :\n");
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

  *unite = realloc(*unite, (*iCompteurUnite * sizeof(Unites)));

  if (*unite == NULL && *iCompteurUnite > 0) {
    printf("Erreur de reallocation memoire après la suppression.\n");
    exit(EXIT_FAILURE);
  }

  printf("DEBUG: La mémoire a été realouée après la suppression\n");

  printf("Unité avec le code %d a été bien supprimé\n", iCodeDonne);
  }
