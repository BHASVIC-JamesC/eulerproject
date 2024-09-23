#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void) {
    setbuf(stdout, 0);
    //int number = 600851475143;
    int number = 4;
    int fact=1;
    for(int i =1;i<=number-1;i++) {
        fact = fact * i;
    }
    int answer = ((fact+1)/number)%1;
    if(answer == 0){
        printf("this number is prime");
    }
    else {
        printf("this number is not prime");
    }
    return 0;
}