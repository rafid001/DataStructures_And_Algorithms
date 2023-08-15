#include<unordered_map>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;


 
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* solve(Node* root) {

        if (root == NULL)
            return NULL;

        if (root->left != NULL)
            root->left->next = root->right;

        if (root->right != NULL) {
            if (root->next != NULL)
                root->right->next = root->next->left;
            else
                root->right->next = NULL;
        }

        solve(root->left);
        solve(root->right);

        return root;
        
}

    Node* connect(Node* root) {
        
        if(root == NULL){
            return NULL;
        }

        root -> next = NULL;

        return solve(root);
    }
};