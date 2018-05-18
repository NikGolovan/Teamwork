#include "poker_holdem.hpp"

using namespace std;

/*
  Remarque :
    Le fait d'utiliser des switch nous amène à écrire 3 fois un code similaire
    ce qui augmente considérablement la taille de chaque fonction.
*/

/*
  Fonction qui renvoie un booléen qui vaut vrai si il y a une quinte flush, et faux
  sinon;

  Principe : On crée 1 compteur qui servira à la fin pour vérifier si il y a une
  quinte. On créé 4 tableaux pour les hauteurs de cartes et 4 compteurs (1 pour
  chaque couleur). On compare les couleurs des cartes et on insère la hauteur
  dans le tableau correspondant. On incrémente le compteur correspondant. Si un
  des compteurs est supérieur ou égal à 5, on vérifie dans le tableau
  correspondant si il y a une quinte (avec le compteur du départ) (On utilise le
  même principe que pour la quinte). Enfin, on vérifie si le compteur est
  supérieur à 5 et, le cas échéant, on retourne vrai. Sinon on retourne faux. On
   utilise le switch pour chaque tour afin de ne pas comparer les cartes avec
   des cartes inexistantes.

  @return bool.
*/
bool Joueurs::estQuinteFlush(int nombreTours) {
  int compteur = 1;
  int ca[DEUX_CARTES_INITIALES + TAILLE_PLATEAU] = {-1, -1, -1, -1, -1, -1, -1};
  int carreau = 0;
  int co[DEUX_CARTES_INITIALES + TAILLE_PLATEAU] = {-1, -1, -1, -1, -1, -1, -1};
  int coeur = 0;
  int p[DEUX_CARTES_INITIALES + TAILLE_PLATEAU] = {-1, -1, -1, -1, -1, -1, -1};
  int pique = 0;
  int t[DEUX_CARTES_INITIALES + TAILLE_PLATEAU] = {-1, -1, -1, -1, -1, -1, -1};
  int trefle = 0;
  int j = 0;
  bool suivi = true;

  switch (nombreTours) {
    case FLOP:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 3; i++) {
        if (getCartesBoardEtMain(i).getCouleur() == 0) {
          ca[carreau] = getCartesBoardEtMain(i)._hauteur;
          carreau++;
        } else if (getCartesBoardEtMain(i).getCouleur() == 1) {
          co[coeur] = getCartesBoardEtMain(i)._hauteur;
          coeur++;
        } else if (getCartesBoardEtMain(i).getCouleur() == 2) {
          p[pique] = getCartesBoardEtMain(i)._hauteur;
          pique++;
        } else {
          t[trefle] = getCartesBoardEtMain(i)._hauteur;
          trefle++;
        }
      }

      trierTableau(ca);
      trierTableau(co);
      trierTableau(p);
      trierTableau(t);


      if (carreau >= 5) {
        while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
          if (ca[j] == ca[j + 1] - 1) {
            compteur++;
          } else if (ca[j] != ca[j + 1]) {
            suivi = false;
          }
          j++;
        }
      } else if (coeur >= 5) {
        while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
          if (co[j] == co[j + 1] - 1) {
            compteur++;
          } else if (co[j] != co[j + 1]) {
            suivi = false;
          }
          j++;
        }
      } else if (pique >= 5) {
        while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
          if (p[j] == p[j + 1] - 1) {
            compteur++;
          } else if (p[j] != p[j + 1]) {
            suivi = false;
          }
          j++;
        }
      } else if (trefle >= 5){
        while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
          if (t[j] == t[j + 1] - 1) {
            compteur++;
          } else if (t[j] != t[j + 1]) {
            suivi = false;
          }
          j++;
        }
      }

      break;
    case TURN:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 4; i++) {
        if (getCartesBoardEtMain(i).getCouleur() == 0) {
          ca[carreau] = getCartesBoardEtMain(i)._hauteur;
          carreau++;
        } else if (getCartesBoardEtMain(i).getCouleur() == 1) {
          co[coeur] = getCartesBoardEtMain(i)._hauteur;
          coeur++;
        } else if (getCartesBoardEtMain(i).getCouleur() == 2) {
          p[pique] = getCartesBoardEtMain(i)._hauteur;
          pique++;
        } else {
          t[trefle] = getCartesBoardEtMain(i)._hauteur;
          trefle++;
        }
      }

      trierTableau(ca);
      trierTableau(co);
      trierTableau(p);
      trierTableau(t);


      if (carreau >= 5) {
        while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
          if (ca[j] == ca[j + 1] - 1) {
            compteur++;
          } else if (ca[j] != ca[j + 1]) {
            suivi = false;
          }
          j++;
        }
      } else if (coeur >= 5) {
        while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
          if (co[j] == co[j + 1] - 1) {
            compteur++;
          } else if (co[j] != co[j + 1]) {
            suivi = false;
          }
          j++;
        }
      } else if (pique >= 5) {
        while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
          if (p[j] == p[j + 1] - 1) {
            compteur++;
          } else if (p[j] != p[j + 1]) {
            suivi = false;
          }
          j++;
        }
      } else if (trefle >= 5){
        while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
          if (t[j] == t[j + 1] - 1) {
            compteur++;
          } else if (t[j] != t[j + 1]) {
            suivi = false;
          }
          j++;
        }
      }

      break;
    case RIVER:
      for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; i++) {
        if (getCartesBoardEtMain(i).getCouleur() == 0) {
          ca[carreau] = getCartesBoardEtMain(i)._hauteur;
          carreau++;
        } else if (getCartesBoardEtMain(i).getCouleur() == 1) {
          co[coeur] = getCartesBoardEtMain(i)._hauteur;
          coeur++;
        } else if (getCartesBoardEtMain(i).getCouleur() == 2) {
          p[pique] = getCartesBoardEtMain(i)._hauteur;
          pique++;
        } else {
          t[trefle] = getCartesBoardEtMain(i)._hauteur;
          trefle++;
        }
      }

      trierTableau(ca);
      trierTableau(co);
      trierTableau(p);
      trierTableau(t);


        if (carreau >= 5) {
          while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
            if (ca[j] == ca[j + 1] - 1) {
              compteur++;
            } else if (ca[j] != ca[j + 1]) {
              suivi = false;
            }
            j++;
          }
        } else if (coeur >= 5) {
          while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
            if (co[j] == co[j + 1] - 1) {
              compteur++;
            } else if (co[j] != co[j + 1]) {
              suivi = false;
            }
            j++;
          }
        } else if (pique >= 5) {
          while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
            if (p[j] == p[j + 1] - 1) {
              compteur++;
            } else if (p[j] != p[j + 1]) {
              suivi = false;
            }
            j++;
          }
        } else if (trefle >= 5){
          while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
            if (t[j] == t[j + 1] - 1) {
              compteur++;
            } else if (t[j] != t[j + 1]) {
              suivi = false;
            }
            j++;
          }
        }

      break;
  }

  return(compteur >= 5);
}

