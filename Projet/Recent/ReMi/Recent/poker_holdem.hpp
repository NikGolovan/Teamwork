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
  int getCouleur() const;
  std::string getHauteur() const;
  void setCouleur(int couleur);
  void setHauteur(int hauteur);
  void afficherCarte();
  friend class Deck;
  friend class Joueurs;
};

class Plateau{
private:
  Carte _cartes;
public:
  Plateau();
  ~Plateau();
  Carte getCartesPlateau() const;
  void setCartesPlateau(Carte carte);
};

class Deck {
private:
  Carte _carte;
  int _estUtilisee;
public:
  Deck();
  ~Deck();
  Carte getCartesDeck() const;
  int getEstUtilisee() const;
  void setEstUtilisee(bool boolean);
  friend void remplirDeck(Deck deck[]);
};

class Joueurs {
private:
  Carte _cartes[DEUX_CARTES_INITIALES];
  std::string _niveau;
  Carte _boardEtMain[DEUX_CARTES_INITIALES + TAILLE_PLATEAU];
public:
  Joueurs();
  ~Joueurs();
  Carte getCartes(int indexCarte);
  std::string getNiveau() const;
  Carte getCartesBoardEtMain(int indexCarte);
  void setNiveau(std::string niveau);
  void setCartesBoardEtMain(Carte carte, int numCarte);
  void ajouterCarte(Carte carte);
  void afficherCartesBoardEtMain(Joueurs *joueurs, int nombreTours);
  bool estQuinteFlush(int nombreTours);
  bool estCarre(int nombreTours);
  bool estFull(int nombreTours);
  bool estCouleur(int nombreTours);
  bool estQuinte(int nombreTours);
  bool estUnBrelan(int nombreTours);
  bool estDoublePaire(int nombreTours);
  bool estUnePaire(int nombreTours);
  void calculerNiveau(int nombreTours);
  std::string getCarteCarre();
  std::string getCarteFull();
  std::string getCarteCouleur();
  std::string getCarteQuinte();
  std::string getCarteBrelan();
  std::string getCarteDoublePaire();
  std::string getCartePaire();
  std::string getCarteHaute(int nombreTours);
};

void distribuerCarte(Deck deck[], Joueurs *joueurs, int nombreJoueurs);
void devoilerCarte(Plateau *plateau, Deck deck[], Joueurs *joueurs, int nombreTours);
void afficherBoard(Plateau *plateau, int nombreTours);
void tour(Deck deck[], Plateau *plateau, Joueurs *joueurs, int nombreJoueurs, int nombreTours);
void trierTableau(int tab[]);
Carte tirerCarte(Deck deck[]);

bool operator==(const Carte&, const Carte&);
std::ostream& operator<<(std::ostream&, const Carte&);
bool operator>(const Carte&, const Carte&);
std::string to_string(int carte);

#endif
