#include "poker_holdem.hpp"

using namespace std;

Carte::Carte() {
  _couleur = -1;
  _hauteur = -1;
}

Carte::~Carte() {
  _couleur = -1;
  _hauteur = -1;
}

void Carte::setHauteur(int hauteur) {
  _hauteur = hauteur;
}

void Carte::setCouleur(int couleur) {
  _couleur = couleur;
}

int Carte::getHauteur() const {
  return(_hauteur);
}

int Carte::getCouleur() const {
  return(_couleur);
}

void afficherCarte(Carte carte) {
  switch (carte.getHauteur()) {
    case 1:
      cout << "As";
      break;
    case 11:
      cout << "Valet";
      break;
    case 12:
      cout << "Dame";
      break;
    case 13:
      cout << "Roi";
      break;
    default:
      cout << carte.getHauteur();
      break;
  }

  cout << _DE_;

  switch (carte.getCouleur()) {
    case 0:
      cout << "Carreau";
      break;
    case 1:
      cout << "Cœur";
      break;
    case 2:
      cout << "Pique";
      break;
    default:
      cout << "Trefle";
      break;
  }
  cout << " ";
}

Carte tirerCarte(Deck deck[]) {
  Carte carte;

  int estTiree = 0;

  int tmpRandCouleur = rand() % 4;
  int tmpRandHauteur = rand() % 13 + 1;

  if (!deck[tmpRandHauteur].getEstUtilisee()) {
    carte.setCouleur(tmpRandCouleur);
    carte.setHauteur(tmpRandHauteur);
    deck[tmpRandHauteur].setEstUtilisee(VRAI);
    estTiree = VRAI;
  }
  return(carte);
}

Deck::Deck() {
  _carte._couleur = -1;
  _carte._hauteur = -1;
  _estUtilisee = 0;
}

Deck::~Deck() {
  _carte._couleur = -1;
  _carte._hauteur = -1;
  _estUtilisee = FAUX;
}

Carte Deck::getCartesDeck() const {
  return(_carte);
}

void Deck::setEstUtilisee(int boolean) {
  _estUtilisee = boolean;
}

int Deck::getEstUtilisee() const {
  return(_estUtilisee);
}

Joueurs::Joueurs() {
  _cartes[0]._hauteur = -1;
  _cartes[0]._couleur = -1;
  _cartes[1]._hauteur = -1;
  _cartes[1]._couleur = -1;
  _niveau = "vide";
  _nombreDeCartes = 0;
}

Joueurs::~Joueurs() {
   _cartes[0]._hauteur = -1;
   _cartes[0]._couleur = -1;
   _cartes[1]._hauteur = -1;
   _cartes[1]._couleur = -1;
   _niveau = "";
   _nombreDeCartes = 0;
 }

void Joueurs::ajouterCarte(Carte carte) {
  if (_cartes[0].getHauteur() == -1) {
    _cartes[0].setHauteur(carte._hauteur);
    _cartes[0].setCouleur(carte._couleur);
  } else {
    _cartes[1].setHauteur(carte._hauteur);
    _cartes[1].setCouleur(carte._couleur);
  }
}

Carte Joueurs::getCartes(int indexCarte) {
  return(_cartes[indexCarte]);
}

void Joueurs::setNiveau(string niveau, Carte carte) {
  string carteHaute = to_string(carte.getHauteur());

  if (niveau == CARTE_HAUTE)
    switch (carte.getHauteur()) {
      case 1:
        _niveau = niveau + "As";
        break;
      case 11:
        _niveau = niveau + "Valet";
        break;
      case 12:
        _niveau = niveau + "Dame";
        break;
      case 13:
        _niveau = niveau + "Roi";
        break;
      default:
        _niveau = niveau + carteHaute;
        break;
    }
  else if (niveau == PAIR)
    _niveau = niveau + carteHaute;
  else if (niveau == BRELAN)
    _niveau = niveau + carteHaute;
  else
      _niveau = niveau;
}

string Joueurs::getNiveau() const {
  return(_niveau);
}

void comparerPremierMain(Joueurs *joueurs, int nombreJoueurs) {
  for (int i = 0; i < nombreJoueurs; i++) {
    if (joueurs[i].getCartes(0) == joueurs[i].getCartes(1))
      joueurs[i].setNiveau(PAIR, joueurs[i].getCartes(0));
    else if (joueurs[i].getCartes(0) > joueurs[i].getCartes(1))
      joueurs[i].setNiveau(CARTE_HAUTE, joueurs[i].getCartes(0));
    else
      joueurs[i].setNiveau(CARTE_HAUTE, joueurs[i].getCartes(1));
  }
}

