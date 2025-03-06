#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int check(int first,int second,int base);

int main(void) {
    int count = 0;
    int decimals[1000] = {0};
    int place = 0;
    bool state = true;
    int first = 10;
    int second = 7;
    decimals[place] = first/second;
    place++;
    first = (first-second)*10;
    while(state == true) {
        decimals[place] = first/second;
        tempfirst

        for(int j = 1;j<100;j++) {
            if(decimals[j] == decimals[0]){
                state = false;
                break;
        }
        }

        count++;
    }

    printf("%d",count);



    return 0;
}

