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
private:
    bool check(TreeNode* root, long long min, long long max){

        if(root == NULL){
            return true;
        }

        if(root->val > min && root->val < max){
            bool left = check(root->left, min, root->val);
            bool right = check(root->right, root->val, max);
            return left && right;
        }
        else{
            return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) {

        if(root->left == NULL && root->right == NULL){
            return true;
        }
    
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};