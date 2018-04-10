#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

#define N0 3
#define N1 2
#define N2 1

struct signaux {
  int count0;
  int count1;
  int count2;
  string signal;
};

void count(signaux *signal) {
  signal->count0 = 0;
  signal->count1 = 0;
  signal->count2 = 0;

  for (int i = 5; i < signal->signal.size() - 3; i += 3) {
    if (signal->signal[i] == '0') {
      signal->count0++;
    } else if (signal->signal[i] == '1') {
      signal->count1++;
    } else {
      signal->count2++;
    }
  }
}

int main(int argc, char const *argv[]) {
  signaux signal2;

  signal2.signal = "F00F10F10F10F10F12F12F11F11F11F20";

  count(&signal2);

  if (signal2.count0 < N0 || signal2.count1 < N1 || signal2.count2 < N2) {
    cout << "Missile non identifié" << endl;
  } else if (log(signal2.count0) >= log(signal2.count1 + 4 * signal2.count2)) {
    cout << "Missile identifié : TYPE = A" << endl;
  } else if (log(signal2.count1) >= log(2 * signal2.count2)) {
    cout << "Missile identifié : TYPE = B" << endl;
  } else {
    cout << "Missile identifié : TYPE = C" << endl;
  }

/*
  signaux signal1;
  signal1.signal = "F00F10F10F11F12F21";
  count(&signal1);
  if (signal1.count0 < N0 || signal1.count1 < N1 || signal1.count2 < N2) {
    cout << "Missile non identifié" << endl;
  } else if (log(signal1.count0) >= log(signal1.count1 + 4 * signal1.count2)) {
    cout << "Missile identifié : TYPE = A" << endl;
  } else if (log(signal1.count1) >= log(2 * signal1.count2)) {
    cout << "Missile identifié : TYPE = B" << endl;
  } else {
    cout << "Missile identifié : TYPE = C" << endl;
  }
*/
  return 0;
}
