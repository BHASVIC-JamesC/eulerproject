#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int count(int* coins,int sum);

int main(void) {

    int coins[8] = {1,2,5,10,20,50,100,200};

    printf("%d",count(8,200));

    return 0;
}


int count(int* coins,int sum) {
    int max = sizeof(coins)/sizeof(coins[0]);
    int dp[max][sum];
    for(int i = 0; i< max;i++) {
        for(int j = 0; j< sum;j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    for(int i = 0; i < max;i++) {
        for(int j =1;j < sum;j++) {
            dp[i][j+1] = dp[i][j-1] + (dp[i][j] - dp[i-1][j-1]);
        }
    }
    return dp[max][sum];
}