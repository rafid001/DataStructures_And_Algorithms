/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
         if (root == nullptr) {
            return std::vector<int>();
        }

        std::queue<TreeNode*> q;
        q.push(root);

        std::vector<int> ans;

        while (!q.empty()) {
            int n = q.size();
            int maxe = std::numeric_limits<int>::min();

            // Process each node at the current level.
            for (int i = 0; i < n; i++) {
                TreeNode* f = q.front();
                q.pop();

                // Check if left child is not nullptr.
                if (f->left) {
                    q.push(f->left);
                }

                // Check if right child is not nullptr.
                if (f->right) {
                    q.push(f->right);
                }

                maxe = std::max(maxe, f->val);
            }

            ans.push_back(maxe);
        }
        return ans;
    }
};