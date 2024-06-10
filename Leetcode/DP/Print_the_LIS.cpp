#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> solve(vector<int> &arr, int n)
{
    vector<int> dp(n, 1);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    vector<int> hash(n)
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = solve(arr, n);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}