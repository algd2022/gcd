#include <stdio.h>

const int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y) {
    if (x == 0) {
        return y;
    }
    return Euclidean_gcd_rec(y % x, x);
}

unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y) {
    while (x != 0) {
        unsigned int z = x;
        x = y % x;
        y = z;
    }
    return y;
}

unsigned int binary_gcd_rec(unsigned int x, unsigned int y) {
    if (x == 0) {
        return y;
    } else if (y == 0) {
        return x;
    } else if (x % 2 == 0) {
        if (y % 2 == 0) {  // (even, even)
            return 2 * binary_gcd_rec(x / 2, y / 2);
        } else {  // (even, odd)
            return binary_gcd_rec(x / 2, y);
        }
    } else {
        if (y % 2 == 0) {  // (odd, even)
            return binary_gcd_rec(x, y / 2);
        } else {  // (odd, odd)
            if (y >= x) {
                return binary_gcd_rec(x, (y - x) / 2);
            } else {
                return binary_gcd_rec((x - y) / 2, y);
            }
        }
    }
}

unsigned int binary_gcd_itr(unsigned int x, unsigned int y) {
    unsigned int t = 1;
    // if x and y are even, doubles t and halves x and y, and finally multiply
    // (x or y) by t
    while (1) {
        if (x == 0) {
            return y * t;
        } else if (y == 0) {
            return x * t;
        } else if ((x % 2 == 0) && (y % 2 == 0)) {
            x = x / 2;
            y = y / 2;
            t = t * 2;
        } else if (x % 2 == 0) {
            x = x / 2;
        } else if (y % 2 == 0) {
            y = y / 2;
        } else if (y >= x) {
            y = (y - x) / 2;
        } else {
            x = (x - y) / 2;
        }
    }
}

int main() {
    unsigned int i, j, c;

    c = 0;
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            // if (Euclidean_gcd_itr(i, j) == 1) {
            // if (binary_gcd_rec(i, j) == 1) {
            // if (binary_gcd_itr(i, j) == 1) {
            if (Euclidean_gcd_rec(i, j) == 1) {
                c++;
            }
        }
    }
    c = 2 * c + 1;

    printf("%f\n", (double)c / (n * n));
    return 0;
}
