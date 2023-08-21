#include<iostream>
#include<vector>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int solve(int wt[], int v[], int n, int capacity) {
        
        vector<vector<int>> dp(n, vector<int>(capacity+1,0));
        
        for(int w = wt[0]; w <= capacity; w++) {
            if(wt[0] <= capacity) dp[0][w] = v[0];
            else dp[0][w] = 0;
        }
        
        for(int i = 1; i < n; i++) {
            for(int w = 0; w <= capacity; w++) {
                int include = 0;
                if(wt[i] <= w)
                    include = v[i] + dp[i-1][w-wt[i]];
                
                int exclude = dp[i-1][w];
                
                dp[i][w] = max(exclude, include);
            }
        }
        
        return dp[n-1][capacity];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return solve(wt, val, n, W);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends