class Solution {
public:
    int solve(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp) {
        if(ind1 == 0 || ind2 == 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(s1[ind1-1] == s2[ind2-1]) return 1+solve(ind1-1, ind2-1, s1, s2, dp);
        return dp[ind1][ind2] = max(solve(ind1-1, ind2, s1, s2, dp), solve(ind1, ind2-1, s1, s2, dp));
    }

    int solveTab(int ind1, int ind2, string s1, string s2) {
        vector<vector<int>> dp(ind1+1, vector<int>(ind2+1,0));
        for(int i=1; i<=ind1; i++) {
            for(int j=1; j<=ind2; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[ind1][ind2];
    }

    int solveOpt(int n, int m, string s1, string s2) {
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    curr[j] = 1+prev[j-1];
                }
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        //vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1,-1));
        //return solve(text1.size(), text2.size(), text1, text2, dp);
        return solveTab(text1.size(),text2.size(),text1,text2);
    }
};