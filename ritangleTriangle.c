#include <stdio.h>
#include <math.h>


int nextPermutation(int *arr, int n) {
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) i--;
    if (i < 0) return 0;

    int j = n - 1;
    while (arr[j] <= arr[i]) j--;

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    for (int k = i + 1, l = n - 1; k < l; k++, l--) {
        temp = arr[k];
        arr[k] = arr[l];
        arr[l] = temp;
    }
    return 1;
}void checkPermutations(int arr[], int size, FILE *file2) {
    do {
        rewind(file2);
        for (int x = 0; x < 44; x++) {
            int a, b, c;
            fscanf(file2, "%d,%d,%d", &a, &b, &c);

            // Extract digits for comparison
            int digit1AC = arr[0] / 10;          // First digit of 1ac
            int digit1DN = a / 10;              // First digit of 1dn

            int digit3DN = b % 10;              // Third digit of 7dn
            int digit2AC = (c / 10) % 10;       // Second digit of 13ac

            int digit2DN = (b / 10) % 10;       // Second digit of 7dn
            int digit3AC = c % 10;              // Third digit of 13ac

            // Updated condition
            if (digit1AC == digit1DN && (digit3DN == digit2AC || digit2DN == digit3AC)) {
                printf("1ac: %d 2ac: %d 4ac: %d  1dn: %d 7dn: %d 13ac: %d\n",
                       arr[0], arr[1], arr[2], a, b, c);
            }
        }
    } while (nextPermutation(arr, size));
}



int main() {
    FILE *file, *file2;
    file = fopen("C:\\Users\\james\\Downloads\\comp sci work\\eulerproject\\1ac2ac4ac", "r");
    file2 = fopen("C:\\Users\\james\\Downloads\\comp sci work\\eulerproject\\PP", "r");

    if (!file || !file2) {
        printf("Error opening files.\n");
        return 1;
    }

    int arr[3];
    while (fscanf(file, "%d,%d,%d", &arr[0], &arr[1], &arr[2]) != EOF) {
        checkPermutations(arr, 3, file2);
    }

    fclose(file);
    fclose(file2);
    return 0;
}
