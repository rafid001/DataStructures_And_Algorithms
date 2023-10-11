class Solution {
public:
    int minOperations(vector<int>& nums) {

        int ans = INT_MAX;
        int n = nums.size();
        
        set<int> st(begin(nums), end(nums));

        vector<int> temp(begin(st), end(st));

        for(int i=0; i<temp.size(); i++) {

            int L = temp[i];
            int R = L + n - 1;

            int j = upper_bound(begin(temp), end(temp), R) - begin(temp);

            int within_range = j-i;

            int out_of_range = n - within_range;

            ans = min(ans, out_of_range);
        }
        
        return ans;
    }
};