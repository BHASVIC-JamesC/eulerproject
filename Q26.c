#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int periodic(int* decimals);

int main(void) {
    int max = 0;
    int position;
    for(int i = 2;i<1000;i++) {
        int decimals[2001] = {0};
        int place = 0;
        int first = 10;
        int second = i;
        decimals[place] = first/second;

        first = (first%second)*10;
        int x = 0;
        while(x<2001) {
            place++;
            decimals[place] = first/second;
            first = (first%second)*10;

            x++;
        }
        int ans = periodic(decimals);
        if(ans > max) {
            max = ans;
            position = i;
        }
    }

    printf("the value of d:%d",position);
    printf("\nthe reoccurance cycle:%d",max);
    return 0;
}

int periodic(int* decimals) {
    int arr[1001] = {0};
    arr[0] = decimals[0];
    int pointer = 0;
    int length = 1;
    for(int i = 1;i<2001;i++) {
        if(length + i >= 2000 ) {
            return 0;
        }
        bool Case = true;
        for(int j = 0;j<= length;j++) {
            //check if the decimals index i is the same as the sequence in arr
            if(decimals[i+j] == arr[j]) {
                Case = true;

            }
            else {
                Case = false;
                length ++;
                arr[i] = decimals[i];
                break;
            }
        }
        if(Case == true) {
            if(arr[0] == decimals[i+length+1]) {
                return length;
            }
        }
    }
}
