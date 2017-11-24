/*
  Le module menu.c contient tous les menus du programme.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "alerte.h"
#include "unite.h"
/*
  La fonction menuGlobal(); sert pour l'affichage de menu principal.
  @params: aucun
  retourne: void
*/
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
  printf("║ 5  ║ Gestion des unités                ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 6  ║ Consultation des unités déployées ║\n");
  printf("║    ║                                   ║\n");
  printf("╠════╬═══════════════════════════════════╣\n");
  printf("║ -1 ║ Quitter                           ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}
/*
  La fonction menuTraitementAlerte(); sert pour l'affichage de sous-menu de gestion d'alertes.
  @params: aucun
  retourne: void
*/
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
  printf("║ 5  ║ Sauvegarder les données           ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 6  ║ Charger les données du fichier    ║\n");
  printf("║    ║                                   ║\n");
  printf("╠════╬═══════════════════════════════════╣\n");
  printf("║ -2 ║ Retourner                         ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}
/*
  La fonction menuNiveauAlerte(); sert pour l'affichage du choix du niveau d'alerte
  à l'utilisateur pour la saisie.
  @params: aucun
  retourne: void
*/
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
/*
  La fonction menuTypeAlerte(); sert pour l'affichage du choix du niveau d'alerte
  à l'utilisateur pour la saisie.
  @params: aucun
  retourne: void
*/
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
/*
  La fonction menuTraitementUnite(); sert pour l'affichage de sous-menu de gestion
  des unités.
  @params: aucun
  retourne: void
*/
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
  printf("║ 5  ║ Sauvegarder les données           ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 6  ║ Charger les données du fichier    ║\n");
  printf("║    ║                                   ║\n");
  printf("╠════╬═══════════════════════════════════╣\n");
  printf("║ -2 ║ Retourner                         ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}
/*
  La fonction menuDeplacementUnite(); sert pour l'affichage du choix du moyen
  de deplacement d'une unité à l'utilisateur pour la saisie.
  @params: aucun
  retourne: void
*/
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
/*
  La fonction menuDisponibiliteUnite(); sert pour l'affichage du choix du niveau
  de disponibilité d'une unité à l'utilisateur pour la saisie.
  @params: aucun
  retourne: void
*/
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
/*
  La fonction menuStatutUnite(); sert pour l'affichage du choix du statut d'une
  unité à l'utilisateur pour la saisie.
  @params: aucun
  retourne: void
*/
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
/*
  La fonction menuGestionUniteDeployee(); sert pour l'affichage du choix
  pour la gestion des unités deployées à l'utilisateur pour la saisie.
  @params: aucun
  retourne: void
*/
void menuGestionUniteDeployee() {
  printf("╔════════════════════════════════════════╗\n");
  printf("║                                        ║\n");
  printf("║       GESTION DES UNITES DEPLOYEES     ║\n");
  printf("║                                        ║\n");
  printf("╠════╦═══════════════════════════════════╣\n");
  printf("║    ║                                   ║\n");
  printf("║ 1  ║ Mettre unité en repos             ║\n");
  printf("║    ║                                   ║\n");
  printf("╠════╬═══════════════════════════════════╣\n");
  printf("║ -2 ║ Retourner                         ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}

void supprimerAlerteApresTraitement(Alerte **alerte, int *iCompteurAlerte, int *iCodeDonneUnite) {
  int i = 0;
  int j = 0;
  int iNouvelleTaille = 0;

  while (i < *iCompteurAlerte && *iCodeDonneUnite != (*alerte)[i].iCodeUniteQuiTraite) {
    i++;
  }

  if (i == *iCompteurAlerte) {
    printf("NOTIFICATION : Alerte avec le code n'a pas été trouvée.\n");
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
  printf("DEBUG : alerte après la mise d'unité en repos a été bien supprimée\n");
}
