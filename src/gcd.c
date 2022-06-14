#include <stdio.h>

const int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y){
  if(x==0) return y;
  return Euclidean_gcd_rec(y % x, x);
}


unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y){
  while(x != 0){
    unsigned int z = x;
    x = y % x;
    y = z;
  }
  return y;
}


unsigned int binary_gcd_rec(unsigned int x, unsigned int y){
  if(x == 0) return y;
  if(y == 0) return x;
  if( (x & 1) == 0 ){
    if( (y & 1) == 0) return 2*binary_gcd_rec(x/2 , y/2);
    return binary_gcd_rec(x/2 , y);
  }
  if( (y & 1) == 0) return binary_gcd_rec(x , y/2);
  if(y >= x) return binary_gcd_rec( x , ( y - x )/2 );
  return binary_gcd_rec( ( x - y )/2 , y );
}


unsigned int binary_gcd_itr(unsigned int x, unsigned int y){
  unsigned int m = 1;
  while(x*y != 0){
    if( (x & 1) == 0 ){
      x = x/2;
      if( (y & 1) == 0 ){
        y = y/2;
        m = 2 * m;
      }
    } 
    else if( (y & 1) == 0 ){
      y = y/2;
    } 
    else{
      if( y >= x ) y = ( y - x )/2;
      else x = ( x - y )/2;
    }
  }
  if(x == 0) return y * m;
  return x * m;
}



int main(){
  unsigned int i, j, c;


  c = 0;
  for(i = 1; i <= n; i++){
    for(j = i + 1; j <= n; j++){
      if(binary_gcd_itr(i, j) == 1){
        c++;
      }
    }
  }
  c = 2 * c + 1;

  printf("%f\n", (double) c / (n * n));
  return 0;
}
