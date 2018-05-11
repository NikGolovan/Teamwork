#include "poker_holdem.hpp"
#include "defines.hpp"

using namespace std;
/*---------------------------------------------*/
/* Fonctions de la classe Carte                */
/*---------------------------------------------*/

/* Constructeur de Cartes                      */
Carte::Carte() {
  _couleur = -1;
  _hauteur = -1;
}

/* Destructeur de Cartes                       */
Carte::~Carte() {
  _couleur = -1;
  _hauteur = -1;
}

/* retourne la couleur de Cartes               */
int Carte::getCouleur() const {
  return(_couleur);
}

/* retourne la hauteur de Cartes               */
string Carte::getHauteur() const {
  switch (_hauteur) {
    case 1:
      return(AS);
      break;
    case 11:
      return(VALET);
      break;
    case 12:
      return(DAME);
      break;
    case 13:
      return(ROI);
      break;
    default:
      return(to_string(_hauteur));
      break;
  }
}

/* initialise la couleur de Cartes             */
void Carte::setCouleur(int couleur) {
  _couleur = couleur;
}

/* initialise la hauteur de Cartes             */
void Carte::setHauteur(int hauteur) {
  _hauteur = hauteur;
}

/* affichage de Cartes                         */
void Carte::afficherCarte() {
  cout << getHauteur();
  cout << _DE_;

  switch (getCouleur()) {
    case 0:
      cout << CARREAU;
      break;
    case 1:
      cout << COEUR;
      break;
    case 2:
      cout << PIQUE;
      break;
    default:
      cout << TREFLE;
      break;
  }
  cout << " ";
}

/*---------------------------------------------*/
/* Fonctions de la classe Plateau              */
/*---------------------------------------------*/

/* Constructeur de Plateau                     */
Plateau::Plateau() {
  //_cartes._couleur = -1;
  //_cartes._hauteur = -1;
}

/* Destructeur de Plateau                      */
Plateau::~Plateau() {
  //_cartes._couleur = -1;
  //_cartes._hauteur = -1;
}

Carte Plateau::getCartesPlateau() const {
  return(_cartes);
}

void Plateau::setCartesPlateau(Carte carte) {
  _cartes = carte;
}

/*---------------------------------------------*/
/* Fonctions de la classe Deck                 */
/*---------------------------------------------*/

/* Constructeur de Deck                        */
Deck::Deck() {
  _carte._couleur = -1;
  _carte._hauteur = -1;
  _estUtilisee = 0;
}

/* Destructeur de Deck                         */
Deck::~Deck() {
  _carte._couleur = -1;
  _carte._hauteur = -1;
  _estUtilisee = FAUX;
}

Carte Deck::getCartesDeck() const {
  return(_carte);
}

int Deck::getEstUtilisee() const {
  return(_estUtilisee);
}

void Deck::setEstUtilisee(int boolean) {
  _estUtilisee = boolean;
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

/*---------------------------------------------*/
/* Fonctions de la classe Joueurs              */
/*---------------------------------------------*/

/* Constructeur de Joueurs                     */
Joueurs::Joueurs() {
  for (int i = 0; i < DEUX_CARTES_INITIALES; i++) {
    _cartes[i]._hauteur = -1;
    _cartes[i]._couleur = -1;
  }
  _niveau = "vide";
  _nombreDeCartes = 0;
  for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; i++) {
    _boardEtMain[i]._hauteur = -1;
    _boardEtMain[i]._couleur = -1;
  }
}

/* Destructeur de Joueurs                      */
Joueurs::~Joueurs() {
  for (int i = 0; i < DEUX_CARTES_INITIALES; i++) {
    _cartes[i]._hauteur = -1;
    _cartes[i]._couleur = -1;
  }
  _niveau = "";
  _nombreDeCartes = 0;
  for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; i++) {
    _boardEtMain[i]._hauteur = -1;
    _boardEtMain[i]._couleur = -1;
  }
 }

Carte Joueurs::getCartes(int indexCarte) {
  return(_cartes[indexCarte]);
}

string Joueurs::getNiveau() const {
  return(_niveau);
}

