#include "poker_holdem.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  Deck deck[TAILLE_DECK];
  Joueurs *joueurs;
  int nombreJoueurs = 0;
  Plateau plateau[TAILLE_PLATEAU];

  srand(time(NULL));

  remplirDeck(deck);

  while (nombreJoueurs < 2 || nombreJoueurs > 10) {
    std::cout << "Donnez le nombre de joueurs (2-10) : ";
    std::cin >> nombreJoueurs;
  }

  try {
    joueurs = new Joueurs[nombreJoueurs];

    if (joueurs == NULL)
      throw ERREUR_JOUEURS_EST_NULL;
  } catch (string jouers_null) {
    cout << "Erreur : " << jouers_null << endl;
    exit(-1);
  }

  for (int nbTour = 0; nbTour < 4; nbTour++) {
    tour(deck, plateau, joueurs, nombreJoueurs, nbTour);
  }

  return 0;
}
