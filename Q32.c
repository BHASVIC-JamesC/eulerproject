#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

void set(int a,int b, int c);

int main(void) {
    int total[1000] = {0};
    int pointer = 0;
    int totalsum = 0;
    for(int a = 11;a<=99;a++) {
        for(int b = 100;b<=999;b++) {
            int c = a*b;
            if(c > 1000) continue;




        }
    }

    for(int i = 0;i<1000;i++) {
        printf("%d\n",total[i]);
    }
    return 0;
}

void set(int a,int b,int c) {
    int digit1a = a/10;
    int digit2a = a%10;
    int digit1b = b/100;
    int digit2b = b/10 % 10;
    int digit3b = b %10;
    int digit1c = c/1000;
    int digit2c = c/100 %10;
    int digit3c = c/10 %10;
    int digit4c = c % 10;


}