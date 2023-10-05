#include<vector>
using namespace std;
class Solution {
public:
    int solve(vector<int> &nums, int n, int i, vector<int> &dp){

        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int ans = max(nums[i] + solve(nums, n, i+2, dp), solve(nums, n, i+1,dp));
        dp[i] = ans;

        return ans;
    }  

    int rob(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> dp(n+1, -1);
        int ans = solve(nums, n, i, dp);
        return ans;
    }
};