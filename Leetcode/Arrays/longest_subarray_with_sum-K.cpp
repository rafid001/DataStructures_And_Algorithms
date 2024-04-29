#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> nums, int k) {

    int sum = 0;
    int maxLen = INT_MIN;
    unordered_map<int,int> mapping;

    for(int i=0; i<nums.size(); i++) {
        sum += nums[i];
        if(sum == k) {
            maxLen = max(maxLen, i+1);
        }
        else if(sum > k) {
            int rem = sum - k;
            if(mapping.find(rem) != mapping.end()) {
                int len = i - mapping[rem];
                maxLen = max(maxLen,len);
            }
        }
        mapping[sum] = i;
    }

    return maxLen;

}