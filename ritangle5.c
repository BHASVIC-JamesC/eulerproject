#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to check if a number is a perfect square
int is_perfect_square(int num) {
    int root = sqrt(num);
    return root * root == num;
}

// Function to reverse a number
int reverse_number(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

// Function to calculate the sum of digits of a number
int digit_sum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

// Function to check if a number is a triangular number
int is_triangular(int num) {
    int n = (int)(sqrt(2 * num)); // Approximate the value of n
    return num == n * (n + 1) / 2; // Check if the number equals T_n
}

// Function to check if fiveAC is divisible by the sum of all required digits
int is_divisible_by_sum(int fiveAC, int oneAC, int oneDN, int threeAC, int fourDN) {
    int digit1oneAC = oneAC / 100;
    int digit2oneAC = (oneAC / 10) % 10;
    int digit3oneAC = oneAC % 10;

    int digit1oneDN = oneDN / 100;
    int digit2oneDN = (oneDN / 10) % 10;
    int digit3oneDN = oneDN % 10;

    int digit1threeAC = threeAC / 10;
    int digit2threeAC = threeAC % 10;

    int digit1fourDN = fourDN / 10;
    int digit2fourDN = fourDN % 10;

    int sum = digit1oneAC + digit2oneAC + digit3oneAC +
              digit1oneDN + digit2oneDN + digit3oneDN +
              digit1threeAC + digit2threeAC +
              digit1fourDN + digit2fourDN;

    return (fiveAC % sum == 0); // Check if fiveAC is divisible by the sum of all digits
}

// Function to check if 1DN follows the rule: 1DN = (digit sum of 1AC)^2 + 3AC
int check_1DN_rule(int oneAC, int oneDN, int threeAC) {
    int sum_of_digits = digit_sum(oneAC);
    int calculated_1DN = (sum_of_digits * sum_of_digits) + threeAC;
    return oneDN == calculated_1DN; // Check if 1DN equals the calculated value
}

// Function to check if 3AC is a triangular number minus 4DN
int check_3AC_rule(int threeAC, int fourDN) {
    // Check if 3AC is a triangular number minus 4DN
    return is_triangular(threeAC + fourDN);
}

int main(void) {
    int found = 0;

    for (int oneAC = 100; oneAC < 1000; oneAC++) {
        if (is_prime(oneAC)) continue;

        int digit1oneAC = oneAC / 100;
        int digit2oneAC = (oneAC / 10) % 10;
        int digit3oneAC = oneAC % 10;

        for (int oneDN = 100; oneDN < 1000; oneDN++) {


            int digit1oneDN = oneDN / 100;
            int digit2oneDN = (oneDN / 10) % 10;
            int digit3oneDN = oneDN % 10;

            if (digit1oneDN != digit1oneAC) continue; // 1AC and 1DN must start with the same digit

            // Check if 1DN follows the rule: 1DN = (digit sum of 1AC)^2 + 3AC
            for (int threeAC = 10; threeAC < 100; threeAC++) {
                if (!check_1DN_rule(oneAC, oneDN, threeAC)) continue; // Check if 1DN matches rule

                for (int fourDN = 10; fourDN < 100; fourDN++) {
                    if (!is_triangular(fourDN)) continue; // 4DN must be triangular

                    // Check if 3AC is a triangular number minus 4DN
                    if (!check_3AC_rule(threeAC, fourDN)) continue; // Check if 3AC is a triangular number minus 4DN

                    int digit1fourDN = fourDN / 10;
                    int digit2fourDN = fourDN % 10;

                    for (int twoDN = 10; twoDN < 100; twoDN++) {
                       if (reverse_number(threeAC) != twoDN) continue;

                        int digit1twoDN = twoDN / 10;
                        int digit2twoDN = twoDN % 10;
                        int digit1threeAC = threeAC / 10;
                        int digit2threeAC = threeAC % 10;

                        if (digit2twoDN != digit1threeAC) continue;
                        if (digit2threeAC != digit1fourDN) continue;
                        if (digit1twoDN != digit2oneAC) continue; // First digit of 2DN = second digit of 1AC

                        for (int fiveAC = 100; fiveAC < 1000; fiveAC++) {
                            int digit1fiveAC = fiveAC / 100;
                            int digit3fiveAC = fiveAC % 10;
                            if (fiveAC != oneDN +threeAC + fourDN) continue;
                            if (digit3oneDN != digit1fiveAC) continue;
                            if (digit3fiveAC != digit2fourDN) continue;
                            // All conditions satisfied, print the solution
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
    printf("Finished now...\n");
    return 0;
}
