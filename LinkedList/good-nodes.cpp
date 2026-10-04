/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }
    
    int helper(TreeNode* root, int maxi) {
        if (root == nullptr) {
            return 0;
        }

        int count = 0;
        if (root->val >= maxi) {
            count = 1;
        }

        int new_maxi = std::max(maxi, root->val);

        count += helper(root->left, new_maxi);
        count += helper(root->right, new_maxi);

        return count;
    }
};
