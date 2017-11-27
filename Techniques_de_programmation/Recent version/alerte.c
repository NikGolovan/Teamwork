/*
  Le module alerte.c sert pour la gestion des alertes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "alerte.h"
/*
  La fonction genererCodeAlerte(); génére le code aléatoire entre 0 et
  50,000 pour chaque alerte qui a été crée.
  @params: aucun
  retourne: int
*/
int genererCodeAlerte() {
  return(rand() % TAILLE_DE_CODE_GENERE_50001);
}
/*
  La fonction *niveauAlerte(); retourne un pointeur de type de chaîne de caractères
  selon la choix de l'utilisateur.
  @params: aucun
  retourne: une chaîne de caractères
*/
char * niveauAlerte() {
  char *cpNiveau = NULL;
  int iChoix = 0;

  cpNiveau = malloc(TAILLE_BUFFER_RETOUR * sizeof(char));

  if (cpNiveau == NULL) {
    printf("Erreur d'allocation memoire pour le niveau d'alerte\n");
    exit(EXIT_FAILURE);
  }

  do {
    menuNiveauAlerte();
    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        cpNiveau = NIVAU_NOMINAL;
        break;
      case 2:
        cpNiveau = NIVAU_URGENT;
        break;
        case 3:
        cpNiveau = NIVAU_URGENCE_ABSOLUE;
        break;
        default:
        printf("NOTIFICATION : La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > CHOIX_MAX_NIVEAU_ALERTE);

  return(cpNiveau);
}
/*
  La fonction *typeAlerte() retourne un pointeur de type de chaîne de caractères
  selon la choix de l'utilisateur.
  @params: aucun
  retourne: une chaîne de caractères
*/
char * typeAlerte() {
  char *cpType = NULL;
  int iChoix = 0;

  cpType = malloc(TAILLE_BUFFER_RETOUR * sizeof(char));

  if (cpType == NULL) {
    printf("Erreur d'allocation memoire pour le type d'alerte\n");
    exit(EXIT_FAILURE);
  }

  do {
    menuTypeAlerte();

    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        cpType = TYPE_INCENDIE;
        break;
      case 2:
        cpType = TYPE_ACCIDENT_ROUTE;
        break;
      case 3:
        cpType = TYPE_ACCIDENT_MER;
        break;
      case 4:
        cpType = TYPE_ACCIDENT_MONTAGNE;
        break;
      case 5:
        cpType = TYPE_MALAISE;
        break;
      case 6:
        cpType = TYPE_EXPLOSION;
        break;
      case 7:
        cpType = TYPE_ACCIDENT_DE_LA_VIE;
        break;
      default:
        printf("NOTIFICATION : La saisie n'est pas correcte.\n");
        break;
    }
  } while (iChoix > CHOIX_MAX_TYPE_ALERTE);

  return(cpType);
}
/*
  La fonction ajouterAlerte(); permet de créer nouvelle alerte.
  L'utilisateur saisie les donées qui permet de décrire une alerte
  et ensuite elles sont sauvegardé dans la structure Alerte.
  @params: pointeur de pointeur de la struct Alerte, pointeur d'entier de
  compteur d'alerte
  retourne: void
*/
void ajouterAlerte(Alerte **alerte, int *iCompteurAlerte) {
  char sBuffer[TAILLE_BUFFER];
  char *cpType = NULL;
  char *cpNiveau = NULL;
  int iTmpNombre = 0;
  int i = 0;

  i = *iCompteurAlerte;

  iTmpNombre = genererCodeAlerte();
  (*alerte)[i].iCode = iTmpNombre;

  printf("Type d'alerte :\n");
  cpType = typeAlerte();
  strcpy((*alerte)[i].cType, cpType);

  printf("Niveau d'alerte :\n");
  cpNiveau = niveauAlerte();
  strcpy((*alerte)[i].cNiveau, cpNiveau);

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
/*
  La fonction afficherToutesAlertes(); parcours le tableau de structure d'Alerte
  et affiche à l'utilisateur toutes les alertes qui ont été enregistrées.
  @params: pointeur de pointeur de la struct Alerte, pointeur d'entier de
  compteur d'alerte
  retourne: void
*/
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
    printf("Les unités deployés : %d\n", (*alerte)[i].iCodeUniteQuiTraite);
  }
}
/*
  La fonction afficherUneAlerte(); parcours le tableau de structure d'Alerte
  et affiche à l'utilisateur qu'une seule alerte selon le code que l'utilisateur
  a donné. Si le code est faux ou alerte n'existe pas, la fonction affiche une
  notification d'erreur à l'écran.
  @params: pointeur de pointeur de la struct Alerte, pointeur d'entier de
  compteur d'alerte
  retourne: void
*/
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
      printf("Les unités deployés : %d\n", (*alerte)[i].iCodeUniteQuiTraite);
      existeAlerte = 1;
    }
  }
  if (!existeAlerte)
    printf("NOTIFICATION : Alerte avec le code %d n'a pas été trouvée.\n", iCodeDonne);
}
/*
  La fonction modifierAlerte(); parcours le tableau de structure d'Alerte
  et affiche à l'utilisateur alerte selon le code qu'il a saisi. Si le code est
  faux ou alerte n'existe pas, la fonction affiche une notification d'erreur à l'écran.
  Sinon, l'utilisateur saisie les nouvelles donnée de l'alerte sauf le code qui
  a été généré automatiquement. Ce-dernière reste le même malgré les modifications.
  @params: pointeur de pointeur de la struct Alerte, pointeur d'entier de
  compteur d'alerte
  retourne: void
*/
void modifierAlerte(Alerte **alerte, int *iCompteurAlerte) {
  int i = 0;
  int iExisteAlerte = 0;
  char *cpType = NULL;
  char *cpNiveau = NULL;
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
      cpType = typeAlerte();
      strcpy((*alerte)[i].cType, cpType);

      printf("Niveau d'alerte :\n");
      cpNiveau = niveauAlerte();
      strcpy((*alerte)[i].cNiveau, cpNiveau);

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
/*
  La fonction supprimerAlerte(); parcours le tableau de structure d'Alerte
  et affiche à l'utilisateur alerte selon le code qu'il a saisi. Si le code est
  faux ou alerte n'existe pas, la fonction affiche une notification d'erreur à l'écran.
  Sinon, alerte sera supprimmée de la structure d'Alerte. Apès la suppression
  tous les éléments de la structure d'Alerte sont bougé pour éviter les trous.
  La mémoire est realouée et le iCompteurAlerte est diminué de 1.
  @params: pointeur de pointeur de la struct Alerte, pointeur d'entier de
  compteur d'alerte
  retourne: void
*/
void supprimerAlerte(Alerte **alerte, int *iCompteurAlerte) {
  int iCodeDonne = 0;
  int i = 0;
  int j = 0;
  int iNouvelleTaille = 0;
  int iCodeUniteQuiTraite = 0;

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
    iCodeUniteQuiTraite = (*alerte)[i].iCodeUniteQuiTraite;
    printf("DEBUG : iCodeUniteQuiTraite = %d\n", iCodeUniteQuiTraite);
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
  printf("NOTIFICATION : Alerte avec le code %d a été bien supprimé\n", iCodeDonne);
}
/*
  La fonction alertesStatiques(); crée les alertes statiques dès que le programme
  est lancé. Permet de faire des testes directs et éviter de taper les nouvelles
  alertes à chaque chargement du programme.
  @params: pointeur de pointeur de la struct Alerte, pointeur d'entier de
  compteur d'alerte
  retourne: void
*/
void alertesStatiques(Alerte **alerte, int *iCompteurAlerte) {
  (*alerte)[0].iCode = 12895;
  strcpy((*alerte)[0].cType, "URGENCE\n");
  strcpy((*alerte)[0].cNiveau, "INCENDIE\n");
  strcpy((*alerte)[0].cLieu, "Paris\n");
  (*alerte)[0].iNombreVictimes = 2;
  strcpy((*alerte)[0].cDescription, "Un incendie du Batiment SF au 5-éme arrondissement.\n");
  (*alerte)[0].iEstTraiteParUnite = 0;
  (*alerte)[0].iCodeUniteQuiTraite = 0;
  (*iCompteurAlerte)++;
  (*alerte)[1].iCode = 826;
  strcpy((*alerte)[1].cType, "NOMINAL\n");
  strcpy((*alerte)[1].cNiveau, "MALAISE\n");
  strcpy((*alerte)[1].cLieu, "Bayonne\n");
  (*alerte)[1].iNombreVictimes = 1;
  strcpy((*alerte)[1].cDescription, "Une personne a perdue connaissance à cause de la chaleur.\n");
  (*alerte)[1].iEstTraiteParUnite = 0;
  (*alerte)[1].iCodeUniteQuiTraite = 0;
  (*iCompteurAlerte)++;
}
/*
  La fonction imprimerLesAlertes(); cette fonction crée un fichier qui s'appelle
  alertes.txt et imprime toutes les alertes qui existent dans la structure d'Alerte.
  @params: pointeur de pointeur de la struct Alerte, pointeur d'entier de
  compteur d'alerte
  retourne: void
*/
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
  printf("NOTIFICATION : Les alertes ont été bien sauvegardée dans le fichier alertes.txt\n");
}
/*
  La fonction chargerLesAlertes(); lit un fichier donnée par l'utilisateur. Si
  le fichier n'existe pas ou le nom de fichier n'est pas correct, la fonction
  affiche une notification d'erreur à l'écran. Sinon, toutes les données seront
  affichées au-dessus de menu principal.
  @params: pointeur de pointeur de la struct Alerte, pointeur d'entier de
  compteur d'alerte
  retourne: void
*/
void chargerLesAlertes(Alerte **alerte, int *iCompteurAlerte) {
  FILE *file = NULL;
  int i = 0;
  char sBuffer[TAILLE_BUFFER];

  printf("Donnez le nom du fichier avec son extantion (ex: exemple.txt) : \n");
  scanf("%s%*c",sBuffer);

  file = fopen(sBuffer, "r");

  if (file == NULL) {
    printf("Erreur d'ouverture de fichier. Vérifiez que le fichier existe.\n");
    return;
   }

 printf("Les alertes chargées du fichier :\n");
 while(!feof(file)) {
    fgets(sBuffer, TAILLE_BUFFER, file);
    printf("%s", sBuffer);
  }
 fclose(file);
}
