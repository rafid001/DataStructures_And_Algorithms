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
    TreeNode* prev=NULL, *first=NULL,*second=NULL;
    void utility (TreeNode* root)
    {
        if(root==NULL) return;

        utility(root->left);
        if(prev!=NULL && root->val<prev->val)
        {
            if(first==NULL)
            {
                first=prev;
            }
            second=root;
        }
        prev=root;
        utility(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        utility(root);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }
};