/*
  Fonction qui renvoie un booléen qui vaut vrai si il y a un carre, et faux sinon;

  Principe : On utilise le même principe que pour le brelan mais en comparant
  avec 3 au lieu de 2.

  @return bool.
*/
bool Joueurs::estCarre(int nombreTours) {
  int compteur = 0;
  bool estBrelan = false;

  switch (nombreTours) {
    case FLOP:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 2; i++) {
        compteur = 0;
        for (int j = i + 1; j < DEUX_CARTES_INITIALES + 3; j++) {
          if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
            compteur++;
        }
        if (compteur >= 3)
          estBrelan = true;
      }
      break;
    case TURN:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 3; i++) {
        compteur = 0;
        for (int j = i + 1; j < DEUX_CARTES_INITIALES + 4; j++) {
          if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
            compteur++;
        }
        if (compteur >= 3)
          estBrelan = true;
      }
      break;
    case RIVER:
      for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1; i++) {
        compteur = 0;
        for (int j = i + 1; j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; j++) {
          if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
            compteur++;
        }
        if (compteur >= 3)
          estBrelan = true;
      }
      break;
  }
  return(estBrelan);
}

/*
  Fonction qui renvoie un booléen qui vaut vrai si il y a un full, et faux sinon;

  Principe : On initialise un booléen à faux. On regarde si il y a un brelan et
  une double paire et, le cas échéant, on met le booléen à vrai. Enfin, on
  retourne ce booléen.

  @return bool.
*/
bool Joueurs::estFull(int nombreTours) {
  bool estFullBooleen = false;

  if (estUnBrelan(nombreTours) && estDoublePaire(nombreTours))
    estFullBooleen = true;

  return(estFullBooleen);
}

