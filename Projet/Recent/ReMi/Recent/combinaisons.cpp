#include "poker_holdem.hpp"

using namespace std;

// TODO: ameliorer carre
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

// TODO: ameliorer full
bool Joueurs::estFull(int nombreTours) {
  bool estFullBooleen = false;

  switch (nombreTours) {
    case FLOP:
      if (estUnBrelan(nombreTours) && estDoublePaire(nombreTours))
        estFullBooleen = true;
      cout <<  estUnBrelan(nombreTours) << " " << estDoublePaire(nombreTours) << endl;
      break;
    case TURN:
    if (estUnBrelan(nombreTours) && estDoublePaire(nombreTours))
      estFullBooleen = true;
    cout <<  estUnBrelan(nombreTours) << " " << estDoublePaire(nombreTours) << endl;
    case RIVER:
      cout <<  estUnBrelan(nombreTours) << " " <<  estDoublePaire(nombreTours) << endl;
      break;
    default:
      break;
  }
  return(estFullBooleen);
}

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

bool Joueurs::estQuinte(int nombreTours) {
  int compteur = 1;
  int tab[DEUX_CARTES_INITIALES + TAILLE_PLATEAU] = {0, 0, 0, 0, 0, 0, 0};
  int j = 0;
  bool suivi = true;

  switch (nombreTours) {
    case FLOP:
      for (int i = 0; i < DEUX_CARTES_INITIALES + 3; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableauPourQuinte(tab);

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

      trierTableauPourQuinte(tab);

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

      trierTableauPourQuinte(tab);

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
  return(compteur == 3);
}

bool Joueurs::estDoublePaire(int nombreTours) {
  int compteur = 0;
  int i = 0;
  int interdit = -1;

  switch (nombreTours) {
    case FLOP:
      while (i < DEUX_CARTES_INITIALES + 2) {
        if (i != interdit) {
          for (int j = i + 1; j < DEUX_CARTES_INITIALES + 3; j++) {
            if (j != interdit && getCartesBoardEtMain(i) == getCartesBoardEtMain(j)) {
              if (interdit == -1)
                interdit = j;
              compteur++;
              i++;
            }
          }
        }
        i++;
      }
      break;
    case TURN:
      while (i < DEUX_CARTES_INITIALES + 3) {
        if (i != interdit) {
          for (int j = i + 1; j < DEUX_CARTES_INITIALES + 4; j++) {
            if (j != interdit && getCartesBoardEtMain(i) == getCartesBoardEtMain(j)) {
              if (interdit == -1)
                interdit = j;
              compteur++;
              i++;
            }
          }
        }
        i++;
      }
      break;
    case RIVER:
      while (i < DEUX_CARTES_INITIALES + 4) {
        if (i != interdit) {
          for (int j = i + 1; j < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; j++) {
            if (j != interdit && getCartesBoardEtMain(i) == getCartesBoardEtMain(j)) {
              if (interdit == -1)
                interdit = j;
              compteur++;
              i++;
            }
          }
        }
        i++;
      }
      break;
  }

  if (compteur >= 2)
    return true;
  else
    return false;
}

// TODO: coder pour l'AS
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

std::string Joueurs::estCarteHaute(int nombreTours) {
  int tab[DEUX_CARTES_INITIALES + TAILLE_PLATEAU] = {0, 0, 0, 0, 0, 0, 0};
  string carteHaute;
  int tmp = 0;

  switch (nombreTours) {
    case PREFLOP:
      for (int i = 0; i < DEUX_CARTES_INITIALES; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableauPourQuinte(tab);
      tmp = tab[6];
      carteHaute = to_string(tmp);
      break;
    case FLOP:
      for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableauPourQuinte(tab);

      tmp = tab[6];
      carteHaute = to_string(tmp);
      break;
    case TURN:
      for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableauPourQuinte(tab);
      tmp = tab[6];
      carteHaute = to_string(tmp);
      break;
    default:
      for (int i = 0; i < DEUX_CARTES_INITIALES + TAILLE_PLATEAU; i++) {
        tab[i] = getCartesBoardEtMain(i)._hauteur;
      }

      trierTableauPourQuinte(tab);
      tmp = tab[6];
      carteHaute = to_string(tmp);
      break;
  }
  if (carteHaute == "13")
    return(ROI);
  else if (carteHaute == "12")
    return(DAME);
  else if (carteHaute == "11")
    return(VALET);
  else
    return carteHaute;
}
