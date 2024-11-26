#include <stdio.h>
#include <math.h>


int gcd(int a, int b)
{
    // Find Minimum of a and b
    int result = ((a < b) ? a : b);
    while (result > 0) {
        // Check if both a and b are divisible by result
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    // return gcd of a nd b
    return result;
}

int co_prime(int num1,int num2) {
    if(gcd(num1,num2) == 1) {
        return 1;
    }
    return 0;
}

int main(void) {

    for(int a = 10;a<100;a++) {
        for(int b = 10;b<1000;b++) {
            for(int c = 10;c<1000;c++) {
                if(co_prime(a,b)==1 && co_prime(a,c) == 1 && co_prime(b,c)== 1) {
                    if(a*a + b*b == c*c) {
                        printf("a: %d b: %d c:%d\n",a,b,c);
                    }
                }
            }
        }
    }
    return 0;
}