/*
  Fonction qui renvoie un booléen qui vaut vrai si il y a une couleur, et faux sinon;

  Principe : On initialise 4 compteurs (1 pour chaque couleur) à 0. On compare
  les couleurs des cartes du plateau et on incrémente le compteur de la couleur
  correspondante. Si un des compteurs est supérieur à 5, on retourne vrai. Sinon
  on retourne faux. On utilise le switch pour chaque tour afin de ne pas comparer
  les cartes avec des cartes inexistantes.

  @return bool.
*/
bool Joueurs::estCouleur(int nombreTours) {

  int carreau = 0;
  int coeur = 0;
  int pique = 0;
  int trefle = 0;

  switch (nombreTours) {
    case FLOP:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 3; i++) {
        if (getCartesBoardEtMain(i).getCouleur() == 0) {
          carreau++;
        } else if (getCartesBoardEtMain(i).getCouleur() == 1) {
          coeur++;
        } else if (getCartesBoardEtMain(i).getCouleur() == 2) {
          pique++;
        } else {
          trefle++;
        }
      }
      break;
    case TURN:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 4; i++) {
        if (getCartesBoardEtMain(i).getCouleur() == 0) {
          carreau++;
        } else if (getCartesBoardEtMain(i).getCouleur() == 1) {
          coeur++;
        } else if (getCartesBoardEtMain(i).getCouleur() == 2) {
          pique++;
        } else {
          trefle++;
        }
      }
      break;
    case RIVER:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 5; i++) {
        if (getCartesBoardEtMain(i).getCouleur() == 0) {
          carreau++;
        } else if (getCartesBoardEtMain(i).getCouleur() == 1) {
          coeur++;
        } else if (getCartesBoardEtMain(i).getCouleur() == 2) {
          pique++;
        } else {
          trefle++;
        }
      }
      break;
  }
  if (carreau >= 5 || coeur >= 5 || pique >= 5 || trefle >= 5)
    return true;
  else
    return false;
}

/*
  Fonction qui renvoie un booléen qui vaut vrai si il y a une quinte, et faux sinon;

  Principe : On trie les hauteurs des cartes par ordre croissant. On initialise
  un compteur à 1. On incrémente le compteur si deux cartes se suivent. Si les 2
  cartes ne se suivent pas et ne sont pas égales, on met un booléen à faux pour
  sortir de la boucke de parcours. On vérifie que le compteur est supérieur à 5
  et, le cas échéant, on retourne vrai. Sinon on retourne faux. On utilise le
  switch pour chaque tour afin de ne pas comparer les cartes avec des cartes
  inexistantes.

  @return bool.
*/
bool Joueurs::estQuinte(int nombreTours) {
  int compteur = 1;
  int tab[DEUX_CARTES_INITIALES + TAILLE_PLATEAU] = {-1, -1, -1, -1, -1, -1, -1};
  int j = 0;
  bool suivi = true;

  switch (nombreTours) {
    case FLOP:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 3; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableau(tab);

      while (j < DEUX_CARTES_INITIALES + 2 && suivi) {
        if (tab[j] == tab[j + 1] - 1) {
          compteur++;
        } else if (tab[j] != tab[j + 1]) {
          suivi = false;
        }
        j++;
      }
      break;
    case TURN:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 4; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableau(tab);

      while (j < DEUX_CARTES_INITIALES + 3 && suivi) {
        if (tab[j] == tab[j + 1] - 1) {
          compteur++;
        } else if (tab[j] != tab[j + 1]) {
          suivi = false;
        }
        j++;
      }
      break;
    case RIVER:

      for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableau(tab);

      while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
        if (tab[j] == tab[j + 1] - 1) {
          compteur++;
        } else if (tab[j] != tab[j + 1]) {
          suivi = false;
        }
        j++;
      }
      break;
  }

  return(compteur >= 5);
}

