#include "turing.hpp"

int main(int argc, char const *argv[]) {
  MachineTuring machine;

  machine.setPremierRuban(25);
  cout << "1 ruban : " << machine.getPremierRuban() << endl;

  return 0;
}
