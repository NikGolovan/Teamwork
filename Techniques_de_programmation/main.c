#include <stdio.h>
#include <stdlib.h>

#include "alerte.c"

int main(int argc, char const *argv[]) {
  int iChoix = 0;
  int iCompteurAlerte = 0;
  int iCompteurUnite = 0;
  Alerte *alerte = NULL;
  Unites *unite = NULL;

  srand(time(NULL));

  alerte = malloc(TAILLE_INITIALE_DE_MALLOC_ALERTE  * sizeof(Alerte));

  if (alerte == NULL) {
    printf("Erreur d'allocation mémoire pour alerte\n");
    return(-1);
  }

  unite = malloc(TAILLE_INITIALE_DE_MALLOC_UNITE * sizeof(Unites));

  if (unite == NULL) {
    printf("Erreur d'allocation mémoire pour unite\n");
    return(-1);
  }

  do {
    printf("╔═══════════════════════════════════╗\n");
    printf("║                                   ║\n");
    printf("║            MENU ALERTE            ║\n");
    printf("║                                   ║\n");
    printf("╠════╦══════════════════════════════╣\n");
    printf("║    ║                              ║\n");
    printf("║ 1  ║ Créer une alerte             ║\n");
    printf("║    ║                              ║\n");
    printf("║ 2  ║ Afficher une alerte          ║\n");
    printf("║    ║                              ║\n");
    printf("║ 3  ║ Afficher toutes les alertes  ║\n");
    printf("║    ║                              ║\n");
    printf("║ 4  ║ Modifier une alerte          ║\n");
    printf("║    ║                              ║\n");
    printf("║ 5  ║ Supprimer une alerte         ║\n");
    printf("║    ║                              ║\n");
    printf("╠════╬══════════════════════════════╣\n");
    printf("║ -1 ║ Quitter                      ║\n");
    printf("╚════╩══════════════════════════════╝\n");

    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        ajouterAlerte(&alerte, &iCompteurAlerte);
        iCompteurAlerte++;

        if (iCompteurAlerte >= TAILLE_INITIALE_DE_MALLOC_ALERTE) {
          alerte = realloc(alerte, (iCompteurAlerte * sizeof(Alerte)));
          printf("DEBUG: La mémoire a été realouée\n");
        }
        printf("DEBUG: compteurAlerte après l'ajout : %d\n", iCompteurAlerte);
        break;
      case 2:
        afficherUneAlerte(&alerte, &iCompteurAlerte);
        break;
      case 3:
        afficherToutesAlertes(&alerte, &iCompteurAlerte);
        break;
      case 4:
        modifierAlerte(&alerte, &iCompteurAlerte);
        break;
      case 5:
        supprimerAlerte(&alerte, &iCompteurAlerte);
        printf("DEBUG: compteurAlerte après la suppression : %d\n", iCompteurAlerte);
        break;
      case -1:
        break;
      default:
        printf("La saisie n'est pas correcte.\n");
        break;
    }
  } while(iChoix != -1);

  free(alerte);
  free(unite);

  return 0;
}
