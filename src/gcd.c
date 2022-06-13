#include <stdio.h>

const int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y){
  if(x == 0) return y;
  return Euclidean_gcd_rec(y % x, x);
}

unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y){
  while(x != 0) {
    unsigned int z = x;
    x = y % x;
    y = z;
  }
  return y;
}

unsigned int binary_gcd_rec(unsigned int x, unsigned int y){
  if(x == 0) return y;
  if(y == 0) return x;
  if((x & 1) == 0)
    if((y & 1) == 0) return binary_gcd_rec(x >> 1, y >> 1) << 1;
    else return binary_gcd_rec(x >> 1, y);
  else
    if((y & 1) == 0) return binary_gcd_rec(x, y >> 1);
    else if(y >= x) return binary_gcd_rec(x, (y-x) >> 1);
  return binary_gcd_rec((x-y) >> 1, y);
}

unsigned int binary_gcd_itr(unsigned int x, unsigned int y){
  unsigned int cor = 1, x_ = 0, y_ = 0;
  if(x == 0) return y;
  while(y != 0){
    x_ = (x & 1);
    y_ = (y & 1);
    if((x_ | y_) == 0) cor <<= 1;
    if(x_ == 0) x >>= 1;
    if(y_ == 0) y >>= 1;
    if(x_ & y_) {
      if(x > y) {
        unsigned int z = x;
        x = y;
        y = z;
      }
      y = (y - x) >> 1;
    }
  }
  return x * cor;
}


int main(){
  unsigned int i, j, c;

  c = 0;
  for(i = 1; i <= n; i++){
    for(j = i + 1; j <= n; j++){
      if(Euclidean_gcd_rec(i, j) == 1){
        c++;
      }
    }
  }
  c = 2 * c + 1;

  printf("%f\n", (double) c / (n * n));
  return 0;
}
