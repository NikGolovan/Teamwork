#include "poker_holdem.hpp"
#include "defines.hpp"

using namespace std;
/*---------------------------------------------*/
/* Fonctions de la classe Carte                */
Carte::Carte() {
  _couleur = -1;
  _hauteur = -1;
}

Carte::~Carte() {
  _couleur = -1;
  _hauteur = -1;
}

int Carte::getCouleur() const {
  return(_couleur);
}

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

void Carte::setCouleur(int couleur) {
  _couleur = couleur;
}

void Carte::setHauteur(int hauteur) {
  _hauteur = hauteur;
}

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
Plateau::Plateau() {
  //_cartes._couleur = -1;
  //_cartes._hauteur = -1;
}

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
    _cartes[0].setHauteur(2);
    _cartes[0].setCouleur(1);
    _boardEtMain[0].setHauteur(2);
    _boardEtMain[0].setCouleur(1);
  } else {
    _cartes[1].setHauteur(3);
    _cartes[1].setCouleur(2);
    _boardEtMain[1].setHauteur(3);
    _boardEtMain[1].setCouleur(2);
  }
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
      if (estCarre(plateau))
        _niveau = CARRE + getCartes(0).getHauteur();
      else if (estFull(plateau))
      _niveau = FULL + getCartes(0).getHauteur();
      else if (estQuinte(plateau))
       _niveau = QUINTE + getCartes(0).getHauteur();
      else if (estCouleur(plateau))
        _niveau = COULEUR + getCartes(0).getHauteur(); //TODO: il affiche toujours la premiere carte pour la couleur
      else if (estUnBrelan(plateau))
        _niveau = BRELAN + getCartes(0).getHauteur();
      else if (estDoublePaire(plateau))
        _niveau = DOUBLE_PAIR + getCartes(0).getHauteur(); // TODO: ajouter + " et de " +
      else if (estUnePairePcarte(plateau))
        _niveau = PAIRE + getCartes(0).getHauteur();
      else if (estUnePaireDcarte(plateau))
        _niveau = PAIRE + getCartes(1).getHauteur();
      break;
  }
}

int Joueurs::convertirCartesBoardEtMainEnEntier() {
  string carteChaine = getCartes(0).getHauteur();

  stringstream convertir(carteChaine);
  int carteEntier = 0;
  convertir >> carteEntier;

  return(carteEntier);
}

// TODO: ameliorer carre
bool Joueurs::estCarre(Plateau *plateau) {
  int compteur = 0;

  if (getCartes(0) == getCartes(1)) {
    compteur -= 1;
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
      if (getCartes(0) == plateau[i+1].getCartesPlateau())
      compteur++;
      // when fourth card is at the end but doesnt work if
      // we get four card in a row
      if (i == TAILLE_PLATEAU-1) {
        for (int i = TAILLE_PLATEAU; i > 0; i--)
        if (plateau[TAILLE_PLATEAU].getCartesPlateau() == plateau[i].getCartesPlateau())
        compteur++;
      }
    }
  } else {
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
      if (getCartes(0) == plateau[i+1].getCartesPlateau())
      compteur++;
      // when fourth card is at the end but doesnt work if
      // we get four card in a row
      if (i == TAILLE_PLATEAU-1) {
        for (int i = TAILLE_PLATEAU; i > 0; i--)
        if (plateau[TAILLE_PLATEAU].getCartesPlateau() == plateau[i].getCartesPlateau())
        compteur++;
      }
    }
  }

  if (compteur == 3 || compteur == 4)
  return true;
  else
  return false;
}

// TODO: ameliorer full
bool Joueurs::estFull(Plateau *plateau) {
  int compteur = 0;

  if (getCartes(0) == getCartes(1)) {
    compteur += 1;
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
      if (plateau[i].getCartesPlateau() == plateau[i+1].getCartesPlateau())
      compteur++;
    }
  } else {
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
      if (plateau[i].getCartesPlateau() == plateau[i+1].getCartesPlateau())
      compteur++;
    }
  }

  if (compteur == 3 || compteur == 2)
  return true;
  else
  return false;
}

bool Joueurs::estCouleur(Plateau *plateau) {
  int compteur = 0;

  // TODO: verifier s'il n'y a pas de suite coloree

  for(int i = 0; i  < TAILLE_PLATEAU; i++)
    if((getCartes(0).getCouleur() == plateau[i].getCartesPlateau().getCouleur())
        || (getCartes(1).getCouleur() == plateau[i].getCartesPlateau().getCouleur()))
      compteur++;

  if (getCartes(0).getCouleur() == getCartes(1).getCouleur())
    compteur += 1;

  if (compteur >= 5)
    return true;
  else
    return false;
}

