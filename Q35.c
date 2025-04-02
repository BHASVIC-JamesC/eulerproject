#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


#include <string.h>

void sieve(int n,int* arr);


int main(void){
    int arr[78499] = {0};
    sieve(1000000,arr);
    for(int j = 0;j<78499;j++) {
        int digitsum = 0;
        bool state = true;
        int num = arr[j];
        while(num != 0) {
            int integer = num%10;
            num = num /10;
            digitsum = digitsum + integer;
            if(integer == 0 || integer % 2 == 0) {
                state = false;
            }
        }
        if(state == true || digitsum % 3 == 0) {
            printf("%d\n",arr[j]);
        }


    }


  return 0;
}



void sieve(int n,int* arr) {
    int count = 0;
    bool prime[n+1];
    memset(prime,true,sizeof(prime));

    for(int x = 2;x*x<=n;x++) {

        if(prime[x] == true) {
            for(int p = x*x ;p<= n;p += x) {
                prime[p] = false;
            }
        }
    }

    for(int j =2; j<= n;j ++) {
        if(prime[j]== true) {
            arr[count] = j;
            count ++;

        }
    }
}

