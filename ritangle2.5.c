#include <stdio.h>
#include <math.h>

int main(void) {
    int a = 2024, asquared = a * a, count = 0, smallestb = 100000;
    int factor1, factor2;
    int b, c;

    for (factor1 = 1; factor1 * factor1 <= asquared; factor1++) {
        if (asquared % factor1 == 0) {
            factor2 = asquared / factor1;

            if ((factor2 - factor1) % 2 == 0 && (factor1 + factor2) % 2 == 0) {
                b = (factor2 - factor1) / 2;
                c = (factor1 + factor2) / 2;

                if (c*c == (a*a + b*b) && b > 0 && c > 0) {
                    count++;
                    if (b < smallestb) {
                        smallestb = b;
                    }
                    printf("Valid triangle: a = %d, b = %d, c = %d\n", a, b, c);
                }
            }
        }
    }

    printf("\nTotal valid triangles (N): %d\n", count);
    printf("Smallest b (B): %d\n", smallestb);
    printf("N x B: %d\n", count * smallestb);
    return 0;
}
