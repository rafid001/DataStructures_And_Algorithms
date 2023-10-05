class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> result;
        unordered_map<int,int> m;

        for(int i : nums) {
            m[i]++;
        }

        int n = nums.size();
        for(auto it = m.begin(); it != m.end(); it++) {
            if(it -> second > n/3)
                result.push_back(it->first);
        }

        return result;

    }
};