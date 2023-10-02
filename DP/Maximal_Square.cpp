#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int solve(vector<vector<int>> matrix, int i, int j, int &maxi) {

        if(i >= matrix.size() || j >= matrix[0].size()) {cout << "base reached "; return 0;}
        
        
        int right = solve(matrix, i, j+1, maxi);
        cout << "right here " << i << " " << j << " "<< right << endl;
        int diagonal = solve(matrix, i+1, j+1, maxi);
        cout << "diagonal here " << i<< " " << j << " " << diagonal << endl;
        int down = solve(matrix, i+1, j, maxi);
        cout << "down here "<< i << " " << j << " " << down << endl;

        cout << "I am i and j " << i << " " << j << ". " << "i am right, diag and down " << right << " " << diagonal << " " << down << endl;
        if(matrix[i][j] == 1) {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else {
            cout << "reached else" << endl;
            return 0;
        }
}

int main() {
    
    vector<vector<int>> matrix = {
        {{0,1},{1,0}}
    };

    

    int maxi = 0;

    solve(matrix, 0, 0, maxi);
    cout << endl;
    cout << endl;
    cout << maxi*maxi;
    return 0;

}