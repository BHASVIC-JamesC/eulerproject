#include <stdio.h>
#include <math.h>

int abundantNumber(int i);

int main(void) {
    int abundantNumbers[74224] = {0};
    int count = 0;
    for(int j = 12;j<300000;j++) {
        if(abundantNumber(j) == 1) {
            abundantNumbers[count] = j;
            count++;

        }
    }
    printf("%d",count);



    return 0;
}

int  abundantNumber(i) {

        int sum = 0;
        for(int j = 2;j<=(i/2);j++) {
            if (i % j == 0) {
              sum = sum + j;
            }
        }
        if(sum > i) {
        return 1;}

    return 0;

}