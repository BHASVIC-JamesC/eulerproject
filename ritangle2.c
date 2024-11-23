#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
int main(void) {
    int a=2024,count = 0;
    double c;
    for(int i = 1;i<=100000;i++) {
        c = sqrt(a*a+i*i);
        int integerc = c;
        double difference = c - integerc;
        if(difference>0) {
            NULL;
        }
        else {
            count++;
            printf("[%d][%d][%f]\n",a,i,c);
                }



    }
    printf("\n%d",count);
    return 0;
}