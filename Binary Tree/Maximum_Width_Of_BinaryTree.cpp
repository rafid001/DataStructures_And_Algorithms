#include<unordered_map>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;


  
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL) return 0;
        
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        unsigned long long ans = 0;

        while(!q.empty()) {
            unsigned long long n = q.size();
            unsigned long long start = q.front().second;
            unsigned long long end = q.back().second;
            ans = max(ans, end-start+1);

            for(int i=0; i<n; i++) {
                pair<TreeNode*,unsigned long long> p = q.front();
                TreeNode* curr = p.first;
                unsigned long long index = p.second;
                q.pop();

                if(curr -> left)
                    q.push({curr -> left, 2*index+1});
                if(curr -> right)
                    q.push({curr -> right, 2*index+2});
            }
        }
        return ans;
    }
};