// TODO: faire quinte pour deuxieme main
bool Joueurs::estQuinte(Plateau *plateau) {
  int compteur = 0;
  int tab[TAILLE_PLATEAU] = {0, 0, 0, 0, 0};
  string carteChaine;
  int carteEntier = 0;

  carteEntier = convertirCartesBoardEtMainEnEntier();

  for (int i = 0; i < TAILLE_PLATEAU; i++) {
    tab[i] = convertirCartesBoardEtMainEnEntier();
  }

  for (int i = 0; i < TAILLE_PLATEAU; i++) {
    if ((carteEntier) == tab[i+1])
    compteur++;
  }

  if (compteur == 5)
  return true;
  else
  return false;
}

bool Joueurs::estUnBrelan(Plateau *plateau) {
  int compteur = 0;

  // TODO: Traiter le cas avec brelan sur le plateau
  for (int i = 0; i < TAILLE_PLATEAU; i++) {
    if ((getCartes(0) == getCartes(1)) && (getCartes(0) == plateau[i].getCartesPlateau()
          || getCartes(1) == plateau[i].getCartesPlateau()))
        compteur++;
  }

  if (compteur == 1)
    return true;
  else
    return false;
}

// TODO: double paire marche pas des fois
bool Joueurs::estDoublePaire(Plateau *plateau) {
  int compteur = 0;

  for (int i = 0; i < TAILLE_PLATEAU; i++) {
    if ((getCartes(0) == getCartes(1)) && (getCartes(0) == plateau[i].getCartesPlateau()
          || getCartes(1) == plateau[i].getCartesPlateau()))
        compteur++;
  }

  if (compteur == 2)
    return true;
  else
    return false;
}

bool Joueurs::estUnePaireDcarte(Plateau *plateau) {
  bool estPaire = FAUX;

  for (int i = 0; i < TAILLE_PLATEAU; i++) {
    if (getCartes(1) == plateau[i].getCartesPlateau())
        estPaire = VRAI;
  }
  return(estPaire);
}

bool Joueurs::estUnePairePcarte(Plateau *plateau) {
  bool estPaire = FAUX;

  for (int i = 0; i < TAILLE_PLATEAU; i++) {
    if (getCartes(0) == plateau[i].getCartesPlateau())
        estPaire = VRAI;
  }
  return(estPaire);
}

/*---------------------------------------------*/
/* Fonctions hors des classes                  */
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

  test.setHauteur(4);
  test.setCouleur(1);

  test2.setHauteur(5);
  test2.setCouleur(3);

  switch (nombreTours) {
    case FLOP:
      for (int i = 0; i < 3; i++) {
        plateau[i].setCartesPlateau(tirerCarte(deck));
        for (int j = 0; j < nombreJoueurs; j++) {
          joueurs[j].setCartesBoardEtMain(plateau[i].getCartesPlateau(), i);
        }
      }
      break;
    case TURN:
      plateau[3].setCartesPlateau(test);
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
}

void afficherBoard(Plateau *plateau, int nombreTours) {
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
      //TODO depiler(deck);
      //devoilerCarte(board, /*TODO sommet(deck)*/);
      //TODO depiler(deck);
      //devoilerCarte(board, /*TODO sommet(deck)*/);
      //TODO depiler(deck);
      std::cout << "╔═════════════════════════╗\n";
      std::cout << "║          FLOP           ║\n";
      std::cout << "╚═════════════════════════╝\n";
      break;
     case TURN:
      devoilerCarte(plateau, deck, joueurs, nombreJoueurs, nombreTours);
      //TODO depiler(deck);
      std::cout << "╔═════════════════════════╗\n";
      std::cout << "║          TURN           ║\n";
      std::cout << "╚═════════════════════════╝\n";
      break;
     case RIVER:
      devoilerCarte(plateau, deck, joueurs, nombreJoueurs, nombreTours);
      //TODO depiler(deck);
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

ostream& operator<<(ostream& os, const Carte& carte) {
  os << carte.getHauteur() << endl;
  return os;
}

string to_string(int carte) {
  ostringstream ss;
  ss << carte;
  return ss.str();
}
