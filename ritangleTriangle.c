#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int triangular(int number) {
    int n = (int)(sqrt(2 * number));
    if(number == n * (n+1)/2) {
        return 1;
    }
    return 0;
}

int is_prime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}



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


int main() {
    for(int a =11; a < 100; a = a + 2) {
        for(int b=11; b < 100; b= b + 2) {
            for(int c = 11;c<100;c = c + 2) {
                if(a+b >c || a+c >b || b+c > a) {
                    if(triangular(a+b+c)== 1) {
                        if(is_prime(a) == 0) {
                            if(is_prime(b)==0) {
                                if(is_prime(c)==0) {
                                    if(co_prime(a,b)==1) {
                                        if(co_prime(a,c)==1) {
                                            if(co_prime(b,c)==1) {
                                                printf("a:%d b:%d c:%d\n",a,b,c);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
