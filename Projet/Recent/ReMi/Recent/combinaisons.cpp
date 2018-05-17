/*
  poker_holdem.cpp
  Ce fichier consiste des fonctions générales et des constructeurs des classes
  @auteurs : GOLOVAN Mykola && LACROIX Rémi
*/

#include "poker_holdem.hpp"
#include "defines.hpp"

using namespace std;
/*---------------------------------------------*/
/* Fonctions de la classe Carte                */
/*---------------------------------------------*/

/*
  Constructeur de la classe Carte.
  Initialise hauteur et couleur de la carte à -1.
*/
Carte::Carte() {
  _couleur = -1;
  _hauteur = -1;
}

/*
  Destructeur de la classe Carte.
  Initialise hauteur et couleur de la carte à -1,
  ce que simule la destruction.
*/
Carte::~Carte() {
  _couleur = -1;
  _hauteur = -1;
}

/*
  Le getteur de la class carte.
  @return : couleur de la carte.
*/
int Carte::getCouleur() const {
  return(_couleur);
}

/*
  Le getteur de la classe Carte.
  Principe : On vérifie hauteur de la carte,
  1 vaut AS,  13 vaut ROI, 12 vaut DAME et 11 vaut VALET.
  @return string : hauteur de la carte.
*/
string Carte::getHauteur() const {
  switch (_hauteur) {
    case 11:
      return(VALET);
      break;
    case 12:
      return(DAME);
      break;
    case 13:
      return(ROI);
      break;
    case 14:
      return(AS);
      break;
    default:
      /* La fonction qui converti hauteur en chaîne de caractères
        pour ensuite pouvoir l'afficher dans la console en tant que niveau. */
      return(to_string(_hauteur));
      break;
  }
}

/*
  Le setteur de la classe Carte.
  Affectue une couleur à une carte.
  @param int : couleur de la carte.
*/
void Carte::setCouleur(int couleur) {
  _couleur = couleur;
}

/*
  Le setteur de la classe Carte.
  Affectue une hauteur à une carte.
  @param int : hauteur de la carte.
*/
void Carte::setHauteur(int hauteur) {
  _hauteur = hauteur;
}

/*
  Fonction affiche les cartes de chaque joueur.
*/
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

/*
  Constructeur de la classe Plateau.
  Initialise hauteur et couleur de la carte à -1.
*/
Plateau::Plateau() {
  //_cartes._couleur = -1;
  //_cartes._hauteur = -1;
}

/*
  Destructeur de la classe Plateau.
  Initialise hauteur et couleur de la carte à -1.
*/
Plateau::~Plateau() {
  //_cartes._couleur = -1;
  //_cartes._hauteur = -1;
}

/*
  Le getteur de la classe Plateau.
  @return Carte : une carte.
*/
Carte Plateau::getCartesPlateau() const {
  return(_cartes);
}

/*
  Le setteur de la classe Plateau.
  Affectue une carte à une carte de la classe Plateau.
*/
void Plateau::setCartesPlateau(Carte carte) {
  _cartes = carte;
}

/*---------------------------------------------*/
/* Fonctions de la classe Deck                 */
/*---------------------------------------------*/

/*
  Constructeur de la classe Deck.
  Initialise hauteur et couleur de la carte à -1 et booleen à faux.
*/
Deck::Deck() {
  _carte._couleur = -1;
  _carte._hauteur = -1;
  _estUtilisee = false;
}

/*
  Destructeur de la classe Deck.
  Initialise hauteur et couleur de la carte à -1 et booleen à faux.
*/
Deck::~Deck() {
  _carte._couleur = -1;
  _carte._hauteur = -1;
  _estUtilisee = false;
}

/*
  Le getteur de la classe Deck.
  @return Carte : une carte.
*/
Carte Deck::getCartesDeck() const {
  return(_carte);
}

/*
  Le setteur de la classe Deck.
  Initialise le booleen.
  @param booleen : booleen.
*/
void Deck::setEstUtilisee(bool boolean) {
  _estUtilisee = boolean;
}

/*
  Le getteur de la classe Deck.
  @return booleen : un booleen.
*/
int Deck::getEstUtilisee() const {
  return(_estUtilisee);
}

/*
  Fonction rempli le deck avec 52 carte.
  Le booleen d'utilisation de chaque carte mise dans le deck est
  initialisé à faux car les cartes n'étaient pas encore mises sur plateau.

  Principe : Une variable de type entier k qui sert comme index des cases
  du tableau et qui incremente à chaque tour des boucles. Première boucle
  sert pour réinitialiser les couleurs et la deuxième pour les hauters.

  @param Deck : tableau de deck.
*/
void remplirDeck(Deck deck[]) {
  int k = 0;

  /* couleurs */
  for (int i = 0; i < 4; i++) {
    /* hauteurs */
    for (int j = 2; j < 15; j++) {
      /* initialisation */
      deck[k]._carte.setHauteur(j);
      deck[k]._carte.setCouleur(i);
      deck[k].setEstUtilisee(false);
      k++;
    }
  }
}

