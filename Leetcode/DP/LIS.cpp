#include<iostream>
#include<vector>
using namespace std;

int f(int ind, int prev, vector<int>& arr, int n) {
    if(ind == n) return 0;

    int notTake = 0+f(ind+1,prev,arr,n);
    int take = 0;
    if(prev == -1 || arr[ind] > arr[prev]) {
        take = 1+f(ind+1,ind,arr,n);
    }
    return max(take,notTake);
}

int LIS(vector<int>& arr, int n) {
    return f(0,-1,arr,n);
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int ans = LIS(arr,n);
    cout << ans << endl;
}