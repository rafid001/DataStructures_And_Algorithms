#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(int index, int nums[], int amt) {

    if(index == 0) {
        if(amt % nums[0] == 0) return amt/nums[0];
        else return 1e9;
    }

    int notTake = solveUsingRecursion(index-1, nums, amt);
    int take = 1e9;
    if(nums[index] <= amt)
        take = 1+solveUsingRecursion(index, nums, amt-nums[index]);
    
    return min(take,notTake);
}

int solveUsingMemoization(int index, int nums[], int amt, vector<vector<int>>& dp) {

    if(index == 0) {
        if(amt % nums[0] == 0) return amt/nums[0];
        else return 1e9;
    }

    if(dp[index][amt] != 0) return dp[index][amt];

    int notTake = solveUsingRecursion(index-1, nums, amt);
    int take = 1e9;
    if(nums[index] <= amt)
        take = 1+solveUsingRecursion(index, nums, amt-nums[index]);
    
    return dp[index][amt] = min(take,notTake);
}

int solveUsingTabulation(int index, int nums[], int amt) {
    
    vector<vector<int>> dp(index, vector<int>(amt+1,0));

    for(int i=0; i<n; i++) {
        if(i % nums[0] == 0) dp[][i] = i/nums[0];
        else dp[0][i] = 1e9;
    }

    for(int ind=1; ind<index; ind++) {
        for(int amount=0; amount<amt; amount++) {
            int notTake = dp[ind-1][amount];
            int take = 1e9;
            if(nums[ind] <= amount)
                take = dp[ind][amount-nums[ind]];
            dp[ind][amount] = min(take,notTake);
        }
    }

    int ans = dp[index-1][amt];
    if(ans >= 1e9) return -1;
    else return ans;
}
int main() {

    int n;
    cin >> n;

    cout << "now enter array elements" << endl;

    int coins[n];

    for(int i=0; i<n; i++) {
        cin >> coins[i];
        cout << "again" << endl;
    }

    int amount;
    cin >> amount;

    int ans = solveUsingRecursion(n, coins, amount);

    if(ans >= 1e9) cout << -1;
    else cout << ans;

    return 0;
}
