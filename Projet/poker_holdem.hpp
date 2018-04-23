#ifndef __POKER_HOLDEM_HPP
#define __POKER_HOLDEM_HPP
#include <iostream>
#include <cstring>



struct Carte {
  std::string couleur;
  std::string hauteur;
};

//TODO créer la pile de cartes pour faire le deck

class Joueurs {
private:
  Carte *_cartes;
  std::string _niveau;
  int _nbCartes; // pour ne pas dépasser le 2
public:
  Joueurs();
  ~Joueurs();
  Carte getCartes(int quelleCarte);
  std::string getNiveau();
  void calculerNiveau(Carte *board); //TODO
  void ajouterCarte(Carte carte); //TODO (facile)
};

void tour(/*TODO Stack deck, */Carte *board, Joueurs **joueurs, int nombre_joueurs, int nbTour);


#endif