Carte Joueurs::getCartesBoardEtMain(int indexCarte) {
  return(_boardEtMain[indexCarte]);
}

void Joueurs::setNiveau(string niveau) {
  _niveau = niveau;
}

void Joueurs::setCartesBoardEtMain(Carte carte, int numCarte) {
  _boardEtMain[numCarte + DEUX_CARTES_INITIALES] = carte;
}

void Joueurs::ajouterCarte(Carte carte) {
  if (_cartes[0].getHauteur() == "-1") {
    _cartes[0].setHauteur(carte._hauteur);
    _cartes[0].setCouleur(carte._couleur);
    _boardEtMain[0].setHauteur(carte._hauteur);
    _boardEtMain[0].setCouleur(carte._couleur);
  } else {
    _cartes[1].setHauteur(carte._hauteur);
    _cartes[1].setCouleur(carte._couleur);
    _boardEtMain[1].setHauteur(carte._hauteur);
    _boardEtMain[1].setCouleur(carte._couleur);
  }
}

void trierTableauPourQuinte(int tab[]) {
  for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1; i++) {
    for (int j = 0; j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - i - 1; j++) {
      if (tab[j] > tab[j + 1]) {
        int temp = tab[j];
        tab[j] = tab[j + 1];
        tab[j + 1] = temp;
      }
    }
  }
}

void Joueurs::calculerNiveau(int nombreTours) {
/*  if (estCarre(nombreTours))
    _niveau = CARRE;*/
  if (estFull(nombreTours))
    _niveau = FULL;
  else if (estCouleur(nombreTours))
    _niveau = COULEUR;
  else if (estQuinte(nombreTours))
    _niveau = QUINTE;
  else if (estUnBrelan(nombreTours))
    _niveau = BRELAN;
  else if (estDoublePaire(nombreTours))
    _niveau = DOUBLE_PAIR; // TODO: ajouter + " et de " +
  else if (estUnePaire(nombreTours))

    _niveau = PAIRE;
  else
    _niveau = CARTE_HAUTE;
}

/*---------------------------------------------*/
/* Fonctions hors des classes                  */
/*---------------------------------------------*/

void distribuerCarte(Deck deck[], Joueurs *joueurs, int nombreJoueurs) {
  Carte test;

  test.setHauteur(1);
  test.setCouleur(3);

  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < nombreJoueurs; i++) {
      joueurs[i].ajouterCarte(tirerCarte(deck));
    }
  }
}

void devoilerCarte(Plateau *plateau, Deck deck[], Joueurs *joueurs, int nombreJoueurs, int nombreTours) {
  Carte test;
  Carte test2;

  test.setHauteur(1);
  test.setCouleur(2);

  test2.setHauteur(5);
  test2.setCouleur(2);

  try {
    switch (nombreTours) {
      case FLOP:
        for (int i = 0; i < 3; i++) {
          plateau[i].setCartesPlateau(test);
          for (int j = 0; j < nombreJoueurs; j++) {
            joueurs[j].setCartesBoardEtMain(plateau[i].getCartesPlateau(), i);
          }
        }
        break;
      case TURN:
        plateau[3].setCartesPlateau(test2);
        for (int j = 0; j < nombreJoueurs; j++) {
          joueurs[j].setCartesBoardEtMain(plateau[3].getCartesPlateau(), 3);
        }
        break;
      case RIVER:
        plateau[4].setCartesPlateau(test2);
        for (int j = 0; j < nombreJoueurs; j++) {
          joueurs[j].setCartesBoardEtMain(plateau[4].getCartesPlateau(), 4);
        }
        break;
      default:
        break;
    }
  } catch (string s) {
    cout << "Erreur : " << ERREUR_DEVOILER_CARTE << endl;
  }

}

