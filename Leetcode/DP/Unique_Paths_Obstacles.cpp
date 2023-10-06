class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {

        if (i < 0 || j < 0 || grid[i][j] == 1)
            return 0;

        if(i == 0 && j == 0)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int left = solve(grid, i, j-1, dp);
        int up = solve(grid, i-1, j, dp);

        return dp[i][j] = up + left;
    }

    int solveTab(vector<vector<int>>& grid, int m, int n) {

        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) {
        return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {

            for(int j=0; j<n; j++) {

                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                if(grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                int left = 0;
                int up = 0;

                if(j > 0)
                left = dp[i][j-1];
                if(i > 0)
                up = dp[i-1][j];

                dp[i][j] = left + up;
            }
        }
        return dp[m-1][n-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        /*vector<vector<int>> dp(m, vector<int>(n,-1));

        return solve(obstacleGrid, m-1, n-1, dp);*/

        return solveTab(obstacleGrid, m, n);
    }
};