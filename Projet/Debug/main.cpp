#include "poker_holdem.cpp"

int main(int argc, char const *argv[]) {
  Deck deck[TAILLE_DECK];
  Joueurs *joueurs;
  int nombreJoueurs = 2;
  //Carte plateau[TAILLE_PLATEAU];
  Plateau plateau[TAILLE_PLATEAU];

  srand(time(NULL));

  remplirDeck(deck);

  joueurs = new Joueurs[nombreJoueurs];

  for (int nbTour = 0; nbTour < 4; nbTour++) {
    tour(deck, plateau, joueurs, nombreJoueurs, nbTour);
  }

  return 0;
}
