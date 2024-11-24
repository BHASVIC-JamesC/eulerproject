#include <stdio.h>
#include <math.h>

// Function to check if the sum of digits is a prime number
int prime(int a, int b, int c) {
    int number = a + b + c;
    if (number <= 1) return 0; // Numbers <= 1 are not prime
    if (number == 2) return 1; // 2 is prime
    if (number % 2 == 0) return 0; // Even numbers > 2 are not prime

    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) return 0; // Divisible, not prime
    }
    return 1; // Prime
}

// Function to check if a number is a perfect square
int is_perfect_square(int number) {
    int root = sqrt(number);
    return root * root == number;
}

int main(void) {
    int found = 0;
    for (int oneAC = 100; oneAC < 1000; oneAC++) {
        int digit1oneAC = oneAC / 100;
        int digit2oneAC = (oneAC / 10) % 10;
        int digit3oneAC = oneAC % 10;

        for (int oneDN = 100; oneDN < 1000; oneDN++) {
            int digit1oneDN = oneDN / 100;
            int digit2oneDN = (oneDN / 10) % 10;
            int digit3oneDN = oneDN % 10;

            // Ensure 1AC and 1DN start with the same digit
            if (digit1oneAC != digit1oneDN) continue;

            int sumOneAC = digit1oneAC + digit2oneAC + digit3oneAC;
            int sumOneDN = digit1oneDN + digit2oneDN + digit3oneDN;

            if (sumOneAC != sumOneDN) continue;

            for (int twoDN = 10; twoDN < 100; twoDN++) {
                int digit1twoDN = twoDN / 10;
                int digit2twoDN = twoDN % 10;

                // First digit of 2DN must match second digit of 1AC
                if (digit1twoDN != digit2oneAC) continue;

                if (sumOneDN != digit1twoDN + digit2twoDN) continue;
                if (twoDN != (digit1oneAC * digit2oneAC * digit3oneAC) + (digit1oneDN * digit2oneDN * digit3oneDN)) continue;

                for (int fiveAC = 100; fiveAC < 1000; fiveAC++) {
                    int digit1fiveAC = fiveAC / 100;
                    int digit2fiveAC = (fiveAC / 10) % 10;
                    int digit3fiveAC = fiveAC % 10;

                    // Last digit of 1DN must match the first digit of 5AC
                    if (digit3oneDN != digit1fiveAC) continue;

                    if (!prime(digit1fiveAC, digit2fiveAC, digit3fiveAC)) continue;

                    for (int square = 1; square * square < fiveAC; square++) {
                        int squareValue = square * square;
                        int fourDN = fiveAC - squareValue;

                        if (fourDN < 10 || fourDN >= 100) continue; // Ensure 4DN is two digits

                        int digit1fourDN = fourDN / 10;
                        int digit2fourDN = fourDN % 10;

                        for (int threeAC = 10; threeAC < 100; threeAC++) {
                            int digit1threeAC = threeAC / 10;
                            int digit2threeAC = threeAC % 10;

                            // Second digit of 3AC must match first digit of 4DN
                            if (digit2threeAC != digit1fourDN) continue;

                            // Second digit of 2DN must match the first digit of 3AC
                            if (digit2twoDN != digit1threeAC) continue;

                            if (threeAC != (fourDN - (digit1fourDN + digit2fourDN))) continue;

                            // Second digit of 4DN must match third digit of 5AC
                            if (digit2fourDN != digit3fiveAC) continue;

                            // All conditions satisfied
                            printf("1AC=%d, 1DN=%d, 2DN=%d, 3AC=%d, 4DN=%d, 5AC=%d\n",
                                   oneAC, oneDN, twoDN, threeAC, fourDN, fiveAC);
                            found = 1;
                        }
                    }
                }
            }
        }
    }
    if (!found) printf("No solutions found.\n");
    printf("Finished now.\n");
    return 0;
}
