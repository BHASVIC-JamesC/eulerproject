#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int digitGetter(int num,int digitPlace);
int main(void) {


    for(int i = 1023456789;i<10000000000;i++) {
        int digit1 = digitGetter(i,10);
        int digit2 = digitGetter(i,9);
        int digit3 = digitGetter(i,8);
        int digit4 = digitGetter(i,7);
        int digit5 = digitGetter(i,6);
        int digit6 = digitGetter(i,5);
        int digit7 = digitGetter(i,4);
        int digit8 = digitGetter(i,3);
        int digit9 = digitGetter(i,2);
        int digit10 = digitGetter(i,1);
        bool arr[10];
        bool state = true;
        memset(arr,false,sizeof(arr));
        arr[digit1] = true;
        arr[digit2] = true;
        arr[digit3] = true;
        arr[digit4] = true;
        arr[digit5] = true;
        arr[digit6] = true;
        arr[digit7] = true;
        arr[digit8] = true;
        arr[digit9] = true;
        arr[digit10] = true;
        for(int x = 0; x<=9;x++) {
            if(arr[x] == false){
                state = false;
            }
        }
            if(state == false) {
                continue;
            }

    }
    printf("done");
    return 0;
}


int digitGetter(int num,int digitPlace){
    int digit = 0;
    int power = 1;
    if(digitPlace == 1) {
        return num % 10;
    }
    for(int i = 1; i<digitPlace;i++) {
        power = power * 10;
    }

    digit = (num / (power)) % 10;
    return digit;

}