#include <stdio.h>
#include <math.h>


int is_triangular(int num) {
    int n = (int)(sqrt(2 * num)); // Approximate the value of n
    return num == n * (n + 1) / 2; // Check if the number equals T_n
}

int odd(int number) {
    if(number %2 == 1) {
        return 1;
    }
    return 0;
}
int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}
int co_prime(int a, int b) {
    if(gcd(a,b) == 1) {
        return 1; // returns 1 for co prime
    }

    return 0; // not co prime

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

int primitiveP(int a,int b,int c) {
    if(a*a == b*b + c*c) {
        if(co_prime(a,b) == 1 && co_prime(a,c) == 1 && co_prime(b,c) == 1) {
            return 1;
        }
    }
    else if(b*b == a*a + c*c) {
        if(co_prime(a,b) == 1 && co_prime(a,c) == 1 && co_prime(b,c) == 1) {
            return 1;
        }
    }
    else if(c*c == a*a + b*b) {
        if(co_prime(a,b) == 1 && co_prime(a,c) == 1 && co_prime(b,c) == 1) {
            return 1;
        }
    }
    return 0;
}

int is_perfect_square(int num) {
    int root = sqrt(num);
    return root * root == num;
}

int main(void) {
    int found = 0;
    for(int oneAC = 10; oneAC<100;oneAC++) {
        for(int twoAC = 10;twoAC<100;twoAC++) {
            for(int fourAC = 10;fourAC < 100;fourAC++) {
                if(!is_triangular(oneAC+twoAC+fourAC)) continue;
                if(odd(oneAC) == 0 ) continue;
                if(odd(twoAC)==0) continue;
                if(odd(fourAC)== 0) continue;
                if(is_prime(oneAC)) continue;
                if(is_prime(twoAC)) continue;
                if(is_prime(fourAC)) continue;
                if(co_prime(oneAC,twoAC) == 0 || co_prime(oneAC,fourAC) == 0 || co_prime(twoAC,fourAC) == 0) continue;
                for(int sixAC = 100;sixAC < 1000; sixAC ++) {
                    for(int eightAC = 100; eightAC < 1000;eightAC ++) {
                        for(int tenDN = 10;tenDN < 100;tenDN++) {
                            for(int threeDN =100;threeDN<1000;threeDN++) {
                                //such that 2dn+3dn form a square
                                for(int twoDN = 100;twoDN<1000;twoDN++) {
                                    if(!is_perfect_square(threeDN+twoDN)) continue;


                            for(int elevenAC = 10;elevenAC < 100;elevenAC++) {
                                for(int twelveDN = 10;twelveDN < 100;twelveDN++) {
                                    if(primitiveP(tenDN,elevenAC,twelveDN) == 0) continue;
                                    for(int fiveDN = 10;fiveDN<100;fiveDN++) {
                                        for(int nineDN = 100;nineDN<1000;nineDN++) {
                                            for(int fourteenAC = 100;fourteenAC<1000;fourteenAC ++) {
                                                if(primitiveP(tenDN,elevenAC,twelveDN) == 0) continue;
                                                for(int thirteenAC = 100;thirteenAC < 1000;thirteenAC++) {
                                                    for(int sevenDN = 100;sevenDN<1000;sevenDN++) {
                                                        for(int oneDN = 10;oneDN< 100;oneDN++) {
                                                            if(primitiveP(tenDN,elevenAC,twelveDN) == 0) continue;

                                                            int digit2oneDN = oneDN % 10;
                                                            int digit1sixAC = sixAC/100;
                                                            if(digit2oneDN != digit1sixAC) continue;

                                                            int digit2sixAC = (sixAC/10) % 10;
                                                            int digit1sevenDN = sevenDN / 100;
                                                            if(digit2sixAC != digit1sevenDN) continue;

                                                            int digit3sevenDN = sevenDN %10;
                                                            int digit2thirteenAC = (thirteenAC/10)%10;
                                                            if(digit3sevenDN != digit2thirteenAC) continue;

                                                            int digit2tenDN = tenDN % 10;
                                                            int digit1thirteenAC = thirteenAC/100;
                                                            if(digit2tenDN != digit1thirteenAC) continue;

                                                            int digit1elevenAC = elevenAC/10;
                                                            int digit3twoDN = (twoDN/10) % 10;
                                                            if(digit1elevenAC != digit3twoDN) continue;

                                                            int digit2twoAC = twoAC %10;
                                                            int digit1threeDN = threeDN/100;
                                                            if(digit2twoAC != digit1threeDN) continue;

                                                            int digit2threeDN = (threeDN/10) % 10;
                                                            int digit1eightAC = eightAC /100;
                                                            if(digit2threeDN != digit1eightAC) continue;

                                                            int digit3threeDN = threeDN % 10;
                                                            int digit2elevenAC = elevenAC % 10;
                                                            if(digit3threeDN != digit2elevenAC) continue;

                                                            int digit3sixAC = sixAC % 10;
                                                            int digit2twoDN = (twoDN/10) % 10;
                                                            if(digit3sixAC != digit2twoDN) continue;

                                                            int digit2eightAC = (eightAC / 10) % 10;
                                                            int digit1nineDN = nineDN / 100;
                                                            if(digit2eightAC != digit1nineDN) continue;

                                                            int digit3eightAC = eightAC % 10;
                                                            int digit2fiveDN = fiveDN % 10;
                                                            if(digit3eightAC != digit2fiveDN) continue;

                                                            int digit2fourAC = fourAC % 10;
                                                            int digit1fiveDN = fiveDN / 10;
                                                            if(digit2fourAC != digit1fiveDN) continue;

                                                            int digit3nineDN = nineDN % 10;
                                                            int digit2fourteenAC = (fourteenAC / 10) % 10;
                                                            if(digit3nineDN != digit2fourteenAC) continue;

                                                            int digit2twelveDN = twelveDN % 10;
                                                            int digit3fourteenAC = fourteenAC % 10;
                                                            if(digit2twelveDN != digit3fourteenAC) continue;
                                                            printf("1ac: %d\n",oneAC);
                                                            printf("2ac: %d\n",twoAC);
                                                            printf("4ac: %d\n",fourAC);
                                                            printf("6ac: %d\n",sixAC);
                                                            printf("8ac: %d\n",eightAC);
                                                            printf("2dn: %d\n",twoDN);
                                                            printf("3dn: %d\n",threeDN);
                                                            printf("11ac: %d\n",elevenAC);
                                                            printf("10dn: %d\n",tenDN);
                                                            printf("12dn: %d\n",twelveDN);
                                                            printf("14ac: %d\n",fourteenAC);
                                                            printf("9dn: %d\n",nineDN);
                                                            printf("5dn: %d\n",fiveDN);
                                                            printf("13ac: %d\n",thirteenAC);
                                                            printf("7dn: %d\n",sevenDN);
                                                            printf("1dn: %d\n\n\n",oneDN);

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
                    }
                }
            }
        }
    }
}
