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

string Carte::getHauteur() const {
  switch (_hauteur) {
    case 1:
      return("As");
      break;
    case 11:
      return("Valet");
      break;
    case 12:
      return("Dame");
      break;
    case 13:
      return("Roi");
      break;
    default:
      return(to_string(_hauteur));
      break;
  }
}

int Carte::getCouleur() const {
  return(_couleur);
}

void afficherCarte(Carte carte) {
  cout << carte.getHauteur();
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

  int estTiree = FAUX;

  while (!estTiree) {

    int tmpRandCouleur = rand() % 4;
    int tmpRandHauteur = rand() % 13 + 1;

    if (!deck[tmpRandHauteur].getEstUtilisee()) {
      carte.setCouleur(tmpRandCouleur);
      carte.setHauteur(tmpRandHauteur);
      deck[tmpRandHauteur].setEstUtilisee(VRAI);
      estTiree = VRAI;
    }
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
  if (_cartes[0].getHauteur() == "-1") {
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

void Joueurs::setNiveau(string niveau) {
  _niveau = niveau;
}

string Joueurs::getNiveau() const {
  return(_niveau);
}


void Joueurs::calculerNiveau(Plateau *plateau, int nombreTours) {
  switch (nombreTours) {
    case PREFLOP:
      if (getCartes(0) == getCartes(1))
        _niveau = PAIRE + getCartes(0).getHauteur();
      else if (getCartes(0) > getCartes(1))
        _niveau = CARTE_HAUTE + getCartes(0).getHauteur();
      else
        _niveau = CARTE_HAUTE + getCartes(1).getHauteur();
      break;
    case FLOP:

      break;
    case TURN:

      break;
    default:

      break;
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

void afficherBoard(Plateau *plateau, int nombreTours) {
  switch (nombreTours) {
    case FLOP:
      cout << "3 carte(s) : ";
      for (int i = 0; i < 3; i++) {
        afficherCarte(plateau[i].getCartesPlateau());
      }
      break;
    case TURN:
      cout << "4 carte(s) : ";
      for (int i = 0; i < 4; i++) {
        afficherCarte(plateau[i].getCartesPlateau());
      }
      break;
    case RIVER:
      cout << "5 carte(s) : ";
      for (int i = 0; i < 5; i++) {
        afficherCarte(plateau[i].getCartesPlateau());
      }
      break;
    default:
      cout << "aucune carte" << endl;
      break;
  }
}

void Plateau::setCartesPlateau(Carte carte) {
  _cartes = carte;
}

void devoilerCarte(Plateau *plateau, Deck deck[], int nombreTours) {
  switch (nombreTours) {
    case FLOP:
      for (int i = 0; i < 3; i++) {
        plateau[i].setCartesPlateau(tirerCarte(deck));
      }
      break;
    case TURN:
      for (int i = 3; i < 4; i++) {
        plateau[i].setCartesPlateau(tirerCarte(deck));
      }
      break;
    case RIVER:
      for (int i = 4; i < 5; i++) {
        plateau[i].setCartesPlateau(tirerCarte(deck));
      }
      break;
    default:
      break;
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
    devoilerCarte(plateau, deck, nombreTours);
    //TODO depiler(deck);
  //  devoilerCarte(board, /*TODO sommet(deck)*/);
    //TODO depiler(deck);
  //  devoilerCarte(board, /*TODO sommet(deck)*/);
    //TODO depiler(deck);
    std::cout << "===========================\n";
    std::cout << "\t FLOP\n";
    std::cout << "===========================\n";
  } else if (nombreTours == TURN) {
    devoilerCarte(plateau, deck, nombreTours);
    //TODO depiler(deck);
    std::cout << "===========================\n";
    std::cout << "\t TURN\n";
    std::cout << "===========================\n";
  } else {
    devoilerCarte(plateau, deck, nombreTours);
    //TODO depiler(deck);
    std::cout << "===========================\n";
    std::cout << "\t RIVER\n";
    std::cout << "===========================\n";
  }


  std::cout << "Board :\n";
  afficherBoard(plateau, nombreTours);
  cout << endl;
  for (int i = 0; i < nombreJoueurs; i++) {
    std::cout << "Joueur " << i << '\n';
    std::cout << "2 carte(s) : " << endl;;
    afficherCarte(joueurs[i].getCartes(0));
    std::cout << " ";
    afficherCarte(joueurs[i].getCartes(1));
    std::cout << endl;
    //TODO afficher main + board
    joueurs[i].calculerNiveau(plateau, nombreTours);
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
