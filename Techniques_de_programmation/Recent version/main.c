#include <stdio.h>
#include <stdlib.h>

#include "alerte.h"
#include "unite.h"
#include "menu.c"

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
    menuGlobal();

    scanf("%d%*c", &iChoix);

    switch (iChoix) {
      case 1:
        declancherAlerte(&alerte, &unite, &iCompteurAlerte, &iCompteurUnite);
        mettreUniteEnRepos(&unite, &iCompteurUnite);
        break;
      case 2:
        ajouterAlerte(&alerte, &iCompteurAlerte);
        iCompteurAlerte++;

        if (iCompteurAlerte >= TAILLE_INITIALE_DE_MALLOC_ALERTE) {
          alerte = realloc(alerte, ((iCompteurAlerte+1) * sizeof(Alerte)));
          printf("DEBUG: La mémoire a été realouée\n");
        }
        break;
      case 3:
        creerUnite(&unite, &iCompteurUnite);
        iCompteurUnite++;

        if (iCompteurUnite >= TAILLE_INITIALE_DE_MALLOC_UNITE) {
          unite = realloc(unite, ((iCompteurUnite+1) * sizeof(Unites)));
          printf("DEBUG: La mémoire a été realouée\n");
        }
        break;
      case 4:
        do {
          menuTraitementAlerte();

          scanf("%d%*c", &iChoix);

          switch (iChoix) {
            case 1:
              afficherUneAlerte(&alerte, &iCompteurAlerte);
              break;
            case 2:
              modifierAlerte(&alerte, &iCompteurAlerte);
              break;
            case 3:
              afficherToutesAlertes(&alerte, &iCompteurAlerte);
              break;
            case 4:
              supprimerAlerte(&alerte, &iCompteurAlerte);
              printf("DEBUG: compteurAlerte après la suppression : %d\n", iCompteurAlerte);
              break;
            case -2:
              break;
            default:
              printf("La saisie n'est pas correcte.\n");
              break;
          }
        } while(iChoix != -2);
        break;
      case 5:
      do {
        menuTraitementUnite();

        scanf("%d%*c", &iChoix);

        switch (iChoix) {
          case 1:
            afficherUneUnite(&unite, &iCompteurUnite);
            break;
          case 2:
            afficherToutesUnites(&unite, &iCompteurUnite);
            break;
          case 3:
            modifierUnite(&unite, &iCompteurUnite);
            break;
          case 4:
            supprimerUnite(&unite, &iCompteurUnite);
            printf("DEBUG: compteurUnite après la suppression : %d\n", iCompteurAlerte);
            break;
          case -2:
            break;
          default:
            printf("La saisie n'est pas correcte.\n");
            break;
        }
      } while(iChoix != -2);
        break;
      case 6:
        printf("Ici le traitement des unités deployées\n");
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
