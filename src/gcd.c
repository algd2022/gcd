#include <stdio.h>

const unsigned int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y) {
  if (x == 0) return y;
  return Euclidean_gcd_rec(y % x, x);
}

unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y) {
  while (x != 0) {
    unsigned int tmp = x;
    x = y % x;
    y = tmp;
  }
  return y;
}

unsigned int binary_gcd_tail_rec(unsigned int x, unsigned int y,
                                 unsigned int mag) {
  if (x == 0) return y << mag;
  if (y == 0) return x << mag;
  if ((x & 1) == 0 || (y & 1) == 0) {
    unsigned int x_zero_count = __builtin_ctzll(x);
    unsigned int y_zero_count = __builtin_ctzll(y);
    if (x_zero_count > y_zero_count)
      return binary_gcd_tail_rec(x >> x_zero_count, y >> y_zero_count,
                                 y_zero_count + mag);
    else
      return binary_gcd_tail_rec(x >> x_zero_count, y >> y_zero_count,
                                 x_zero_count + mag);
  }
  if (x >= y) return binary_gcd_tail_rec((x - y) >> 1, y, mag);
  return binary_gcd_tail_rec((y - x) >> 1, x, mag);
}

unsigned int binary_gcd_rec(unsigned int x, unsigned int y) {
  return binary_gcd_tail_rec(x, y, 0);
}

unsigned int binary_gcd_itr(unsigned int x, unsigned int y) {
  unsigned int mag = 0;
  while (1) {
    if (x == 0) return y << mag;
    if (y == 0) return x << mag;
    if ((x & 1) == 0 && (y & 1) == 0) {
      x >>= 1;
      y >>= 1;
      mag++;
    } else if ((x & 1) == 0) {
      x >>= 1;
    } else if ((y & 1) == 0) {
      y >>= 1;
    } else if (x >= y) {
      x = (x - y) >> 1;
    } else {
      unsigned int tmp = x;
      x = (y - x) >> 1;
      y = tmp;
    }
  }
}

int main() {
  unsigned int i, j, c;

  c = 0;
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      // if(Euclidean_gcd_rec(i, j) == 1){
      //   c++;
      // }
      // if (Euclidean_gcd_itr(i, j) == 1) {
      //   c++;
      // }
      if (binary_gcd_rec(i, j) == 1) {
        c++;
      }
      if (binary_gcd_rec(i, j) != Euclidean_gcd_rec(i, j)) {
        printf("%d %d\n", i, j);
      }
    }
  }
  c = 2 * c + 1;

  printf("%f\n", (double)c / (n * n));
  return 0;
}