void afficherBoard(Plateau *plateau, int nombreTours) {
  try {
    if (plateau == NULL) {
      throw ERREUR_PLATEAU_NULL;
      exit(-1);
    }
    switch (nombreTours) {
      case FLOP:
        cout << "3 carte(s) : ";
        for (int i = 0; i < 3; i++) {
          plateau[i].getCartesPlateau().afficherCarte();
        }
        break;
      case TURN:
        cout << "4 carte(s) : ";
        for (int i = 0; i < 4; i++) {
          plateau[i].getCartesPlateau().afficherCarte();
        }
        break;
      case RIVER:
        cout << "5 carte(s) : ";
        for (int i = 0; i < 5; i++) {
          plateau[i].getCartesPlateau().afficherCarte();
        }
        break;
      default:
        cout << "aucune carte" << endl;
        break;
    }
  } catch (string plateau_null) {
    std::cout << "Erreur : " << plateau_null << endl;
  }
}

void Joueurs::afficherCartesBoardEtMain(Joueurs *joueurs, int nombreTours) {
  switch (nombreTours) {
    case PREFLOP:
      for (int j = 0; j < 2; j++) {
        this->getCartesBoardEtMain(j).afficherCarte();
        std::cout << " ";
      }
      break;
    case FLOP:
    for (int j = 0; j < 5; j++) {
      this->getCartesBoardEtMain(j).afficherCarte();
      std::cout << " ";
      }
      break;
    case TURN:
    for (int j = 0; j < 6; j++) {
      this->getCartesBoardEtMain(j).afficherCarte();
      std::cout << " ";
      }
      break;
    default:
    for (int j = 0; j < 7; j++) {
      this->getCartesBoardEtMain(j).afficherCarte();
      std::cout << " ";
      }
      break;
    }
}

void tour(Deck deck[], Plateau *plateau, Joueurs *joueurs, int nombreJoueurs, int nombreTours) {
  int nombreDeCartes = 0;

  switch (nombreTours) {
    case PREFLOP:
      distribuerCarte(deck, joueurs, nombreJoueurs);
      std::cout << "╔═════════════════════════╗\n";
      std::cout << "║         PREFLOP         ║\n";
      std::cout << "╚═════════════════════════╝\n";
      break;
    case FLOP:
      devoilerCarte(plateau, deck, joueurs, nombreJoueurs, nombreTours);
      std::cout << "╔═════════════════════════╗\n";
      std::cout << "║          FLOP           ║\n";
      std::cout << "╚═════════════════════════╝\n";
      break;
     case TURN:
      devoilerCarte(plateau, deck, joueurs, nombreJoueurs, nombreTours);
      std::cout << "╔═════════════════════════╗\n";
      std::cout << "║          TURN           ║\n";
      std::cout << "╚═════════════════════════╝\n";
      break;
     case RIVER:
      devoilerCarte(plateau, deck, joueurs, nombreJoueurs, nombreTours);
      std::cout << "╔═════════════════════════╗\n";
      std::cout << "║          RIVER          ║\n";
      std::cout << "╚═════════════════════════╝\n";
      break;
    default:
      std::cout << "╔═════════════════════════╗\n";
      std::cout << "║      FIN DE PARTIE      ║\n";
      std::cout << "╚═════════════════════════╝\n";
      break;
   }

  std::cout << "Board :\n";
  afficherBoard(plateau, nombreTours);
  cout << endl;
  for (int i = 0; i < nombreJoueurs; i++) {
    std::cout << "Joueur " << i << '\n';
    std::cout << "2 carte(s) : " << endl;;
    joueurs[i].getCartes(0).afficherCarte();
    std::cout << " ";
    joueurs[i].getCartes(1).afficherCarte();
    std::cout << endl;
    std::cout << "avec le board : ";
    joueurs[i].afficherCartesBoardEtMain(joueurs, nombreTours);
    std::cout << endl;
    joueurs[i].calculerNiveau(nombreTours);
    std::cout << joueurs[i].getNiveau() << '\n';
  }
}

bool operator==(const Carte& carte1, const Carte& carte2) {
  return (carte1.getHauteur() == carte2.getHauteur());
}

bool operator>(const Carte& carte1, const Carte& carte2) {
  return (carte1.getHauteur() > carte2.getHauteur());
}

ostream& operator<<(ostream& os, const Carte& carte) {
  os << carte.getHauteur() << endl;
  return os;
}

string to_string(int carte) {
  ostringstream ss;
  ss << carte;
  return ss.str();
}
