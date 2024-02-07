#include<climits>
// int solve(int ind, int wt, vector<int> &profit, vector<int> &weight) {

//     if(ind == 0) {
//         if(wt == 0) return 0;
//         if(weight[0] > wt) return 0;
//         else {
//             return ((int)(wt/weight[0]))*profit[0];
//         }
//     }

//     int notTake = solve(ind-1, wt, profit, weight);
//     int take = INT_MIN;
//     if(weight[ind] <= wt) {
//         take = profit[ind] + solve(ind, wt-weight[ind], profit, weight);
//     }

//     return max(take,notTake);
// }

int solve(int ind, int wt, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
    if (ind == 0) {
        if (wt == 0) return 0;
        if (weight[0] > wt) return 0;
        else {
            return (wt / weight[0]) * profit[0];
        }
    }

    if(dp[ind][wt] != -1) return dp[ind][wt];

    // if(ind == 0) 
    //     return ((int)(wt/weight[0])*profit[0]);

    int notTake = solve(ind - 1, wt, profit, weight, dp);
    int take = 0;

    if (weight[ind] <= wt) {
        take = profit[ind] + solve(ind, wt - weight[ind], profit, weight, dp);
    }

    return dp[ind][wt] = max(take, notTake);
}


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1,-1));
    return solve(n-1,w,profit,weight, dp);
}