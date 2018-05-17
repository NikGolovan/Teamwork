#include "poker_holdem.hpp"

using namespace std;

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

  if (compteur >= 5)
    return true;
  else
    return false;
}

// TODO: finir fonction et mettre les commentaires
bool Joueurs::estCarre(int nombreTours) {

  switch (nombreTours) {
    case FLOP:

      break;
    case TURN:

      break;
    case RIVER:

      break;
  }

  int compteur = 0;

  if (getCartes(0) == getCartes(1)) {
    compteur -= 1;
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
      if (getCartes(0) == getCartesBoardEtMain(i+1))
      compteur++;
      // when fourth card is at the end but doesnt work if
      // we get four card in a row
      if (i == TAILLE_PLATEAU-1) {
        for (int i = TAILLE_PLATEAU; i > 0; i--)
        //if (plateau[TAILLE_PLATEAU].getCartesPlateau() == getCartesBoardEtMain(i))
        compteur++;
      }
    }
  } else {
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
      if (getCartes(0) == getCartesBoardEtMain(i+1))
      compteur++;
      // when fourth card is at the end but doesnt work if
      // we get four card in a row
      if (i == TAILLE_PLATEAU-1) {
        for (int i = TAILLE_PLATEAU; i > 0; i--)
        //if (plateau[TAILLE_PLATEAU].getCartesPlateau() == getCartesBoardEtMain(i))
        compteur++;
      }
    }
  }

  if (compteur == 3 || compteur == 4)
  return true;
  else
  return false;
}

// TODO: commentaires
bool Joueurs::estFull(int nombreTours) {
  bool estFullBooleen = false;

  switch (nombreTours) {
    case FLOP:
      if (estUnBrelan(nombreTours) && estDoublePaire(nombreTours))
        estFullBooleen = true;
      break;
    case TURN:
      if (estUnBrelan(nombreTours) && estDoublePaire(nombreTours))
        estFullBooleen = true;
    case RIVER:
      if (estUnBrelan(nombreTours) && estDoublePaire(nombreTours))
        estFullBooleen = true;
      break;
    default:
      break;
  }
  return(estFullBooleen);
}

// TODO: commentaires
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

// TODO: commentaires
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

  if (compteur >= 5)
    return true;
  else
    return false;
}

// TODO: commentaires
bool Joueurs::estUnBrelan(int nombreTours) {
  int compteur = 0;

  switch (nombreTours) {
    case FLOP:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 2; i++) {
        for (int j = i + 1; j < DEUX_CARTES_INITIALES + 3; j++) {
          if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
              compteur++;
        }
      }
      break;
    case TURN:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 3; i++) {
        for (int j = i + 1; j < DEUX_CARTES_INITIALES + 4; j++) {
          if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
            compteur++;
        }
      }
      break;
    case RIVER:
      for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1; i++) {
        for (int j = i + 1; j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; j++) {
          if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
            compteur++;
        }
      }
      break;
  }
  return(compteur >= 3);
}

// TODO: commentaires
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

  if (compteur >= 2)
    return true;
  else
    return false;
}

// TODO: commentaires
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

string Joueurs::getCarteCarre() {

}

string Joueurs::getCarteFull() {

}

/*
  Fonction renvoi une carte sous type de chaîne de caractères pour pouvoir
  l'afficher dans la console et rejoindre dans le niveau;

  Principe : On compte les couleurs des cartes sur le plateau. Si l'une des
  couleurs est égale ou supérieur a 5, on renvoi une chaîne de caractères
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

string Joueurs::getCarteQuinte() {

}

/*
  Fonction renvoi une carte sous type de chaîne de caractères pour pouvoir
  l'afficher dans la console et rejoindre dans le niveau;

  Principe : On compare directement les cartes dans le board entre elles et
  dès qu'on trouve une paire, on recopie la position de cette carte. Ensuite,
  on convertir hauteur de cette carte (en utilisant la positon) en une chaîne
  de caractères.

  Remarque : Nous n'avons pas fait des vérifications car cettefonction est
  appelée si et seulement s'il y a un brelan.

  @return string : une carte.
*/
string Joueurs::getCarteBrelan() {
  string carteBrelan;
  int brelan = 0;
  int positionCarte = 0;

  /* recherche d'une paire */
  for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1; i++) {
    for (int j = i + 1; j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; j++) {
      if (getCartesBoardEtMain(i) == getCartesBoardEtMain(j))
        positionCarte = i; /* recopie de la position */
    }
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

string Joueurs::getCarteDoublePaire() {
  string test;
  string test2;
  string doublePaire;
  int i = 0;
  bool trouvee = false;

  test = getCartePaire();

  while (i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU - 1 && !trouvee) {
    int j = i + 1;
    while (j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU && !trouvee) {
      if (test != getCartesBoardEtMain(i).getHauteur()
          && getCartesBoardEtMain(i)._hauteur == getCartesBoardEtMain(j)._hauteur) {
        test2 = getCartesBoardEtMain(i).getHauteur();
        trouvee = true;
      }
      j++;
    }
    i++;
  }

  /* on vérifie le résultat obtenu s'il est supérieur à 10 */
  if (test2 == "14")
    test2 = AS;
  else if (test2 == "13")
    test2 = ROI;
  else if (test2 == "12")
    test2 = DAME;
  else if (test2 == "11")
    test2 = VALET;

  doublePaire = test + " et de " + test2;

  return(doublePaire);
}
/*
  Fonction renvoi une carte sous type de chaîne de caractères pour pouvoir
  l'afficher dans la console et rejoindre dans le niveau;

  Principe : On compare les cartes du plateau et dès qu'on trouve une paire
  on recopie sa position dans le plateau. Ensuite, on converti hauteur de la
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
  Fonction renvoi une carte sous type de chaîne de caractères pour pouvoir
  l'afficher dans la console et rejoindre dans le niveau;

  Principe : À chaque tour toutes les hauteurs de cartes sont mises dans
  un tableau. Puis, ce tableau est trié par l'ordre croissant. Ensuite,
  selon le numéro de tour on prend le dernier valeur du tableau (le plus haut)
  et on le convertit en une chaîne de caractères. La fonction returne cette
  chaîne.

  @param int : nombre de tours.
  @return string : une carte.
*/
string Joueurs::getCarteHaute(int nombreTours) {
  int tab[DEUX_CARTES_INITIALES + TAILLE_PLATEAU] = {0, 0, 0, 0, 0, 0, 0};
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
