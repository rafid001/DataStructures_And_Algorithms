class Solution {
public:
    int findTarget(int ind, vector<int>& nums, int tar, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (tar == 0 && nums[ind] == 0) return 2;
            if (tar == 0 || tar == nums[ind]) return 1;
            return 0;
        }

        if (dp[ind][tar] != -1) return dp[ind][tar];

        int notTake = findTarget(ind - 1, nums, tar, dp);
        int take = 0;
        if (nums[ind] <= tar) {
            take = findTarget(ind - 1, nums, tar - nums[ind], dp);
        }

        return dp[ind][tar] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum = 0;
        for (auto &i : nums) {
            totSum += i;
        }

        int ntarget = totSum - target;
        //if (target < 0 || target % 2 != 0) return 0;
        if(ntarget < 0) return 0;
        if(ntarget%2 != 0) return 0;

        vector<vector<int>> dp(nums.size(), vector<int>(ntarget + 1, -1));

        return findTarget(nums.size() - 1, nums, ntarget, dp);
    }
};
