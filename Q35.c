#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


#include <string.h>

void sieve(int n);


int main(void){

    sieve(1000000);
  return 0;}



void sieve(int n) {

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
            //printf("\n%d",j);

        }
    }
}