/*
  Fonction qui renvoie un booléen qui vaut vrai si il y a un brelan, et faux sinon;

  Principe : On initialise un compteur à 0. On compare les cartes du plateau
  et si on trouve 2 cartes égales, on incrémente le compteur. Enfin, on vérifie
  si le compteur est supérieur ou égal à 2 et, le cas échéant, on retourne vrai.
  Sinon on retourne faux. On utilise le switch pour chaque tour afin de ne pas
  comparer les cartes avec des cartes inexistantes.

  @return bool.
*/
bool Joueurs::estUnBrelan(int nombreTours) {
  int compteur = 0;
  bool estBrelan = false;

  switch (nombreTours) {
    case FLOP:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 2; i++) {
        compteur = 0;
        for (int j = i + 1; j < DEUX_CARTES_INITIALES + 3; j++) {
          if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
            compteur++;
        }
        if (compteur >= 2)
          estBrelan = true;
      }
      break;
    case TURN:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 3; i++) {
        compteur = 0;
        for (int j = i + 1; j < DEUX_CARTES_INITIALES + 4; j++) {
          if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
            compteur++;
        }
        if (compteur >= 2)
          estBrelan = true;
      }
      break;
    case RIVER:
      for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1; i++) {
        compteur = 0;
        for (int j = i + 1; j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; j++) {
          if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
            compteur++;
        }
        if (compteur >= 2)
          estBrelan = true;
      }
      break;
  }
  return(estBrelan);
}

/*
  Fonction qui renvoie un booléen qui vaut vrai si il y a 2 paires, et faux
  sinon;

  Principe : On trie les hauteurs des cartes par ordre croissant. On initialise
  un compteur à 0. On compare les hauteurs des cartes du plateau et si on trouve
  une paire, on incrémente le compteur. Enfin, on vérifie si le compteur est
  supérieur ou égal à 2 et, le cas échéant, on retourne vrai. Sinon on retourne
  faux. On utilise le switch pour chaque tour afin de ne pas comparer les cartes
  avec des cartes inexistantes.

  @return bool.
*/
bool Joueurs::estDoublePaire(int nombreTours) {
  int compteur = 0;
  int i = 0;
  int tab[DEUX_CARTES_INITIALES + TAILLE_PLATEAU] = {-1, -1, -1, -1, -1, -1, -1};

  switch (nombreTours) {
    case FLOP:
      for (i = 0; i < DEUX_CARTES_INITIALES + 3; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableau(tab);

      for (i = 0; i < DEUX_CARTES_INITIALES + 3; i++) {
      }

      i = 0;
      while (i < DEUX_CARTES_INITIALES + 2) {
        int j = i + 1;
        while (j < DEUX_CARTES_INITIALES + 3 && tab[i] == tab[j]) {
          j++;
        }
        if (j > i + 1) {
          compteur++;
          i = j;
        } else
          i++;
      }
      break;
    case TURN:
      for (i = 0; i < DEUX_CARTES_INITIALES + 4; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableau(tab);

      i = 0;
      while (i < DEUX_CARTES_INITIALES + 3) {
        int j = i + 1;
        while (j < DEUX_CARTES_INITIALES + 4 && tab[i] == tab[j]) {
          j++;
        }
        if (j > i + 1) {
          compteur++;
          i = j;
        } else
          i++;
      }
      break;
    case RIVER:
      for (i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableau(tab);

      i = 0;
      while (i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1) {
        int j = i + 1;
        while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU && tab[i] == tab[j]) {
          j++;
        }
        if (j > i + 1) {
          compteur++;
          i = j;
        } else
          i++;
      }
      break;
  }

  return(compteur >= 2);
}

/*
  Fonction qui renvoie un booléen qui vaut vrai si il y a une paire, et faux
  sinon;

  Principe : On initialise un booléen à faux. On compare les cartes du plateau
  et si on trouve une paire, on met le booléen à vrai. Enfin, on retourne ce
  booléen. On utilise le switch pour chaque tour afin de ne pas comparer les
  cartes avec des cartes inexistantes.

  @return bool.
*/
bool Joueurs::estUnePaire(int nombreTours) {
  bool estPaire = false;

  switch (nombreTours) {
    case PREFLOP:
      for (int i = 0; i < DEUX_CARTES_INITIALES - 1; i++) {
        for (int j = i + 1; j < DEUX_CARTES_INITIALES; j++) {
          if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
              estPaire = true;
          }
      }
      break;
    case FLOP:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 2; i++) {
        for (int j = i + 1; j < DEUX_CARTES_INITIALES + 3; j++) {
          if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
              estPaire = true;
          }
      }
      break;
    case TURN:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 3; i++) {
        for (int j = i + 1; j < DEUX_CARTES_INITIALES + 4; j++) {
          if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
              estPaire = true;
          }
      }
      break;
    default:
      for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1; i++) {
        for (int j = i + 1; j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; j++) {
          if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
            estPaire = true;
          }
      }
      break;
  }

  return(estPaire);
}


