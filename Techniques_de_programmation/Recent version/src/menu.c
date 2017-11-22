#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "alerte.h"
#include "unite.h"

void menuGlobal(){
  printf("╔════════════════════════════════════════╗\n");
  printf("║                                        ║\n");
  printf("║     GESTION GLOBALISEE DES SECOURS     ║\n");
  printf("║                                        ║\n");
  printf("╠════╦═══════════════════════════════════╣\n");
  printf("║    ║                                   ║\n");
  printf("║ 1  ║ Déclenchement d'une alerte        ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 2  ║ Nouvelle alerte                   ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 3  ║ Créer une unité                   ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 4  ║ Traitement des alertes            ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 5  ║ Gestion des unités disponibles    ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 6  ║ Consultation des unités déployées ║\n");
  printf("║    ║                                   ║\n");
  printf("╠════╬═══════════════════════════════════╣\n");
  printf("║ -1 ║ Quitter                           ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
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

void menuNiveauAlerte() {
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
}

void menuTypeAlerte() {
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
}



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

void menuDeplacementUnite() {
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
}

void menuDisponibiliteUnite() {
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
}

void menuStatutUnite() {
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
  char cUniteEnRepos[TAILLE_BUFFER] = "Disponibilité : EN REPOS";

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
    printf("CAS DE FORCE MAJEURE\n");
    printf("1. Faire intervenir les unités en repos ou en reapprovisionnement -2 pour retourner\n");
    scanf("%d%*c", &iChoix);

    switch(iChoix) {
      case 1:
        for (i = 0; i < *iCompteurUnite; i++) {
          if (strcmp((*unite)[i].cNiveauDisponibilite, cUniteEnRepos) != 1) {
            printf("Aucune unités est en repos\n");
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
       printf("La saisie n'est pas correcte.\n");
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
    printf("Alerte avec le code %d n'a pas été trouvée.\n", iCodeDonneAlerte);
    return;
  }

  printf("Donnez code d'unité à envoyer : \n");
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
  (*unite)[iTmpPositionUnite].iCompteurRepos += 1;
  strcpy((*unite)[iTmpPositionUnite].cNiveauDisponibilite, "ACTIVITE\n");
  strcpy((*unite)[iTmpPositionUnite].cStatut, "EN ALERTE\n");
  (*unite)[iTmpPositionUnite].iDeployeeSurAlerte = iCodeDonneAlerte;
  (*unite)[iTmpPositionUnite].iUniteDisponible = 0;
}
