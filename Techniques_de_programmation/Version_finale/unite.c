/*
  Le module unite.c sert pour la gestion des unités.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "alerte.h"
#include "unite.h"

/*
  La fonction genererCodeUnite(); génére le code aléatoire entre 50,001 et
  100,000 pour chaque unité qui a été crée.
  @params: aucun
  retourne: int
*/
int genererCodeUnite() {
  return(rand() % TAILLE_DE_CODE_GENERE_50002 + TAILLE_DE_CODE_GENERE_50001);
}
/*
  La fonction *moyenDeplacement(); retourne un pointeur de type de chaîne de caractères
  selon la choix de l'utilisateur.
  @params: aucun
  retourne: une chaîne de caractères
*/
char * moyenDeplacement() {
  char *cpMoyenDeplacement = NULL;
  int iChoix = 0; /* choix d'utilisateur */

  cpMoyenDeplacement = malloc(TAILLE_BUFFER_RETOUR * sizeof(char));

  if (moyenDeplacement == NULL) {
    printf("Erreur d'allocation memoire pour le moyen de deplacement\n");
    exit(EXIT_FAILURE);
  }

  do {
    /* appel du menu et traitement du choix de l'utilisateur */
    menuDeplacementUnite();

    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        cpMoyenDeplacement = MOYEN_DEPLACEMEMENT_ROUTE;
        break;
      case 2:
        cpMoyenDeplacement = MOYEN_DEPLACEMEMENT_AIR;
        break;
        case 3:
        cpMoyenDeplacement = MOYEN_DEPLACEMEMENT_MER;
        break;
        default:
        printf("NOTIFICATION : La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > CHOIX_MAX_MOYEN_DEPLACEMENT);

  return(cpMoyenDeplacement);
}
/*
  La fonction *niveauDisponibilite(); retourne un pointeur de type de chaîne de caractères
  selon la choix de l'utilisateur.
  @params: aucun
  retourne: une chaîne de caractères
*/
char * niveauDisponibilite() {
  char *cpNiveauDisponibilite = NULL;
  int iChoix = 0; /* choix d'utilisateur */

  cpNiveauDisponibilite = malloc(TAILLE_BUFFER_RETOUR * sizeof(char));

  if (cpNiveauDisponibilite == NULL) {
    printf("Erreur d'allocation memoire pour le niveau de dispinibilite\n");
    exit(EXIT_FAILURE);
  }

  do {
    /* appel du menu et traitement du choix de l'utilisateur */
    menuDisponibiliteUnite();

    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        cpNiveauDisponibilite = DISPONIBILITE_ACTIVE;
        break;
      case 2:
        cpNiveauDisponibilite = DISPONIBILITE_EN_REPOS;
        break;
        case 3:
        cpNiveauDisponibilite = DISPONIBILITE_EN_REAPPROVISIONNEMENT;
        break;
        default:
        printf("NOTIFICATION : La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > CHOIX_MAX_NIVEAU_DISPONIBILITE);

  return(cpNiveauDisponibilite);
}
/*
  La fonction *statutUnite(); retourne un pointeur de type de chaîne de caractères
  selon la choix de l'utilisateur.
  @params: aucun
  retourne: une chaîne de caractères
*/
char * statutUnite() {
  char *cpStatutUnite = NULL;
  int iChoix = 0; /* choix d'utilisateur */

  cpStatutUnite  = malloc(TAILLE_BUFFER_RETOUR * sizeof(char));

  if (cpStatutUnite  == NULL) {
    printf("Erreur d'allocation memoire pour le statu unite\n");
    exit(EXIT_FAILURE);
  }

  do {
    /* appel du menu et traitement du choix de l'utilisateur */
    menuStatutUnite();

    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        cpStatutUnite  = STATUT_EN_ALERTE;
        break;
      case 2:
        cpStatutUnite  = STATUT_EN_ROUTE;
        break;
      case 3:
        cpStatutUnite  = STATUT_SUR_OPERATION;
        break;
      default:
        printf("NOTIFICATION : La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > CHOIX_MAX_STATUT_UNITE);

  return(cpStatutUnite);
}
/*
  La fonction creerUnite(); permet de créer nouvelle unité.
  L'utilisateur saisie les donées qui permet de décrire une unité
  et ensuite elles sont sauvegardé dans la structure Untes.
  @params: pointeur de pointeur de la struct Unites, pointeur d'entier de
  compteur d'unite
  retourne: void
*/
void creerUnite(Unites **unite, int *iCompteurUnite) {
  char sBuffer[TAILLE_BUFFER]; /* sBuffer de saisie pour les chaînes de caractères */
  char *cpStatutUnite = NULL;
  char *ccpMoyenDeplacement = NULL;
  char *cpNiveauDisponibilite = NULL;
  int iTmpNombre = 0; /* variable qui va temporairement contenir le nombre */
  int i;

  i = *iCompteurUnite;

  iTmpNombre = genererCodeUnite();
  (*unite)[i].iCode = iTmpNombre;

  printf("Nom d'unité :\n");
  fgets(sBuffer, TAILLE_BUFFER, stdin);
  strcpy((*unite)[i].cNom, sBuffer);

  printf("Moyen de deplacement :\n");
  ccpMoyenDeplacement = moyenDeplacement();
  strcpy((*unite)[i].cMoyenDeplacement, ccpMoyenDeplacement);

  printf("Niveau de disponibilité :\n");
  cpNiveauDisponibilite = niveauDisponibilite();
  strcpy((*unite)[i].cNiveauDisponibilite, cpNiveauDisponibilite);

  if (strcmp(cpNiveauDisponibilite, DISPONIBILITE_EN_REPOS) == 0) {
    (*unite)[i].iEstEnRepos = 1;
    //(*unite)[i].iUniteDisponible = 0;
  }

  if (strcmp(cpNiveauDisponibilite, STATUT_SUR_OPERATION) == 0) {
    (*unite)[i].iUniteDisponible = 0;
    (*unite)[i].iEstEnRepos = 1;
  }

  printf("Statut :\n");
  cpStatutUnite = statutUnite();
  strcpy((*unite)[i].cStatut, cpStatutUnite);

  printf("Base :\n");
  fgets(sBuffer, TAILLE_BUFFER, stdin);
  strcpy((*unite)[i].cBase, sBuffer);

  (*unite)[i].iCompteurRepos = 0;
  (*unite)[i].iUniteDisponible = 1;
  (*unite)[i].iDeployeeSurAlerte = 0;

  printf("NOTIFICATION : Unité a été bien crée avec le code suivant : %d\n", (*unite)[i].iCode);
}
/*
  La fonction afficherUneUnite(); parcours le tableau de structure d'Unites
  et affiche à l'utilisateur toutes les alertes qui ont été enregistrées.
  @params: pointeur de pointeur de la struct Unites, pointeur d'entier de
  compteur d'unite
  retourne: void
*/
void afficherUneUnite(Unites **unite, int *iCompteurUnite) {
  int i = 0;
  int iCodeDonne = 0; /* le code utilisé pour le parcourt du tableau donné par l'utilisateur  */
  int iExisteUnite = 0;  /* booleen qui sert à définir si unité existe ou non */

  if (*iCompteurUnite == 0) {
    printf("Aucune unité n'a été enregistrée\n");
    return;
  }

  printf("Donnez le code d'unité :\n");
  scanf("%d%*c", &iCodeDonne);

  for (i = 0; i < (*iCompteurUnite); i++) {
    if (iCodeDonne == (*unite)[i].iCode) {
      afficherUnite((*unite)[i]);
      iExisteUnite = 1;
    }
  }
  if (!iExisteUnite)
    printf("Unité avec le code %d n'a pas été trouvée.\n", iCodeDonne);
}
/*
  La fonction afficherToutesUnites(); parcours le tableau de structure d'Unites
  et affiche à l'utilisateur qu'une seule unité selon le code que l'utilisateur
  a donné. Si le code est faux ou unité n'existe pas, la fonction affiche une
  notification d'erreur à l'écran.
  @params: pointeur de pointeur de la struct Unites, pointeur d'entier de
  compteur d'unite
  retourne: void
*/
void afficherToutesUnites(Unites **unite, int *iCompteurUnite) {
  int i = 0;

   if (*iCompteurUnite == 0) {
    printf("Aucune unité n'a été enregistrée\n");
    return;
  }

   for (i = 0; i < *iCompteurUnite; i++) {
      afficherUnite((*unite)[i]);
  }
}
/*
  La fonction modifierUnite(); parcours le tableau de structure d'Unites
  et affiche à l'utilisateur unité selon le code qu'il a saisi. Si le code est
  faux ou unité n'existe pas, la fonction affiche une notification d'erreur à l'écran.
  Sinon, l'utilisateur saisie les nouvelles donnée de l'unité sauf le code qui
  a été généré automatiquement. Ce-dernière reste le même malgré les modifications.
  @params: pointeur de pointeur de la struct Unites, pointeur d'entier de
  compteur d'unite
  retourne: void
*/
void modifierUnite(Unites **unite, int *iCompteurUnite) {
  char *cpStatutUnite = NULL;
  char *ccpMoyenDeplacement = NULL;
  char *cpNiveauDisponibilite = NULL;
  char sBuffer[TAILLE_BUFFER]; /* sBuffer de saisie pour les chaînes de caractères */
  int i = 0;
  int iExisteUnite = 0; /* booleen qui sert à définir si unité existe ou non */
  int iCodeDonne = 0; /* le code utilisé pour le parcourt du tableau donné par l'utilisateur  */
  int iTmpNombre = 0; /* va stocker temporairement un nombre */

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
      ccpMoyenDeplacement = moyenDeplacement();
      strcpy((*unite)[i].cMoyenDeplacement, ccpMoyenDeplacement);

      printf("Disponibilité :\n");
      cpNiveauDisponibilite = niveauDisponibilite();
      strcpy((*unite)[i].cNiveauDisponibilite, cpNiveauDisponibilite);

      if (strcmp(cpNiveauDisponibilite, DISPONIBILITE_EN_REPOS) == 0) {
        (*unite)[i].iCompteurRepos = 0;
        (*unite)[i].iUniteDisponible = 1;
        (*unite)[i].iDeployeeSurAlerte = 0;
      }

      if (strcmp(cpNiveauDisponibilite, STATUT_SUR_OPERATION) == 0) {
          (*unite)[i].iEstEnRepos = 1;
      }

      printf("Statut :\n");
      cpStatutUnite = statutUnite();
      strcpy((*unite)[i].cStatut, cpStatutUnite);

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
/*
  La fonction supprimerUnite(); parcours le tableau de structure d'Unites
  et affiche à l'utilisateur unité selon le code qu'il a saisi. Si le code est
  faux ou unité n'existe pas, la fonction affiche une notification d'erreur à l'écran.
  Sinon, unité sera supprimmée de la structure d'Unites. Apès la suppression
  tous les éléments de la structure d'Unites sont bougé pour éviter les trous.
  La mémoire est realouée et le iCompteurUnite est diminué de 1.
  @params: pointeur de pointeur de la struct Unites, pointeur d'entier de
  compteur d'unite
  retourne: void
*/
void supprimerUnite(Unites **unite, int *iCompteurUnite) {
  int iCodeDonne = 0;
  int i = 0;
  int j = 0;
  int iNouvelleTaille = 0; /* sert pour redimentionner le tableau de structure */

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
    }
  }

/* rédimention la taille du tableau de la structure d'Alerte après la suppression  */
  (*iCompteurUnite)--;
  iNouvelleTaille = *iCompteurUnite;
  *unite = realloc(*unite, ((TAILLE_INITIALE_DE_MALLOC_UNITE+iNouvelleTaille) * sizeof(Unites)));

  if (*unite == NULL && *iCompteurUnite > 0) {
    printf("Erreur de reallocation memoire après la suppression.\n");
    exit(EXIT_FAILURE);
  }
  printf("NOTIFICATION : Unité avec le code %d a été bien supprimé\n", iCodeDonne);
}
/*
  La fonction mettreUniteEnRepos(); permet de mettre une unité en repos après
  ses 3 intervations sur les alertes. La fonction parcours la structure d'Unites
  et en trouvant chaque unité qui a iCompteurRepos >= 3, elle affecte le valeur
  "EN REPOS" pour le nivequ de disponibilité.
  @params: pointeur de pointeur de la struct Unites, pointeur d'entier de
  compteur d'unite
  retourne: void
*/
void mettreUniteEnRepos(Unites **unite, int *iCompteurUnite) {
  int i = 0;
  int iChangementsEffectuees = 0;

  for (i = 0; i < *iCompteurUnite; i++) {
    if ((*unite)[i].iCompteurRepos >= 3) {
      strcpy((*unite)[i].cNiveauDisponibilite, DISPONIBILITE_EN_REPOS);
      (*unite)[i].iDeployeeSurAlerte = 0;
      (*unite)[i].iCompteurRepos = 0;
      (*unite)[i].iUniteDisponible = 0;
      (*unite)[i].iEstEnRepos = 1;
      iChangementsEffectuees = 1;
    }
  }

  if (iChangementsEffectuees)
    printf("NOTIFICATION : Certains unités ont été mises en repos car elles étaient deployées 3 fois.\n");
}
/*
  La fonction declancherAlerte(); affiche toutes les alertes non traitées et toutes
  les unités disponiblées. S'il y a aucune alerte non traitées, le message correspondant
  va être affiche à l'écran pour l'utilisateur. La même chose, s'il n'y a aucune
  unité disponible sauf les cas de force majeure. Ce-dernière permet à l'utilisateur
  de faire intervenir les unités qui sont en repos.
  Utilisateur saisie le code d'alerte qu'il veut traiter et le code d'unités qu'il
  veut envoyer pour le traitement de l'alerte saisie. Si le code est faux ou l'alerte ou bien
  unité n'exite pas, le message d'erreur sera affiche à l'écran. Sinon, un parcours
  sera réalisé dans la structure d'Alerte et structure d'Unité et puis affectation
  de l'unité saisi à l'alerte saisi. Le code des unités deployées sur alerte sera affiche
  sur alerte et le code d'alerte traitées par l'unité sera affiche sur unité. Apès cette
  procedure, les alertes en cours de traitement et les unités deployées ne seront
  plus affiche dans le menu de declanchement d'alerte.
  @params: pointeur de pointeur de la struct Unites, pointeur d'entier de
  compteur d'unite, pointeur de pointeur de la stuct Alerte, pointeur d'entier
  de compteur d'alerte
  retourne: void
*/
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
    afficherAlerte((*alerte)[i]);
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
      if ((*unite)[i].iUniteDisponible == 0 || (*unite)[i].iEstEnRepos == 1)
        continue;
      afficherUnite((*unite)[i]);
      iBoucleCompteurUnite++;
  }

  if (iBoucleCompteurUnite == 0) {
    printf("Les unités sont occuppées.\n");
    menuCaseForceMajeur();
    scanf("%d%*c", &iChoix);

    switch(iChoix) {
      case 1:
        printf("Toutes les unités trouvées en repos : \n");
        for (i = 0; i < *iCompteurUnite; i++) {
          if ((*unite)[i].iEstEnRepos == 1) {
            afficherUnite((*unite)[i]);
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
  //(*unite)[iTmpPositionUnite].iCompteurRepos += 1;
  strcpy((*unite)[iTmpPositionUnite].cNiveauDisponibilite, DISPONIBILITE_ACTIVE);
  strcpy((*unite)[iTmpPositionUnite].cStatut, STATUT_SUR_OPERATION);
  (*unite)[iTmpPositionUnite].iDeployeeSurAlerte = iCodeDonneAlerte;
  (*unite)[iTmpPositionUnite].iUniteDisponible = 0;
  (*unite)[iTmpPositionUnite].iEstEnRepos = 0;
  printf("Les unités ont été bien envoyée\n");
}
/*
  La fonction unitesStatiques(); crée les unités statiques dès que le programme
  est lancé. Permet de faire des testes directs et éviter de taper les nouvelles
  alertes à chaque chargement du programme.
  @params: pointeur de pointeur de la struct Unites, pointeur d'entier de
  compteur d'unite
  retourne: void
*/
int unitesStatiques(Unites **unite, int *iCompteurUnite, int *iLesUnitesDefinis) {
  (*unite)[0].iCode = 51789;
  strcpy((*unite)[0].cNom, "Ambulance\n");
  strcpy((*unite)[0].cMoyenDeplacement, "ROUTE\n");
  strcpy((*unite)[0].cNiveauDisponibilite, "ACTIVE\n");
  strcpy((*unite)[0].cStatut, "EN ALERTE\n");
  strcpy((*unite)[0].cBase, "Bayonne\n");
  (*unite)[0].iCompteurRepos = 0;
  (*unite)[0].iUniteDisponible = 1;
  (*unite)[0].iDeployeeSurAlerte = 0;
  (*iCompteurUnite)++;
  (*unite)[1].iCode = 87222;
  strcpy((*unite)[1].cNom, "Pompiers\n");
  strcpy((*unite)[1].cMoyenDeplacement, "ROUTE\n");
  strcpy((*unite)[1].cNiveauDisponibilite, "ACTIVE\n");
  strcpy((*unite)[1].cStatut, "EN ALERTE\n");
  strcpy((*unite)[1].cBase, "Paris\n");
  (*unite)[1].iCompteurRepos = 1;
  (*unite)[1].iUniteDisponible = 1;
  (*unite)[1].iDeployeeSurAlerte = 0;
  (*iCompteurUnite)++;
  (*iLesUnitesDefinis) = 1;

  return(*iLesUnitesDefinis);
}

void consulterUnitesDeployees(Unites **unite, int *iCompteurUnite) {
  int i = 0;
  int iCompteurBoucle = 0;
  int iChoix = 0;
  int iCodeDonneUnite = 0;
  int iTmpPositionUnite = 0;

  printf("Les unités deployées :\n");
    for (i = 0; i < *iCompteurUnite; i++) {
      if ((*unite)[i].iUniteDisponible == 1 || (*unite)[i].iEstEnRepos == 1)
        continue;
      afficherUnite((*unite)[i]);
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
        printf("Donnez le code d'unité pour mettre en reapprovisionnement :\n");
        scanf("%d%*c", &iCodeDonneUnite);

        while (iTmpPositionUnite < *iCompteurUnite && iCodeDonneUnite != (*unite)[iTmpPositionUnite].iCode) {
          iTmpPositionUnite++;
        }

        if (iTmpPositionUnite == *iCompteurUnite) {
          printf("NOTIFICATION : Unité avec le code %d n'a pas été trouvée.\n", iCodeDonneUnite);
          return;
        }

        strcpy((*unite)[iTmpPositionUnite].cNiveauDisponibilite, DISPONIBILITE_EN_REAPPROVISIONNEMENT);
        strcpy((*unite)[iTmpPositionUnite].cStatut, STATUT_EN_ALERTE);

        (*unite)[iTmpPositionUnite].iCompteurRepos += 1;
        (*unite)[iTmpPositionUnite].iUniteDisponible = 1;
        (*unite)[iTmpPositionUnite].iDeployeeSurAlerte = 0;

        //supprimerAlerteApresTraitement(&alerte, &iCompteurAlerte, &iCodeDonneUnite);

        printf("NOTIFICATION : L'unité avec le code %d a été bien mise en reapprovisionnement\n", iCodeDonneUnite);
        //main();
        break;
      case -2:
        break;
      default:
        printf("La saisie n'est pas correcte\n");
        break;
    }
  } while(iChoix != -2);
}
/*
  La fonction imprimerLesUnites(); cette fonction crée un fichier qui s'appelle
  unites.txt et imprime toutes les unités qui existent dans la structure d'Unites.
  @params: pointeur de pointeur de la struct Unites, pointeur d'entier de
  compteur d'unite
  retourne: void
*/
void imprimerLesUnites(Unites **unite, int *iCompteurUnite) {
  FILE *file = NULL;
  int i = 0;

  file = fopen(NOM_DE_FICHIER_UNITES, "w");

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
  printf("NOTIFICATION : Les unités ont été bien sauvegardée dans le fichier unites.txt\n");
}
/*
  La fonction chargerLesUnites(); lit un fichier donnée par l'utilisateur. Si
  le fichier n'existe pas ou le nom de fichier n'est pas correct, la fonction
  affiche une notification d'erreur à l'écran. Sinon, toutes les données seront
  affichées au-dessus de menu principal.
  @params: pointeur de pointeur de la struct Unites, pointeur d'entier de
  compteur d'unite
  retourne: void
*/
void chargerLesUnites(Unites **unite, int *iCompteurUnite) {
  FILE *file = NULL;
  int i = 0;
  char sBuffer[TAILLE_BUFFER];

  printf("Donnez le nom du fichier avec son extantion (ex: exemple.txt)\n");
  scanf("%s%*c",sBuffer);

  file = fopen(sBuffer, "r");

  if (file == NULL) {
    printf("Erreur d'ouverture de fichier. Vérifiez que le fichier existe.\n");
    return;
   }

 printf("Les unités chargées du fichier :\n");
 while(!feof(file)) {
    fgets(sBuffer, TAILLE_BUFFER, file);
    printf("%s", sBuffer);
  }
 fclose(file);
}
