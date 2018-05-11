#include "poker_holdem.cpp"

int main(int argc, char const *argv[]) {
  Deck deck[TAILLE_DECK];
  Joueurs *joueurs;
  int nombreJoueurs = 2;
  Plateau plateau[TAILLE_PLATEAU];

  srand(time(NULL));

  remplirDeck(deck);

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