/*
  Fonction qui renvoie une carte sous type de chaîne de caractères pour pouvoir
  l'afficher dans la console et rejoindre dans le niveau;

  Principe : On utilise le même principe que pour le brelan mais en cherchant 4
  cartes au lieu de 3.

  @return string : une carte.
*/
string Joueurs::getCarteCarre() {
  string carteCarre;
  int carre = 0;
  int positionCarte = -1;

  bool trouvee = false;
  int i = 0;

  while (i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && !trouvee) {
    int j = i + 1;
    int cpt = 0;
    while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU && !trouvee) {
      if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j)) {
        positionCarte = i;
        cpt++;
        if (cpt == 3)
          trouvee = true;
      }
      j++;
    }
    i++;
  }


  /* convertion en chaîne de caractères */
  carre = getCartesBoardEtMain(positionCarte)._hauteur;
  carteCarre = to_string(carre);


  /* on vérifie le résultat obtenu s'il est supérieur à 10 */
  if (carteCarre == "14")
    return(AS);
  else if (carteCarre == "13")
    return(ROI);
  else if (carteCarre == "12")
    return(DAME);
  else if (carteCarre == "11")
    return(VALET);
  else
    return(carteCarre);
}

/*
Fonction qui renvoie une carte sous type de chaîne de caractères pour pouvoir
l'afficher dans la console et rejoindre dans le niveau;

Principe : On récupère la hauteur du brelan ainsi que les 2 paires (dont le
brelan). On ne garde que la paire qui n'est pas le brelan et on retourne la
hauteur du brelan et de la deuxième paire

@return string : une carte + " par les " + une autre carte.
*/
string Joueurs::getCarteFull() {
  string doublePaire;
  string brelan;
  string carteFull;

  doublePaire = getCarteDoublePaire();
  brelan = getCarteBrelan();

  /* on cherche la paire qui est dans le brelan */
  int pos = doublePaire.find(brelan);
  /* on supprime la paire qui est dans le brelan */
  doublePaire.erase(pos, brelan.length());

  /* on cherche les mots qui séparaient les 2 paires */
  pos = doublePaire.find(" et de ");
  /* on supprime les mots */
  doublePaire.erase(pos, 7);


  carteFull = brelan + " par les " + doublePaire;

  return(carteFull);
}

/*
  Fonction qui renvoie une carte sous type de chaîne de caractères pour pouvoir
  l'afficher dans la console et rejoindre dans le niveau;

  Principe : On compte les couleurs des cartes sur le plateau. Si l'une des
  couleurs est supérieure ou égale à 5, on renvoie une chaîne de caractères
  avec la couleur correspondante.

  @return string : une carte.
*/
string Joueurs::getCarteCouleur() {
  int carreau = 0;
  int coeur = 0;
  int pique = 0;
  int trefle = 0;

  /* on compte chaque couleur sur le plateau */
  for (int i = 0; i < DEUX_CARTES_INITIALES + 5; i++) {
    if (getCartesBoardEtMain(i).getCouleur() == 0) {
      carreau++;
    } else if (getCartesBoardEtMain(i).getCouleur() == 1) {
      coeur++;
    } else if (getCartesBoardEtMain(i).getCouleur() == 2) {
      pique++;
    } else {
      trefle++;
    }
  }
  /* on vérifie le résultat */
  if (carreau >= 5) {
    return(CARREAU);
  } else if (coeur >= 5) {
    return(COEUR);
  } else if (pique >= 5) {
    return(PIQUE);
  } else {
    return(TREFLE);
  }
}

