#include <stdio.h>

const unsigned int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y) {
  return x == 0 ? y : Euclidean_gcd_rec(y % x, x);
}

int main() {
  unsigned int i, j, c;

  c = 0;
  for(i = 1; i <= n; i++) {
    for(j = i + 1; j <= n; j++) {
      // printf("i=%u, j=%u, gcd=%u\n", i, j, Euclidean_gcd_rec(i, j));
      if(Euclidean_gcd_rec(i, j) == 1) {
        c++;
      }
    }
  }
  c = 2 * c + 1;

  // 切り捨てないように`c`を`double`へキャスト
  printf("%f\n", (double) c / (n * n));
  return 0;
}
