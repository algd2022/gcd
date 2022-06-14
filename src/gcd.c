#include <stdio.h>

#define mod2(x) !(x & 1)

const int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y)
{
  if (x == 0)
    return y;
  return Euclidean_gcd_rec(y % x, x);
}

unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y)
{
  unsigned int z;
  while (x != 0)
  {
    z = x;
    x = y % x;
    y = z;
  }
  return y;
}

unsigned int binary_gcd_rec(unsigned int x, unsigned int y)
{
  if (x == 0)
    return y;
  else if (y == 0)
    return x;
  else if (mod2(x) && mod2(y))
    return 2 * binary_gcd_rec(x / 2, y / 2);
  else if (mod2(x))
    return binary_gcd_rec(x / 2, y);
  else if (mod2(y))
    return binary_gcd_rec(x, y / 2);
  else if (y >= x)
    return binary_gcd_rec(x, (y - x) / 2);
  else
    return binary_gcd_rec((x - y) / 2, y);
}

unsigned int binary_gcd_itr(unsigned int x, unsigned int y)
{
  unsigned mult = 0;
  while (1)
  {
    if (x == 0)
      return y << mult;
    else if (y == 0)
      return x << mult;
    else if (mod2(x) && mod2(y))
    {
      x = x >> 1;
      y = y >> 1;
      ++mult;
    }
    else if (mod2(x))
      x = x >> 1;
    else if (mod2(y))
      y = y >> 1;
    else if (y >= x)
      y = (y - x) >> 1;
    else
      x = (x - y) >> 1;
  }
}

int main()
{
  unsigned int i, j, c;

  c = 0;
  for (i = 1; i <= n; i++)
  {
    for (j = i + 1; j <= n; j++)
    {
      if (binary_gcd_itr(i, j) == 1)
      {
        c++;
      }
    }
  }
  c = 2 * c + 1;

  printf("%f\n", (double)c / (n * n));
  return 0;
}
