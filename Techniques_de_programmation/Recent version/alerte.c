#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "alerte.h"

int genererCodeAlerte() {
  int iNombreGenere = 0;

  iNombreGenere = rand() % 50001;

  return(iNombreGenere);
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
    menuNiveauAlerte();

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
        printf("NOTIFICATION : La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > 3);

  return(cPtrNiveau);
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
    menuTypeAlerte();

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
        printf("NOTIFICATION : La saisie n'est pas correcte.\n");
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

  printf("NOTIFICATION : Alerte a été bien crée avec le code suivant : %d\n", (*alerte)[i].iCode);
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
    printf("NOTIFICATION : Aucune alerte n'a été enregistrée\n");
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
      printf("Les unités deployés : %d\n", (*alerte)[i].iCodeUniteQuiTraite);
      existeAlerte = 1;
    }
  }
  if (!existeAlerte)
    printf("NOTIFICATION : Alerte avec le code %d n'a pas été trouvée.\n", iCodeDonne);
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
    printf("NOTIFICATION : Aucune alerte n'a été enregistrée\n");
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
    printf("NOTIFICATION : Alerte avec le code %d n'a pas été trouvée.\n", iCodeDonne);
  } else {
    printf("NOTIFICATION : Alerte avec le code %d a été bien modifiée.\n", iCodeDonne);
  }
}

