#ifndef __MACHINE_TURING__
#define __MACHINE_TURING__
#include <iostream>
#include <cstring>

using namespace std;

#define TAILLE_RUBAN_MAX 30

class MachineTuring {
private:
  int _premier_ruban[TAILLE_RUBAN_MAX];
  int _deuxieme_ruban[TAILLE_RUBAN_MAX];
  int _troisieme_ruban[TAILLE_RUBAN_MAX];
public:
  MachineTuring();
  ~MachineTuring();
  MachineTuring(const &MachineTuring);
  void &operator=(const &MachineTuring);
  void setPremierRuban(int valeurs[]);
  int[] getPremierRuban();
  void setDeuxiemeRuban(int valeurs[]);
  int[] getDeuxiemeRyban();
  void setTroisiemeRuban(int valeurs[]);
  int[] getTroisiemeRuban();
  int estLeNombrePair(int _premier_ruban[], int _deuxieme_ruban[], int _troisieme_ruban[]);
};

#endif
