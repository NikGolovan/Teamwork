#ifndef POKER_HOLDEM_HPP
#define POKER_HOLDEM_HPP
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

#define DEUX_CARTES_INITIALES 2
#define TAILLE_DECK 52
#define TAILLE_PLATEAU 5

#define _DE_ "_de_"

#define PREFLOP 0
#define FLOP 1
#define TURN 2
#define RIVER 3
#define VRAI 1
#define FAUX 0

#define CARTE_HAUTE "Hauteur "
#define PAIRE "Paire de "
#define DOUBLE_PAIR "Double pair de "
#define BRELAN "Brelan de "
#define QUINTE "Quinte hauteur "
#define COULEUR "Couleur de "
#define FULL "Full de "
#define CARRE "Carré de "
#define QUINTE_FLUSH "Quinte flush hauteur "
#define QUINTE_FLUSH_ROYALE "Quinte flush royale "

#define ERREUR_CARTE_EGAL_MOINS_UN "Carte vaut -1"

class Deck;
class Joueurs;

class Carte {
private:
  int _couleur;
  int _hauteur;
public:
  Carte();
  ~Carte();
  void setHauteur(int hauteur);
  void setCouleur(int couleur);
  std::string getHauteur() const;
  int getCouleur() const;
  friend class Deck;
  friend class Joueurs;
};

class Plateau : public Carte {
private:
  Carte _cartes;
public:
  //Plateau();
  //~Plateau();
  void setCartesPlateau(Carte carte);
  Carte getCartesPlateau() const;
};

class Deck {
private:
  Carte _carte;
  int _estUtilisee;
public:
  Deck();
  ~Deck();
  void setEstUtilisee(int boolean);
  int getEstUtilisee() const;
  Carte getCartesDeck() const;
  friend void remplirDeck(Deck deck[]);
};

class Joueurs {
private:
  Carte _cartes[DEUX_CARTES_INITIALES];
  std::string _niveau;
  int _nombreDeCartes;
public:
  Joueurs();
  ~Joueurs();
  Carte getCartes(int indexCarte);
  void setNiveau(std::string niveau);
  std::string getNiveau() const;
  void calculerNiveau(Plateau *plateau, int nombreTours);
  void ajouterCarte(Carte carte);
};

void tour(Deck deck[], Plateau *plateau, Joueurs *joueurs, int nombreJoueurs, int nombreTours);
void distribuerCarte(Deck deck[], Joueurs *joueurs, int nombreJoueurs);
int sommet(Carte deck[]);
void devoilerCarte(Plateau *plateau, Deck deck[], int nombreTours);
Carte tirerCarte(Deck deck[]);
void afficherCarte(Carte carte);
void afficherBoard(Plateau *plateau, int nombreTours);

bool operator==(const Carte&, const Carte&);
std::ostream& operator<<(std::ostream&, const Carte&);
bool operator>(const Carte&, const Carte&);
std::string to_string(int carte);

#endif
