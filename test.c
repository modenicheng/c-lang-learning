#include <stdio.h>

int main() {
  float x = 2, y;
  if (x < 0)
    y = 0;
  else if (x < 5 && !x)
    y = 1 / (x + 2);
  else if (x < 10)
    y = 1 / x;
  else
    y = 10;
  printf("%f\n", y);
}
