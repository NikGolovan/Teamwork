#include "turing.hpp"

MachineTuring::MachineTuring() {}
MachineTuring::~MachineTuring() {}

void MachineTuring::setPremierRuban(int[] valeurs) {
  this._premier_ruban = valeurs;
}

MachineTuring MachineTuring::getPremierRuban() {
  return this._premier_ruban;
}