void supprimerAlerte(Alerte **alerte, int *iCompteurAlerte) {
  int iCodeDonne = 0;
  int i = 0;
  int j = 0;
  int iNouvelleTaille = 0;

  if (*iCompteurAlerte == 0) {
   printf("NOTIFICATION : Aucune alerte n'a été enregistrée\n");
   return;
  }

  printf("Donnez le code d'alerte pour la suppression :\n");
  scanf("%d%*c", &iCodeDonne);

  while (i < *iCompteurAlerte && iCodeDonne != (*alerte)[i].iCode) {
    i++;
  }

  if (i == *iCompteurAlerte) {
    printf("NOTIFICATION : Alerte avec le code %d n'a pas été trouvée.\n", iCodeDonne);
    return;
  } else {
    for (j = i; j < (*iCompteurAlerte); j++) {
        (*alerte)[j].iCode = (*alerte)[j+1].iCode;
        strcpy((*alerte)[j].cType, (*alerte)[j+1].cType);
        strcpy((*alerte)[j].cNiveau, (*alerte)[j+1].cNiveau);
        strcpy((*alerte)[j].cLieu, (*alerte)[j+1].cLieu);
        (*alerte)[j].iNombreVictimes = (*alerte)[j+1].iNombreVictimes;
        strcpy((*alerte)[j].cDescription, (*alerte)[j+1].cDescription);
        // si la suppression a les bugs, supprimmer ces 2 deriniers lignes
        (*alerte)[j].iEstTraiteParUnite = (*alerte)[j+1].iEstTraiteParUnite;
        (*alerte)[j].iCodeUniteQuiTraite = (*alerte)[j+1].iCodeUniteQuiTraite;
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

  printf("NOTIFICATION : Alerte avec le code %d a été bien supprimé\n", iCodeDonne);
}

void alertesStatiques(Alerte **alerte, int *iCompteurAlerte) {
  int i = 0;

  i = *iCompteurAlerte;

  (*alerte)[i].iCode = 12895;
  strcpy((*alerte)[i].cType, "URGENCE\n");
  strcpy((*alerte)[i].cNiveau, "INCENDIE\n");
  strcpy((*alerte)[i].cLieu, "Paris\n");
  (*alerte)[i].iNombreVictimes = 2;
  strcpy((*alerte)[i].cDescription, "Une incendie du Batiment SF au 5-éme arrondissement.\n");
  (*alerte)[i].iEstTraiteParUnite = 0;
  (*alerte)[i].iCodeUniteQuiTraite = 0;
  (*iCompteurAlerte)++;
  i++;
  (*alerte)[i].iCode = 826;
  strcpy((*alerte)[i].cType, "NOMINAL\n");
  strcpy((*alerte)[i].cNiveau, "MALAISE\n");
  strcpy((*alerte)[i].cLieu, "Bayonne\n");
  (*alerte)[i].iNombreVictimes = 1;
  strcpy((*alerte)[i].cDescription, "Une personne a perdue connaissance à cause du chaleur.\n");
  (*alerte)[i].iEstTraiteParUnite = 0;
  (*alerte)[i].iCodeUniteQuiTraite = 0;
  (*iCompteurAlerte)++;
  i++;
}

void supprimerAlerteApresTraitement(Alerte **alerte, int *iCompteurAlerte) {
  int i = 0;
  int j = 0;
  int iNouvelleTaille = 0;

  printf("DEBUG : codeUniteMiseEnRepos() = %d\n", codeUniteMiseEnRepos());

  while (i < *iCompteurAlerte && 87222 != (*alerte)[i].iCodeUniteQuiTraite) {
    i++;
  }

  if (i == *iCompteurAlerte) {
    printf("NOTIFICATION : Alerte avec le code %d n'a pas été trouvée.\n", codeUniteMiseEnRepos());
    return;
  } else {
    for (j = i; j < (*iCompteurAlerte); j++) {
        (*alerte)[j].iCode = (*alerte)[j+1].iCode;
        strcpy((*alerte)[j].cType, (*alerte)[j+1].cType);
        strcpy((*alerte)[j].cNiveau, (*alerte)[j+1].cNiveau);
        strcpy((*alerte)[j].cLieu, (*alerte)[j+1].cLieu);
        (*alerte)[j].iNombreVictimes = (*alerte)[j+1].iNombreVictimes;
        strcpy((*alerte)[j].cDescription, (*alerte)[j+1].cDescription);
        // si la suppression a les bug, supprimmer ces 2 deriniers lignes
        (*alerte)[j].iEstTraiteParUnite = (*alerte)[j+1].iEstTraiteParUnite;
        (*alerte)[j].iCodeUniteQuiTraite = (*alerte)[j+1].iCodeUniteQuiTraite;
    }
  }

  (*iCompteurAlerte)--;

  iNouvelleTaille = *iCompteurAlerte;

  *alerte = realloc(*alerte, ((TAILLE_INITIALE_DE_MALLOC_ALERTE+iNouvelleTaille) * sizeof(Alerte)));

  if (*alerte == NULL && *iCompteurAlerte > 0) {
    printf("Erreur de reallocation memoire après la suppression.\n");
    exit(EXIT_FAILURE);
  }
}

void imprimerLesAlertes(Alerte **alerte, int *iCompteurAlerte) {
  FILE *file = NULL;
  int i = 0;

  file = fopen(NOM_DE_FICHIER_ALERTES, "w");

  if (file == NULL) {
    printf("Erreur d'ouverture de fichier\n");
    exit(-1);
  }

  fprintf(file, "LES ALERTES :\n\n");
  for (i = 0; i < *iCompteurAlerte; i++) {
   fprintf(file, "Code d'alerte : %d\n", (*alerte)[i].iCode);
   fprintf(file, "Type d'alerte : %s", (*alerte)[i].cType);
   fprintf(file, "Niveau d'alerte : %s", (*alerte)[i].cNiveau);
   fprintf(file, "Lieu : %s", (*alerte)[i].cLieu);
   fprintf(file, "Nombre de victimes : %d\n", (*alerte)[i].iNombreVictimes);
   fprintf(file, "Description : %s", (*alerte)[i].cDescription);
   fprintf(file, "Les unités deployés : %d\n\n", (*alerte)[i].iCodeUniteQuiTraite);
 }
  fclose(file);
  printf("Les alertes ont été bien sauvegardée dans le fichier alertes.txt\n");
}
