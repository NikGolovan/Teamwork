#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define TROIS 3

void suite(int x) {
  printf("%d | ", x);
  if (x > 1) {
    if (x % 2 == 0) {
      suite(x / 2);
    } else {
      suite(TROIS * x + 1);
    }
  }
}

int main(int argc, char const *argv[]) {
  int x = 0;

  printf("----- CALCUL D'UNE SUITE -----\n");

  printf("Donnez NOUS U_0 : ");
  scanf("%d%*c", &x);

  suite(x);
  printf("\n");

  return 0;
}