/*
  Fonction renvoi une carte qui a été tirée du deck de façon aléatoire.
  Le booleen de chaque carte _estUtilisee est initialisé à vrai.

  Principe : Une variable de type carte va prendre une couleur et un hauteur
  generés de façon aléatoire. Pour éviter de mettre les mêmes cartes sur le
  plateau, on vérifie si la carte a été déjà prise. Si oui, on continue la boucle
  tant qu'on n'a pas trové carte non-utilisée. Sinon, on prend la carte et
  initialise le booleen à vrai.

  @param Deck : tableau de deck.
  @return Carte : une carte.
*/
Carte tirerCarte(Deck deck[]) {
  Carte carte;
  int i = 0;
  /* sert pour sortir de la boucle */
  int estTiree = false;

  while (!estTiree) {
    /* contient couleur aléatoire  */
    int tmpRandCouleur = rand() % 4;
    /* contient hauteur aléatoire  */
    int tmpRandHauteur = rand() % 13 + 2;

    if (!deck[tmpRandHauteur].getEstUtilisee()) {
      /* affectation de la couleur */
      carte.setCouleur(tmpRandCouleur);
      /* affectation du hauteur */
      carte.setHauteur(tmpRandHauteur);
      /* initialisation du booleen à vrai */
      deck[i].setEstUtilisee(true);
      estTiree = true;
    }
    i++;
  }
  return(carte);
}

/*---------------------------------------------*/
/* Fonctions de la classe Joueurs              */
/*---------------------------------------------*/

/*
  Constructeur de la classe Joueurs.
  Initialise hauteur et couleur de la carte de chaque joueur à -1.
*/
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

/*
  Destructeur de la classe Joueurs.
  Initialise hauteur et couleur de la carte de chaque joueur à -1.
*/
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

 /*
   Le getteur de la classe Joueurs.

   @param int : index de la carte.
   @return Carte : une carte.
 */
Carte Joueurs::getCartes(int indexCarte) {
  return(_cartes[indexCarte]);
}

/*
  Le getteur de la classe Joueurs.

  @return string : le niveau de la main du joueur.
*/
string Joueurs::getNiveau() const {
  return(_niveau);
}

/*
  Le getteur de la classe Joueurs.
  Renvoi une carte précise du tableau _boardEtMain.

  @param int : index de la carte.
  @return Carte : une carte.
*/
Carte Joueurs::getCartesBoardEtMain(int indexCarte) {
  return(_boardEtMain[indexCarte]);
}

/*
  Le setteur de la classe Joueurs.
  Initialise le niveau.

  @param string : le niveau.
*/
void Joueurs::setNiveau(string niveau) {
  _niveau = niveau;
}

/*
  Le setteur de la classe Joueurs.
  Initialise le tableau _boardEtMain pour chaque joueur.

  @param Carte : une carte.
  @param int : numéro de la carte ou bien index.
*/
void Joueurs::setCartesBoardEtMain(Carte carte, int numCarte) {
  _boardEtMain[numCarte + DEUX_CARTES_INITIALES] = carte;
}

/*
  Fonction ajoute une carte à un joueur et en même temps dans le tableau
  _boardEtMain.

  @param Carte : une carte.
*/
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

/*
  La fonction tri le tableau par ordre croissant.

  Principe : tri par bulle.

  @param int : tableau des cartes.
*/
void trierTableau(int tab[]) {
  for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1; i++) {
    for (int j = 0; j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - i - 1; j++) {
      if (tab[j] > tab[j + 1] && tab[j] != -1 && tab[j + 1] != -1) {
        int temp = tab[j];
        tab[j] = tab[j + 1];
        tab[j + 1] = temp;
      }
    }
  }
}

/*
  Fonction calcule le niveau de la main de chaque joueur et ensuite l'affecte
  aux joueurs.

  @param int : nombre de tours.
*/
void Joueurs::calculerNiveau(int nombreTours) {
  string carte;

/*  if (estCarre(nombreTours))
    _niveau = CARRE;*/
  if (estFull(nombreTours))
    _niveau = FULL;
  else if (estCouleur(nombreTours)) {
    carte = getCarteCouleur();
     _niveau = COULEUR + carte;
  } else if (estQuinte(nombreTours))
    _niveau = QUINTE;
  else if (estUnBrelan(nombreTours)) {
    carte = getCarteBrelan();
    _niveau = BRELAN + carte;
  } else if (estDoublePaire(nombreTours)) {
    _niveau = DOUBLE_PAIR; // TODO: ajouter + " et de " +
  } else if (estUnePaire(nombreTours)) {
      carte = getCartePaire();
      _niveau = PAIRE + carte;
  } else {
    carte = getCarteHaute(nombreTours);
    _niveau = CARTE_HAUTE + carte;
  }
}