void remplirDeck(Deck deck[]) {
  int k = 0;

  for (int i = 0; i < 4; i++) {
    for (int j = 1; j < 14; j++) {
      deck[k]._carte.setHauteur(j);
      deck[k]._carte.setCouleur(i);
      deck[k].setEstUtilisee(FAUX);
      k++;
    }
  }
}

void distribuerCarte(Deck deck[], Joueurs *joueurs, int nombreJoueurs) {
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < nombreJoueurs; i++) {
      joueurs[i].ajouterCarte(tirerCarte(deck));
    }
  }
}


Carte Plateau::getCartesPlateau() const {
  return(_cartes);
}

void afficherBoard(Plateau *plateau) {
  for (int i = 0; i < TAILLE_PLATEAU; i++) {
    afficherCarte(plateau[i].getCartesPlateau());
  }
}

void Plateau::setCartesPlateau(Carte carte) {
  _cartes = carte;
}

void devoilerCarte(Plateau *plateau, Deck deck[]) {
  for (int i = 0; i < TAILLE_PLATEAU; i++) {
    if (!deck[i].getEstUtilisee())
      plateau[i].setCartesPlateau(deck[rand() % 13 + 1].getCartesDeck());
  }
}

void comparerMainEtPlateau(Joueurs *joueurs, Plateau *plateau, int nombreJoueurs) {
  for (int i = 0; i < nombreJoueurs; i++) {
    for (int j = 0; j < TAILLE_PLATEAU; j++) {
      if (joueurs[i].getCartes(0) == plateau[j].getCartesPlateau()
          || joueurs[i].getCartes(1) == plateau[j].getCartesPlateau())
        joueurs[i].setNiveau(PAIR, joueurs[i].getCartes(0));
    }
  }
}

 void tour(Deck deck[], Plateau *plateau, Joueurs *joueurs, int nombreJoueurs, int nombreTours) {
   int nombreDeCartes = 0;

   if (nombreTours == PREFLOP) {
    distribuerCarte(deck, joueurs, nombreJoueurs);
    std::cout << "===========================\n";
    std::cout << "\t PREFLOP\n";
    std::cout << "===========================\n";
  } else if (nombreTours == FLOP) {
    devoilerCarte(plateau, deck);
    //TODO depiler(deck);
  //  devoilerCarte(board, /*TODO sommet(deck)*/);
    //TODO depiler(deck);
  //  devoilerCarte(board, /*TODO sommet(deck)*/);
    //TODO depiler(deck);
    std::cout << "===========================\n";
    std::cout << "\t FLOP\n";
    std::cout << "===========================\n";
  } else if (nombreTours == TURN) {
  //  devoilerCarte(board, /*TODO sommet(deck)*/);
    //TODO depiler(deck);
    std::cout << "===========================\n";
    std::cout << "\t TURN\n";
    std::cout << "===========================\n";
  } else {
  //  devoilerCarte(board, /*TODO sommet(deck)*/);
    //TODO depiler(deck);
    std::cout << "===========================\n";
    std::cout << "\t RIVER\n";
    std::cout << "===========================\n";
  }

  comparerPremierMain(joueurs, nombreJoueurs);

  std::cout << "Board :\n";
  afficherBoard(plateau);
  cout << endl;
  for (int i = 0; i < nombreJoueurs; i++) {
    std::cout << "Joueur " << i << '\n';
    std::cout << "2 carte(s) : " << endl;;
    afficherCarte(joueurs[i].getCartes(0));
    std::cout << " ";
    afficherCarte(joueurs[i].getCartes(1));
    std::cout << endl;
    //TODO afficher main + board
    comparerMainEtPlateau(joueurs, plateau, nombreJoueurs);
    std::cout << joueurs[i].getNiveau() << '\n';
  }
 }

 bool operator==(const Carte& carte1, const Carte& carte2) {
   return (carte1.getHauteur() == carte2.getHauteur());
 }

 bool operator>(const Carte& carte1, const Carte& carte2) {
   return (carte1.getHauteur() > carte2.getHauteur());
 }

 ostream& operator<<(ostream& os, const Carte& carte)
{
    os << carte.getHauteur() << endl;
    return os;
}

string to_string(int carte)
{
    ostringstream ss;
    ss << carte;
    return ss.str();
}
