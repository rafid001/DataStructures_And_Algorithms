class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {
        if (i == 0 && j == 0)
            return grid[i][j];

        if (i < 0 || j < 0)
            return INT_MAX; // Return a large value for out-of-bounds cases

        if(dp[i][j] != -1)
            return dp[i][j];

        int left = solve(grid, i, j - 1, dp);  // Move left
        int up = solve(grid, i - 1, j, dp);    // Move up

        return dp[i][j] = grid[i][j] + min(left, up);
    }

    int solveTab(vector<vector<int>>& grid, int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                if(i==0 && j==0) {
                    dp[i][j] = grid[i][j];
                }

                else {
                int left = grid[i][j];
                int up = grid[i][j];

                if(j > 0)
                    left += dp[i][j-1];
                else
                    left += 1e9;

                if(i > 0)
                    up += dp[i-1][j];
                else
                    up += 1e9;

                dp[i][j] = min(left,up);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //vector<vector<int>> dp(m, vector<int>(n, -1));
        //return solve(grid, m-1, n-1, dp);

        return solveTab(grid,m,n);
    }
};