#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int minAbs(int index, vector<int> a, vector<int> b, vector<int> &arr, int n) {
 
    if(index == n) {
        int sum_a = 0;
        for(int i:a) sum_a += i;
        int sum_b = 0;
        for(int i:b) sum_b += i;
        return abs(sum_a*sum_a - sum_b*sum_b); 
    }

    vector<int> new_a = a;
    new_a.push_back(arr[index]);
    int res1 = minAbs(index+1, new_a, b, arr, n);

    vector<int> new_b = b;
    new_b.push_back(arr[index]);
    int res2 = minAbs(index+1, a, new_b, arr, n);

    return min(res1,res2);

}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<int> arr;
        for(int i=0; i<N; i++) {
            int a;
            cin >> a;
            arr.push_back(a);
        }
        int ans = minAbs(0, {}, {}, arr, N);
        cout << ans << endl;
    }
    return 0;
}


    