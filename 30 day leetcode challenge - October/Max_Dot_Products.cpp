class Solution {
public:
    int dp[501][501][2];
    int solve(int i, int j, vector<int>& v1, vector<int>& v2, int l) {

        if(i==v1.size() || j==v2.size()) {
            if(l==1) return 0;
            else return -1;
        }

        if(dp[i][j][l] != INT_MIN) return dp[i][j][l];

        int op1 = v1[i] * v2[j] + solve(i+1,j+1,v1,v2,1);
        int op2 = solve(i+1,j,v1,v2,l);
        int op3 = solve(i,j+1,v1,v2,l);

        return dp[i][j][l] = max(op1, max(op2,op3));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                dp[i][j][0] = INT_MIN;
                dp[i][j][1] = INT_MIN;
            }
        }

        int ans = solve(0, 0, nums1, nums2, 0);

        if(ans == -1) {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            return max(nums1.front()*nums2.back(), nums2.front()*nums1.back());
        }
        else {
            return ans;
        }
    }
};