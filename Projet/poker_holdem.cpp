#include "poker_holdem.hpp"

using namespace std;

#define _DE_ "_de_"

#define PREFLOP 0
#define FLOP 1
#define TURN 2
#define RIVER 3

void afficherCarte(Carte carte) {
  std::cout << carte.hauteur << _DE_ << carte.couleur;
}

void tour(/*TODO Stack deck, */Carte *board, Joueurs **joueurs, int nombre_joueurs, int nbTour) {

  if (nbTour == PREFLOP) {
    //TODO distribuer les cartes
    std::cout << "===========================\n";
    std::cout << "\t PREFLOP\n";
    std::cout << "===========================\n";
  } else if (nbTour == FLOP) {
    //TODO brûler 1 carte et dévoiler le flop (3 cartes)
    std::cout << "===========================\n";
    std::cout << "\t FLOP\n";
    std::cout << "===========================\n";
  } else if (nbTour == TURN) {
    //TODO brûler 1 carte et dévoiler le turn (1 carte)
    std::cout << "===========================\n";
    std::cout << "\t TURN\n";
    std::cout << "===========================\n";
  } else {
    //TODO brûler 1 carte et dévoiler le river (1 carte)
    std::cout << "===========================\n";
    std::cout << "\t RIVER\n";
    std::cout << "===========================\n";
  }

  std::cout << "Board :\n";
  //TODO afficherBoard(board);
  for (int i = 0; i < nombre_joueurs; i++) {
    std::cout << "Joueur" << i << '\n';
    std::cout << "2 carte(s) : ";
    afficherCarte(joueurs[i]->getCartes(0));
    std::cout << " ";
    afficherCarte(joueurs[i]->getCartes(1));
    //TODO afficher main + board
    std::cout << joueurs[i]->getNiveau() << '\n';
  }
}
