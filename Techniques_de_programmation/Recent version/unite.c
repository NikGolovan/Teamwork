#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "alerte.h"
#include "unite.h"

int genererCodeUnite() {
  int iNombreGenere = 0;

  iNombreGenere = rand() % 50002 + 50001;

  return(iNombreGenere);
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
    menuDeplacementUnite();

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
        printf("NOTIFICATION : La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > 3);

  return(ptrMoyenDeplacement);
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
    menuDisponibiliteUnite();

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
        printf("NOTIFICATION : La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > 3);

  return(cPtrNiveauDisponibilite);
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
    menuStatutUnite();

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
        printf("NOTIFICATION : La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > 3);

  return(cPtrStatutUnite);
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

  (*unite)[i].iCompteurRepos = 0;
  (*unite)[i].iUniteDisponible = 1;
  (*unite)[i].iDeployeeSurAlerte = 0;

  printf("NOTIFICATION : Unité a été bien crée avec le code suivant : %d\n", (*unite)[i].iCode);
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

      printf("DEBUG : (*unite)[i].cNiveauDisponibilite = %s\n", (*unite)[i].cNiveauDisponibilite);

      if (strcmp(cPtrNiveauDisponibilite, "EN REPOS\n") == 0) {
        (*unite)[i].iCompteurRepos = 0;
        (*unite)[i].iUniteDisponible = 1;
        (*unite)[i].iDeployeeSurAlerte = 0;
      }

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
    printf("NOTIFICATION : Unité avec le code %d n'a pas été trouvée.\n", iCodeDonne);
  } else {
    printf("NOTIFICATION : Unité avec le code %d a été bien modifiée.\n", iCodeDonne);
  }
}

void supprimerUnite(Unites **unite, int *iCompteurUnite) {
  int iCodeDonne = 0;
  int i = 0;
  int j = 0;
  int iNouvelleTaille = 0;

  if (*iCompteurUnite == 0) {
   printf("NOTIFICATION : Aucune unité n'a été enregistrée\n");
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
        // si la suppression bug, supprimmer ces 4 deriniers lignes
        (*unite)[j].iCode = (*unite)[j+1].iCompteurRepos;
        (*unite)[j].iCode = (*unite)[j+1].iEstEnRepos;
        (*unite)[j].iCode = (*unite)[j+1].iUniteDisponible;
        (*unite)[j].iCode = (*unite)[j+1].iDeployeeSurAlerte;
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

  printf("NOTIFICATION : Unité avec le code %d a été bien supprimé\n", iCodeDonne);
}


void mettreUniteEnRepos(Unites **unite, int *iCompteurUnite) {
  int i = 0;
  int iChangementsEffectuees = 0;

  for (i = 0; i < *iCompteurUnite; i++) {
    if ((*unite)[i].iCompteurRepos >= 3) {
      strcpy((*unite)[i].cNiveauDisponibilite, "EN REPOS\n");
      (*unite)[i].iDeployeeSurAlerte = 0;
      iChangementsEffectuees = 1;
    }
  }

  if (iChangementsEffectuees)
    printf("NOTIFICATION : Certains unités ont été mises en repos car elles étaient deployées 3 fois.\n");
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
    printf("Les unités deployés : %d\n", (*alerte)[i].iCodeUniteQuiTraite);
    iBoucleCompteurAlerte++;
  }

  if (iBoucleCompteurAlerte == 0) {
    printf("NOTIFICATION : Toutes les alertes sont traitées par les unités\n");
    return;
  }

  printf("\n\n");

  if (*iCompteurUnite == 0) {
    printf("NOTIFICATION : Aucune unité n'a pas été enregistrée\n");
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
    printf("NOTIFICATION : Toutes les unités sont occuppées.\n\n");
    printf("CAS DE FORCE MAJEURE\n");
    printf("1. Faire intervenir les unités en repos -2 pour retourner\n");
    scanf("%d%*c", &iChoix);

    switch(iChoix) {
      case 1:
        for (i = 0; i < *iCompteurUnite; i++) {
          if (strcmp((*unite)[i].cNiveauDisponibilite, UNITE_EN_REPOS) != 1) {
            printf("NOTIFICATION : Aucune unités est en repos\n");
            return;
          } else {
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
       printf("NOTIFICATION : La saisie n'est pas correcte. Retour automatique au menu principal.\n");
       return;
       break;
    }
  }

  printf("\n\n");

  printf("Donnez le code d'alerte :\n");
  scanf("%d%*c", &iCodeDonneAlerte);

  while (iTmpPositionAlerte < *iCompteurAlerte && iCodeDonneAlerte != (*alerte)[iTmpPositionAlerte].iCode) {
    iTmpPositionAlerte++;
  }

  if (iTmpPositionAlerte == *iCompteurAlerte) {
    printf("NOTIFICATION : Alerte avec le code %d n'a pas été trouvée.\n", iCodeDonneAlerte);
    return;
  }

  printf("Donnez code d'unité à envoyer : \n");
  scanf("%d%*c", &iCodeDonneUnite);

  while (iTmpPositionUnite < *iCompteurUnite && iCodeDonneUnite != (*unite)[iTmpPositionUnite].iCode) {
      iTmpPositionUnite++;
   }

  if (iTmpPositionUnite == *iCompteurUnite) {
    printf("NOTIFICATION : Unité avec le code %d n'a pas été trouvée.\n", iCodeDonneUnite);
    return;
  }
  (*alerte)[iTmpPositionAlerte].iCodeUniteQuiTraite = iCodeDonneUnite;
  (*alerte)[iTmpPositionAlerte].iEstTraiteParUnite = 1;
  (*unite)[iTmpPositionUnite].iCompteurRepos += 1;
  strcpy((*unite)[iTmpPositionUnite].cNiveauDisponibilite, "ACTIVITE\n");
  strcpy((*unite)[iTmpPositionUnite].cStatut, "EN ALERTE\n");
  (*unite)[iTmpPositionUnite].iDeployeeSurAlerte = iCodeDonneAlerte;
  (*unite)[iTmpPositionUnite].iUniteDisponible = 0;
}

void unitesStatiques(Unites **unite, int *iCompteurUnite) {
  int i;

  i = *iCompteurUnite;

  (*unite)[i].iCode = 51789;
  strcpy((*unite)[i].cNom, "Ambulance\n");
  strcpy((*unite)[i].cMoyenDeplacement, "ROUTE\n");
  strcpy((*unite)[i].cNiveauDisponibilite, "ACTIVITE\n");
  strcpy((*unite)[i].cStatut, "EN REPOS\n");
  strcpy((*unite)[i].cBase, "Bayonne\n");
  (*unite)[i].iCompteurRepos = 0;
  (*unite)[i].iUniteDisponible = 1;
  (*unite)[i].iDeployeeSurAlerte = 0;
  (*iCompteurUnite)++;
  i++;
  (*unite)[i].iCode = 87222;
  strcpy((*unite)[i].cNom, "Pompiers\n");
  strcpy((*unite)[i].cMoyenDeplacement, "ROUTE\n");
  strcpy((*unite)[i].cNiveauDisponibilite, "ACTIVITE\n");
  strcpy((*unite)[i].cStatut, "EN REPOS\n");
  strcpy((*unite)[i].cBase, "Paris\n");
  (*unite)[i].iCompteurRepos = 0;
  (*unite)[i].iUniteDisponible = 1;
  (*unite)[i].iDeployeeSurAlerte = 0;
  (*iCompteurUnite)++;
  i++;
}

void consulterUnitesDeployees(Unites **unite, int *iCompteurUnite) {
  int i = 0;
  int iCompteurBoucle = 0;
  int iChoix = 0;
  int iCodeDonneUnite = 0;
  int iTmpPositionUnite = 0;

  printf("Les unités deployées :\n");
    for (i = 0; i < *iCompteurUnite; i++) {
      if ((*unite)[i].iUniteDisponible == 1)
        continue;
      printf("\n");
      printf("Code d'unité : %d\n", (*unite)[i].iCode);
      printf("Nom d'unité : %s", (*unite)[i].cNom);
      printf("Moyen de deplacement : %s", (*unite)[i].cMoyenDeplacement);
      printf("Disponibilité : %s", (*unite)[i].cNiveauDisponibilite);
      printf("Statut : %s", (*unite)[i].cStatut);
      printf("Base : %s", (*unite)[i].cBase);
      printf("Deployée sur les alertes : %d\n", (*unite)[i].iDeployeeSurAlerte);
      iCompteurBoucle++;
  }

  if (iCompteurBoucle == 0) {
    printf("NOTIFICATION : Il n'y a aucune unité deployée\n");
    return;
  }

  do {
    menuGestionUniteDeployee();
    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        printf("Donnez le code d'unité pour mettre en repos :\n");
        scanf("%d%*c", &iCodeDonneUnite);

        while (iTmpPositionUnite < *iCompteurUnite && iCodeDonneUnite != (*unite)[iTmpPositionUnite].iCode) {
          iTmpPositionUnite++;
        }

        if (iTmpPositionUnite == *iCompteurUnite) {
          printf("NOTIFICATION : Unité avec le code %d n'a pas été trouvée.\n", iCodeDonneUnite);
          return;
        }

        strcpy((*unite)[iTmpPositionUnite].cStatut, "EN REPOS\n");
        (*unite)[iTmpPositionUnite].iCompteurRepos = 0;
        (*unite)[iTmpPositionUnite].iUniteDisponible = 1;
        (*unite)[iTmpPositionUnite].iDeployeeSurAlerte = 0;

        uniteMiseEnRepos();
        codeUniteMiseEnRepos(iCodeDonneUnite);

        printf("NOTIFICATION : L'unité avec le code %d a été bien mise en repos\n", iCodeDonneUnite);
        break;
      default:
        printf("La saisie n'est pas correcte\n");
        break;
    }
  } while(iChoix != -2);
}

int uniteMiseEnRepos() {
  return(1);
}

int codeUniteMiseEnRepos(int iCodeDonneUnite) {
  int iTmp = iCodeDonneUnite;

  return(iTmp);
}

void imprimerLesUnites(Unites **unite, int *iCompteurUnite) {
  FILE *file = fopen(NOM_DE_FICHIER_UNITES, "w");
  int i = 0;

  if (file == NULL) {
    printf("Erreur d'ouverture de fichier\n");
    exit(-1);
  }

  fprintf(file, "LES UNITES :\n\n");
  for (i = 0; i < *iCompteurUnite; i++) {
    fprintf(file, "Code d'unité : %d\n", (*unite)[i].iCode);
    fprintf(file, "Nom d'unité : %s", (*unite)[i].cNom);
    fprintf(file, "Moyen de deplacement : %s", (*unite)[i].cMoyenDeplacement);
    fprintf(file, "Disponibilité : %s", (*unite)[i].cNiveauDisponibilite);
    fprintf(file, "Statut : %s", (*unite)[i].cStatut);
    fprintf(file, "Base : %s", (*unite)[i].cBase);
    fprintf(file, "Deployée sur les alertes : %d\n\n", (*unite)[i].iDeployeeSurAlerte);
 }
  fclose(file);
}