/*
Fonction qui renvoie une carte sous type de chaîne de caractères pour pouvoir
l'afficher dans la console et rejoindre dans le niveau;

Principe : On trie les hauteurs des cartes par ordre croissant et on les compares
2 à 2 jusqu'à arriver à la fin de la quinte. On renvoie la hauteur correspondante

@return string : une carte.
*/
string Joueurs::getCarteQuinte() {
  int tab[DEUX_CARTES_INITIALES + TAILLE_PLATEAU] = {-1, -1, -1, -1, -1, -1, -1};
  string carteQuinte;
  int quinteHauteur = 0;
  bool suivi = true;
  int compteur = 0;
  int j = 0;

  for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; i++) {
    tab[i] = getCartesBoardEtMain(i)._hauteur;
  }

  trierTableau(tab);

  while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && suivi) {
    if (tab[j] == tab[j + 1] - 1  || tab[j] == tab[j + 1])
      compteur++;
    else
      suivi = false;
    j++;
  }

  quinteHauteur = tab[compteur];

  /* convertion en chaîne de caractères */
  carteQuinte = to_string(quinteHauteur);

  /* on vérifie le résultat obtenu s'il est supérieur à 10 */
  if (carteQuinte == "14")
    return(AS);
  else if (carteQuinte == "13")
    return(ROI);
  else if (carteQuinte == "12")
    return(DAME);
  else if (carteQuinte == "11")
    return(VALET);
  else
    return(carteQuinte);
}

/*
  Fonction qui renvoie une carte sous type de chaîne de caractères pour pouvoir
  l'afficher dans la console et rejoindre dans le niveau;

  Principe : On compare directement les cartes dans le board entre elles et dès
  qu'on trouve 3 cartes identiques, on recopie la position de cette carte.
  Ensuite, on convertir la hauteur de cette carte (en utilisant la position) en
  une chaîne de caractères.

  @return string : une carte.
*/
string Joueurs::getCarteBrelan() {
  string carteBrelan;
  int brelan = 0;
  int positionCarte = -1;

  bool trouvee = false;
  int i = 0;

  while (i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && !trouvee) {
    int j = i + 1;
    int cpt = 0;
    while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU && !trouvee) {
      if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j)) {
        positionCarte = i;
        cpt++;
        if (cpt == 2)
          trouvee = true;
      }
      j++;
    }
    i++;
  }


  /* convertion en chaîne de caractères */
  brelan = getCartesBoardEtMain(positionCarte)._hauteur;
  carteBrelan = to_string(brelan);


  /* on vérifie le résultat obtenu s'il est supérieur à 10 */
  if (carteBrelan == "14")
    return(AS);
  else if (carteBrelan == "13")
    return(ROI);
  else if (carteBrelan == "12")
    return(DAME);
  else if (carteBrelan == "11")
    return(VALET);
  else
    return(carteBrelan);
}

