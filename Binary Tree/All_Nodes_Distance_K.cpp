#include<unordered_map>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void parentMapping(unordered_map<TreeNode*,TreeNode*> &m, TreeNode* root){

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp -> left){
                m[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp -> right){
                m[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*> m;
        parentMapping(m, root);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        
        while(!q.empty()){

            int size = q.size();
            if(curr_level++ == k) break;
            
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();

                if((curr -> left) && (!visited[curr -> left])){
                    q.push(curr -> left);
                    visited[curr -> left] = true;
                }

                if((curr -> right) && (!visited[curr -> right])){
                    q.push(curr -> right);
                    visited[curr -> right] = true;
                }

                if(m[curr] && !visited[m[curr]]){
                    q.push(m[curr]);
                    visited[m[curr]] = true;
                }
            }
        }
        vector<int> result;

        while(!q.empty()){
            result.push_back(q.front() -> val);
            q.pop();
        }
        
        return result;
    }
};