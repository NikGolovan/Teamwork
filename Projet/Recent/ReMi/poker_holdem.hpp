/*
  poker_holdem.hpp
  @auteurs : GOLOVAN Mykola && LACROIX Rémi
*/

#ifndef __POKER_HOLDEM_HPP
#define __POKER_HOLDEM_HPP
#include "defines.hpp"
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <typeinfo>

/*
  Prédéfinition des classes Deck && Joueurs
*/
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
  Plateau();
  ~Plateau();
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
  Carte _boardEtMain[DEUX_CARTES_INITIALES + TAILLE_PLATEAU];
public:
  Joueurs();
  ~Joueurs();
  Carte getCartes(int indexCarte);
  Carte getCartesBoardEtMain(int indexCarte);
  void setNiveau(std::string niveau);
  std::string getNiveau() const;
  void calculerNiveau(Plateau *plateau, int nombreTours);
  void ajouterCarte(Carte carte);
  void setCartesBoardEtMain(Carte carte, int numCarte);
  int convertirCarteEnEntier();
  int convertirPlateauEnEntier(Plateau *plateau, int pos);
  bool estUnePairePcarte(Plateau *plateau);
  bool estUnePaireDcarte(Plateau *plateau);
  bool estDoublePaire(Plateau *plateau);
  bool estUnBrelan(Plateau *plateau);
  bool estQuinte(Plateau *plateau);
  bool estCouleur(Plateau *plateau);
  bool estFull(Plateau *plateau);
  bool estCarre(Plateau *plateau);
};

void tour(Deck deck[], Plateau *plateau, Joueurs *joueurs, int nombreJoueurs, int nombreTours);
void distribuerCarte(Deck deck[], Joueurs *joueurs, int nombreJoueurs);
int sommet(Carte deck[]);
void devoilerCarte(Plateau *plateau, Deck deck[], Joueurs *joueurs, int nombreTours);
Carte tirerCarte(Deck deck[]);
void afficherCarte(Carte carte);
void afficherBoard(Plateau *plateau, int nombreTours);

bool operator==(const Carte&, const Carte&);
std::ostream& operator<<(std::ostream&, const Carte&);
bool operator>(const Carte&, const Carte&);
std::string to_string(int carte);

#endif