/*
  Fonction qui renvoie deux cartes sous type de chaîne de caractères pour pouvoir
  l'afficher dans la console et rejoindre dans le niveau;

  Principe : On appelle getCartePaire() pour avoir la première paire puis on
  applique le même principe que cette fonction et on ignore les cartes de la
  première paire pour connaitre la deuxième paire

  @return string : une carte + "et de " + une autre carte.
*/
string Joueurs::getCarteDoublePaire() {
  string premierePaire;
  string deuxiemePaire;
  string doublePaire;
  int i = 0;
  bool trouvee = false;

  premierePaire = getCartePaire();

  while (i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && !trouvee) {
    int j = i + 1;
    while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU && !trouvee) {
      if (premierePaire != getCartesBoardEtMain(i).getHauteur()
          && getCartesBoardEtMain(i)._hauteur == getCartesBoardEtMain(j)._hauteur) {
        deuxiemePaire = getCartesBoardEtMain(i).getHauteur();
        trouvee = true;
      }
      j++;
    }
    i++;
  }

  /* on vérifie le résultat obtenu s'il est supérieur à 10 */
  if (deuxiemePaire == "14")
    deuxiemePaire = AS;
  else if (deuxiemePaire == "13")
    deuxiemePaire = ROI;
  else if (deuxiemePaire == "12")
    deuxiemePaire = DAME;
  else if (deuxiemePaire == "11")
    deuxiemePaire = VALET;

  doublePaire = premierePaire + " et de " + deuxiemePaire;

  return(doublePaire);
}

/*
  Fonction qui renvoie une carte sous type de chaîne de caractères pour pouvoir
  l'afficher dans la console et rejoindre dans le niveau;

  Principe : On compare les cartes du plateau et dès qu'on trouve une paire, on
  recopie sa position dans le plateau. Ensuite, on convertit la hauteur de la
  carte de cette position en une chaîne de caractères.

  @return string : une carte.
*/
string Joueurs::getCartePaire() {
  string cartePaire;
  int tmp = -1;
  bool trouvee = false;
  int i = 0;

  while (i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && !trouvee) {
    int j = i + 1;
    while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU && !trouvee) {
      if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j)) {
        tmp = i;
        trouvee = true;
      }
      j++;
    }
    i++;
  }

  /* convertion en chaîne de caractères */
  tmp = getCartesBoardEtMain(tmp)._hauteur;
  cartePaire = to_string(tmp);

  /* on vérifie le résultat obtenu s'il est supérieur à 10 */
  if (cartePaire == "14")
    return(AS);
  else if (cartePaire == "13")
    return(ROI);
  else if (cartePaire == "12")
    return(DAME);
  else if (cartePaire == "11")
    return(VALET);
  else
    return cartePaire;
}

/*
  Fonction qui renvoie une carte sous type de chaîne de caractères pour pouvoir
  l'afficher dans la console et rejoindre dans le niveau;

  Principe : On trie les hauteurs des cartes par ordre croissant. Ensuite on
  prend la valeur maximale du tableau et on la convertit en une chaîne de
  caractères. La fonction retourne cette chaîne. On utilise le switch pour
  chaque tour afin de ne pas comparer les cartes avec des cartes inexistantes.

  @param int : nombre de tours.
  @return string : une carte.
*/
string Joueurs::getCarteHaute(int nombreTours) {
  int tab[DEUX_CARTES_INITIALES + TAILLE_PLATEAU] = {-1, -1, -1, -1, -1, -1, -1};
  string carteHaute; /* la chaîne qui va être retourné */
  int valeurMax = 0; /* va contenir le plus grand entier du tableau */

  switch (nombreTours) {
    case PREFLOP:
      /* recopie des hauteurs des cartes dans un tableau */
      for (int i = 0; i < DEUX_CARTES_INITIALES; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }
      /* tri du tableau */
      trierTableau(tab);

      /* convertion en chaîne de caractères du valeur maximum */
      valeurMax = tab[6];
      carteHaute = to_string(valeurMax);
      break;
    case FLOP:
      for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableau(tab);

      valeurMax = tab[4];
      carteHaute = to_string(valeurMax);
      break;
    case TURN:
      for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableau(tab);

      valeurMax = tab[5];
      carteHaute = to_string(valeurMax);
      break;
    default:
      for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableau(tab);

      valeurMax = tab[6];
      carteHaute = to_string(valeurMax);
      break;
  }
  /* on vérifie le résultat obtenu s'il est supérieur à 10 */
  if (carteHaute == "14")
    return(AS);
  else if (carteHaute == "13")
    return(ROI);
  else if (carteHaute == "12")
    return(DAME);
  else if (carteHaute == "11")
    return(VALET);
  else
    return carteHaute;
}