/*---------------------------------------------*/
/* Fonctions hors des classes                  */
/*---------------------------------------------*/

/*
  Fonction distribue 2 cartes à chaque joueur.

  Principe : Première boucle sert pour ne pas dépasser le nombre de cartes pour
  chaque main, ce que est égal à deux. Deuxième boucle sert pour distribuer
  les cartes à chaque joueur. Autrement dit, on distribue deux cartes initiales
  pour chaque joueur.

  @param Deck : tableau de deck.
  @param Joueurs : joueur.
  @param int : nombre de tours.
*/
void distribuerCarte(Deck deck[], Joueurs *joueurs, int nombreJoueurs) {
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < nombreJoueurs; i++) {
      /* appel de la fonction tirerCarte(deck) pour tirer aux hazard une carte
         de deck. */
      joueurs[i].ajouterCarte(tirerCarte(deck));
    }
  }
}

/*
  Fonction pour devoiler les cartes sur le plateau.

  Principe : Selon le nombre de tours on affiche les cartes du plateau.

  @param Plateau : plateau.
  @param Joueurs : un joueur.
  @param int : nombre de joueurs.
  @param int : nombre de tours.
*/
void devoilerCarte(Plateau *plateau, Deck deck[], Joueurs *joueurs, int nombreJoueurs, int nombreTours) {
  Carte test;
  Carte test2;

  test.setHauteur(1);
  test.setCouleur(1);

  test2.setHauteur(5);
  test2.setCouleur(1);

  try {
    switch (nombreTours) {
      case FLOP:
        /* Distribution sur le plateau de 3 cartes */
        for (int i = 0; i < 3; i++) {
          plateau[i].setCartesPlateau(tirerCarte(deck));
          for (int j = 0; j < nombreJoueurs; j++) {
            joueurs[j].setCartesBoardEtMain(plateau[i].getCartesPlateau(), i);
          }
        }
        break;
      case TURN:
        /* Rajoute d'une carte sur le plateau. Nombre total de carte vaut 4 */
        plateau[3].setCartesPlateau(tirerCarte(deck));
        for (int j = 0; j < nombreJoueurs; j++) {
          joueurs[j].setCartesBoardEtMain(plateau[3].getCartesPlateau(), 3);
        }
        break;
      case RIVER:
        /* Rajoute d'une carte sur le plateau. Nombre total de carte vaut 5 */
        plateau[4].setCartesPlateau(tirerCarte(deck));
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

/*
  Fonction affiche le plateau de jeu.

  Principe : Selon le nombre de tours on affiche les cartes du plateau.

  @param Plateau : plateau.
  @param int : nombre de tours.
*/
void afficherBoard(Plateau *plateau, int nombreTours) {
  try {
    /* Gestion des erreur */
    if (plateau == NULL) {
      throw ERREUR_PLATEAU_NULL;
      exit(-1);
    }
    switch (nombreTours) {
      case FLOP:
        cout << "3 carte(s) : ";
        /* Affichage de 3 cartes du plateau */
        for (int i = 0; i < 3; i++) {
          plateau[i].getCartesPlateau().afficherCarte();
        }
        break;
      case TURN:
        cout << "4 carte(s) : ";
        /* Affichage de 4 cartes du plateau */
        for (int i = 0; i < 4; i++) {
          plateau[i].getCartesPlateau().afficherCarte();
        }
        break;
      case RIVER:
        cout << "5 carte(s) : ";
        /* Affichage de 5 cartes du plateau */
        for (int i = 0; i < 5; i++) {
          plateau[i].getCartesPlateau().afficherCarte();
        }
        break;
      default:
        /* Pour le PREFLOP il n'y a aucune carte du plateau */
        cout << "aucune carte" << endl;
        break;
    }
  } catch (string plateau_null) {
    std::cout << "Erreur : " << plateau_null << endl;
  }
}

/*
  Fonction affiche les cartes de board et de main.

  Principe : Selon le nombre de tours on affiche les cartes du plateau et de
  main.

  @param Joueurs : un joueur.
  @param int : nombre de tours.
*/
void Joueurs::afficherCartesBoardEtMain(Joueurs *joueurs, int nombreTours) {
  switch (nombreTours) {
    case PREFLOP:
      /* Affichage de 2 cartes de main */
      for (int j = 0; j < 2; j++) {
        this->getCartesBoardEtMain(j).afficherCarte();
        std::cout << " ";
      }
      break;
    case FLOP:
    /* Affichage de 2 cartes de main et 3 cartes du plateau */
    for (int j = 0; j < 5; j++) {
      this->getCartesBoardEtMain(j).afficherCarte();
      std::cout << " ";
      }
      break;
    case TURN:
    /* Affichage de 2 cartes de main et 4 cartes du plateau */
    for (int j = 0; j < 6; j++) {
      this->getCartesBoardEtMain(j).afficherCarte();
      std::cout << " ";
      }
      break;
    default:
    /* Affichage de 2 cartes de main et 5 cartes du plateau */
    for (int j = 0; j < 7; j++) {
      this->getCartesBoardEtMain(j).afficherCarte();
      std::cout << " ";
      }
      break;
    }
}

/*
  Fonction de gestion de tours pendant le jeu.

  Principe : D'abord, on distribue deux cartes à chaque joueur et ensuite selon
  le nombre de tours on devoile different quantité des cartes sur le plateau.
  Après on fait affichage du plateau, des mains et du niveau.

  @param Deck : tableau de deck.
  @param Plateau : plateau de jeu.
  @param int : nombre de joueurs.
  @param int : nombre de tours.
*/
void tour(Deck deck[], Plateau *plateau, Joueurs *joueurs, int nombreJoueurs, int nombreTours) {
  /* Selon le nombre de tours on devoile different quantité des cartes sur le plateau */
  switch (nombreTours) {
    case PREFLOP:
      /* D'abord on distribue les deux premières cartes aux joueurs. */
      distribuerCarte(deck, joueurs, nombreJoueurs);
      std::cout << "***************************\n";
      std::cout << "*         PREFLOP         *\n";
      std::cout << "***************************\n";
      break;
    case FLOP:
    /* Ensuite on devoile les deux trois cartes sur le plateau. */
      devoilerCarte(plateau, deck, joueurs, nombreJoueurs, nombreTours);
      std::cout << "***************************\n";
      std::cout << "*          FLOP           *\n";
      std::cout << "***************************\n";
      break;
     case TURN:
     /* On rajoute quatrième carte sur le plateau */
      devoilerCarte(plateau, deck, joueurs, nombreJoueurs, nombreTours);
      std::cout << "***************************\n";
      std::cout << "*          TURN           *\n";
      std::cout << "***************************\n";
      break;
     case RIVER:
      /* On rajoute cinquième carte sur le plateau */
      devoilerCarte(plateau, deck, joueurs, nombreJoueurs, nombreTours);
      std::cout << "***************************\n";
      std::cout << "*          RIVER          *\n";
      std::cout << "***************************\n";
      break;
    default:
      /* On affiche le fin de partie */
      std::cout << "***************************\n";
      std::cout << "*      FIN DE PARTIE      *\n";
      std::cout << "***************************\n";
      break;
   }

  /* On affiche le plateau */
  std::cout << "Board :\n";
  afficherBoard(plateau, nombreTours);
  cout << endl;
  /* On affiche les cartes de chaque joueur. */
  for (int i = 0; i < nombreJoueurs; i++) {
    std::cout << "Joueur " << i << '\n';
    std::cout << "2 carte(s) : " << endl;;
    joueurs[i].getCartes(0).afficherCarte();
    std::cout << " ";
    joueurs[i].getCartes(1).afficherCarte();
    std::cout << endl;
    /* On affiche les cartes du plateau et de main */
    std::cout << "avec le board : ";
    joueurs[i].afficherCartesBoardEtMain(joueurs, nombreTours);
    std::cout << endl;
    /* On calcul le niveau */
    joueurs[i].calculerNiveau(nombreTours);
    /* On affiche le niveau */
    std::cout << joueurs[i].getNiveau() << endl;
  }
}

/*
  Surcharge de l'operarteur égal pour pouvoir comparer deux cartes.

  @param Carte : première carte.
  @param Carte : deuxième carte.
*/
bool operator==(const Carte& carte1, const Carte& carte2) {
  return (carte1.getHauteur() == carte2.getHauteur());
}

/*
  Surcharge de l'operarteur > pour pouvoir comparer deux cartes.

  @param Carte : première carte.
  @param Carte : deuxième carte.
*/
bool operator>(const Carte& carte1, const Carte& carte2) {
  return (carte1.getHauteur() > carte2.getHauteur());
}

/*
  Surcharge de flux de sortie pour pouvoir afficher une carte.

  @param ostream : flux de sortie.
  @param Carte : une carte.
*/
ostream& operator<<(ostream& os, const Carte& carte) {
  os << carte.getHauteur() << endl;
  return os;
}

/*
  Fonction convertit un entier à une chaîne de caractères.

  @param int : une carte.
  @return string : une chaîne de caractères.
*/
string to_string(int carte) {
  ostringstream ss;
  ss << carte;

  return ss.str();
}
