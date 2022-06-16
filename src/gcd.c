#include <stdio.h>

const int n = 10000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y){
    if (x == 0) return y;
    return Euclidean_gcd_rec(y % x, x);
}
unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y){
    while (x != 0) {
        unsigned int z = x;
        x = y % x;
        y = z;
    }
    return y;
}

unsigned int binary_gcd_rec(unsigned int x, unsigned int y){
    //arrange the order of 2 arguments of the function
    if (x > y) {
        return binary_gcd_rec(y, x);
    }
    else {
        //1. x is 0
        if (x == 0) {
            return y;
        }
        //2. x is even and non-zero
        else if (x - (x >> 1<<1) == 0) {
            //2.1 y is even (and non-zero)
            if (y - (y >> 1<<1) == 0) {
                return 2 * binary_gcd_rec(x >> 1, y >> 1);
            }
            //2.2 y is odd
            else {
                return binary_gcd_rec(x >> 1, y);
            }
        }
        //3. x is odd
        else {
            //3.1 y is even (and non-zero)
            if (y - (y >> 1 <<1) == 0) {
                return binary_gcd_rec(x, y >>1);
            }
            //3.2 y is odd
            else {
                return binary_gcd_rec(x, (y - x) >>1);
            }
        }
    }
}

unsigned int binary_gcd_itr(unsigned int x, unsigned int y) {
    unsigned int c = 1;
    while (x != 0) {
        //arrange the order of 2 arguments of the function
        if (x > y) {
            unsigned int z = y;
            y = x;
            x = z;
        }
        else {
            //1. x is even and non-zero
            if (x - (x >> 1 <<1)== 0) {
                //1.1 y is even (and non-zero)
                if (y - (y >> 1 <<1)== 0) {
                    c *= 2;
                    x >>= 1;
                    y >>= 1;;
                }
                //1.2 y is odd
                else {
                    x >>= 1;
                }
            }
            //2. x is odd
            else {
                //2.1 y is even (and non-zero)
                if (y - (y >> 1 <<1) == 0) {
                    y >>= 1;
                }
                //2.2 y is odd
                else {
                    y = (y - x) >> 1;
                }
            }
        }
    }
    //3. x is 0
    return c*y;
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
