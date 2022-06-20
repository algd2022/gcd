#include <stdio.h>

const int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y)
{
    if (y == 0)
        return x;
    else
        return Euclidean_gcd_rec(y, x % y);
}

unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y)
{
    while (y != 0)
    {
        unsigned int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

unsigned int binary_gcd_rec(unsigned int x, unsigned int y)
{
    if (x == 0)
        return y;
    else if (y == 0)
        return x;
    else if ((x & 1) == 0 && (y & 1) == 0)
        return 2 * binary_gcd_rec(x >> 1, y >> 1);
    else if ((x & 1) == 0)
        return binary_gcd_rec(x >> 1, y);
    else if ((y & 1) == 0)
        return binary_gcd_rec(x, y >> 1);
    else if (x > y)
        return binary_gcd_rec((x - y) >> 1, y);
    else
        return binary_gcd_rec((y - x) >> 1, x);
}

/*
unsigned int binary_gcd_itr(unsigned int x, unsigned int y)
{
}
*/
int main()
{
    unsigned int i, j, c;

    c = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (Euclidean_gcd_rec(i, j) == 1)
            {
                c++;
            }
        }
    }
    c = 2 * c + 1;

    printf("%f\n", (double)c / (n * n));
    return 0;
}
