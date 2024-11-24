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

// Function to calculate the sum of specified digits and check divisibility
int is_divisible_by_combined_sum(int fiveAC, int oneAC, int oneDN, int threeAC) {
    int sum = 0;

    // Add digits of 5AC
    int temp = fiveAC;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }

    // Add first two digits of 1DN
    sum += oneDN / 100; // First digit
    sum += (oneDN / 10) % 10; // Second digit

    // Add second and third digits of 1AC
    sum += (oneAC / 10) % 10; // Second digit
    sum += oneAC % 10; // Third digit

    // Add digits of 3AC
    temp = threeAC;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }

    // Check divisibility of 5AC by the combined sum
    return fiveAC % sum == 0;
}

int main(void) {
    int found = 0;

    for (int oneAC = 100; oneAC < 1000; oneAC++) {
        if (!is_perfect_square(oneAC)) continue; // 1AC must be a perfect square

        int digit1oneAC = oneAC / 100;
        int digit2oneAC = (oneAC / 10) % 10;
        int digit3oneAC = oneAC % 10;

        for (int fourDN = 10; fourDN < 100; fourDN++) {
            if (!is_triangular(fourDN)) continue; // 4DN must be triangular

            for (int prime = 2; prime < 10; prime++) {
                if (!is_prime(prime)) continue; // Iterate through prime multipliers

                int oneDN = fourDN * prime;
                if (oneDN < 100 || oneDN >= 1000) continue; // 1DN must be three digits

                int digit1oneDN = oneDN / 100;
                int digit2oneDN = (oneDN / 10) % 10;
                int digit3oneDN = oneDN % 10;

                if (digit1oneDN != digit1oneAC) continue; // 1AC and 1DN must start with the same digit

                for (int twoDN = 10; twoDN < 100; twoDN++) {
                    if (!is_perfect_square(digit_sum(twoDN))) continue; // 2DN must have a square digit sum

                    int digit1twoDN = twoDN / 10;
                    int digit2twoDN = twoDN % 10;

                    if (digit1twoDN != digit2oneAC) continue; // First digit of 2DN = second digit of 1AC

                    for (int threeAC = 10; threeAC < 100; threeAC++) {
                        int reversed = reverse_number(threeAC);
                        if (!is_prime(reversed)) continue; // 3AC must be the reverse of a prime

                        int digit1threeAC = threeAC / 10;
                        int digit2threeAC = threeAC % 10;

                        if (digit1threeAC != digit2twoDN) continue; // First digit of 3AC = second digit of 2DN
                        if (digit2threeAC != fourDN / 10) continue; // Second digit of 3AC = first digit of 4DN

                        for (int fiveAC = 100; fiveAC < 1000; fiveAC++) {
                            int digit1fiveAC = fiveAC / 100;
                            int digit2fiveAC = (fiveAC / 10) % 10;
                            int digit3fiveAC = fiveAC % 10;

                            if (digit3fiveAC != fourDN % 10) continue; // Last digit of 4DN = last digit of 5AC
                            if (digit1fiveAC != digit3oneDN) continue; // First digit of 5AC = third digit of 1DN

                            if (!is_divisible_by_combined_sum(fiveAC, oneAC, oneDN, threeAC)) continue; // Check divisibility
                            if (digit1threeAC != 3) continue;
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
