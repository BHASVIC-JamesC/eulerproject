#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int abundantNumber(int i);
bool twoSum(int ,int* abundantNumbers);
int main(void) {
    int abundantNumbers[14852] = {0};
    int count = 0;
    for(int j = 12;j<30000;j++) {
        if(abundantNumber(j) == 1) {
            abundantNumbers[count] = j;
            count++;
            abundantNumbers[count] = j;
            count++;

        }
    }

    for(int i =0;i<=14851;i++) {
        printf("%d\n",abundantNumbers[i]);
    }
    int count2 = 0;
    int sum2=0;
    for(int j = 1;j<=28123;j++) {
        if(!twoSum(j,abundantNumbers)){
            count2++;
            sum2 = sum2 + j;
        }

    }
    printf("%d   %d",count2,sum2);
    return 0;
}

int abundantNumber(int i) {

        int sum = 0;
        for(int j = 1;j<=(i/2);j++) {
            if (i % j == 0) {
              sum = sum + j;
            }
        }
        if(sum > i) {
        return 1;}

    return 0;
}

bool twoSum(int x,int* abundantNumbers) {
    int left = 0;
    int right = 14851;
    while(left < right) {
        if(abundantNumbers[left] + abundantNumbers[right] == x) {
            return true;
        }
        if(abundantNumbers[left] + abundantNumbers[right] < x) {
            left ++;
        }
        if (abundantNumbers[left] + abundantNumbers[right] > x) {
            right--;
        }
    }
    return false;
}