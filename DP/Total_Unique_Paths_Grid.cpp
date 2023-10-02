#include <iostream>
#include<vector>
using namespace std;

//RECURSIVE METHOD
int solve(int m, int n) {

    if(m == 0 && n == 0) return 1;
    if(m < 0 || n < 0) return 0;

    int up = solve(m-1, n);
    int left = solve(m, n-1);

    return up + left;

}

//RECURSION + MEMOIZATION
int solveMem(int m, int n, vector<vector<int>> &dp) {

    if(m == 0 && n == 0) return 1;
    if(m < 0 && n < 0) return 0;
    if(dp[m][n] != -1) return dp[m][n];

    int up = solveMem(m-1, n, dp);
    int left = solveMem(m, n-1, dp);

    return dp[m][n] = up + left;

}

//TABULATION METHOD
int countWays(int m, int n) {

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for(int i=0; i<m; i++) {

        for(int j=0; j<n; j++) {

            if(i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if(i > 0) up = dp[i-1][j];

            if(j > 0)  left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }
     return dp[m-1][n-1];
}

int main() {

    int m = 3;
    int n = 2;

    // Call the countWays function and print the result.
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;

    return 0;
}