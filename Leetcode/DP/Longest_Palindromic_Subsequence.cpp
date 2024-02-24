class Solution {
public:
    int lcs(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        for(int i=1; i<=len1; i++) {
            for(int j=1; j<=len2; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
//     int lcs(string s1, string s2) {
//     int n = s1.size();
//     int m = s2.size();

//     // Create a 2D DP array to store the length of the LCS
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//     // Initialize the first row and first column to 0
//     // for (int i = 0; i <= n; i++) {
//     //     dp[i][0] = 0;
//     // }
//     // for (int i = 0; i <= m; i++) {
//     //     dp[0][i] = 0;
//     // }

//     // Fill in the DP array
//     for (int ind1 = 1; ind1 <= n; ind1++) {
//         for (int ind2 = 1; ind2 <= m; ind2++) {
//             if (s1[ind1 - 1] == s2[ind2 - 1])
//                 dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
//             else
//                 dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
//         }
//     }

//     // The value at dp[n][m] contains the length of the LCS
//     return dp[n][m];
// }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s,t);
    }
};