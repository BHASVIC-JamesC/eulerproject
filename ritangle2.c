#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    for(int people = 0; people<=5;people++) {
        int countDice = 0,countCoin = 0;
        int diceRoll;
        int coinFlip;
        do {
            countDice++;
            diceRoll = (rand() % 6)+1;
        }
        while(diceRoll != 6);
        do {
            countCoin ++;
            coinFlip = (rand()%2)+1;}
        while(coinFlip != 2);
        printf("it took %d dice rolls and %d coin flips.\n",countDice,countCoin);
    }

    return 0;
}