#include <stdio.h>


int max_path();
int max(int x, int y);
int triangle[15][15] = {
    {75},
    {95, 64},
    {17, 47, 82},
    {18, 35, 87, 10},
    {20, 4, 82, 47, 65},
    {19, 1, 23, 75, 3, 34},
    {88, 2, 77, 73, 7, 63, 67},
    {99, 65, 4, 28, 6, 16, 70, 92},
    {41, 41, 26, 56, 83, 40, 80, 70, 33},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
    {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
    {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
};

int main(void) {
    // Define the triangle as a centered 15x15 square with zeros padding the sides

  
    int result = max_path();
    printf("%d",result);
    return 0;
}

int  max_path() {

    int n=15;

    int dp[n][n];

    for (int i = 0; i < n; i++) {
        dp[n - 1][i] = triangle[n - 1][i];
    }

    for(int i = n-2;i>= 0;i--) {
        for(int j =0;j< 14;j++) {
            dp[i][j] = triangle[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
        }
    }

    return dp[0][0];

}

int max(int x,int y) {

    if(x>y) {
        return x;
    }
    else {
        return y;
    }
}