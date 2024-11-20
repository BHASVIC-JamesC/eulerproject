#include <stdio.h>
#include <string.h>

void triangle_numbers(int n, char list[2][100001]);

int main(void) {
    char list[2][100001] = {{0}};
    char word[9] = "ritangle";
    int placement = 0;


    for (int i = 1; i < 100001; i++) {
        if (i % 90 == 0) {
            list[0][i] = word[placement];
            placement = (placement + 1) % 8;
        }
    }

    triangle_numbers(450, list);
    return 0;
}

void triangle_numbers(int n, char list[2][100001]) {
    char word[9] = "triangle";
    int character = 0;

    // Populate list[1] with "triangle" at triangle number indices
    for (int p = 1; p <= n; p++) {
        int placement = (p * (p + 1)) / 2;
        if (placement < 100001) {
            list[1][placement] = word[character];
            character = (character + 1) % 8;
        }
    }

    // Print the list
    for (int h = 0; h < 100001; h++) {
        for(int x = 0;x<8;x++){

        if(list[0][h] == list[1][h] && list[0][h] == word[x]) {
            printf("these are the name characters: %c%c\nit was found at index %d\n",list[0][h],list[1][h],h);
            break;
        }
        }
    }
}
