#include "poker_holdem.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  //TODO Stack<Carte> deck(52);
  Joueurs **joueurs;
  int nombre_joueurs;
  Carte *board = NULL;

  //TODO remplirDeck(deck);

  do {

    cout << "Donnez le nombre de joueurs (entre 2 et 10) : ";
    cin >> nombre_joueurs;

  } while(nombre_joueurs >= 2 && nombre_joueurs <= 10);

  joueurs = new Joueurs *[nombre_joueurs];

  for (int nbTour = 0; nbTour < 4; nbTour++) {
    tour(/*TODO deck, */board, joueurs, nombre_joueurs, nbTour);
  }


  return 0;
}
