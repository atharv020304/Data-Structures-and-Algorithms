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
    int best = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftLen  = dfs(node->left);
        int rightLen = dfs(node->right);

        int extendLeft = 0;
        int extendRight = 0;

        if (node->left && node->left->val == node->val)
            extendLeft = leftLen;

        if (node->right && node->right->val == node->val)
            extendRight = rightLen;

        best = std::max(best, extendLeft + extendRight + 1);

        return std::max(extendLeft, extendRight) + 1;
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return best > 0 ? best - 1 : 0;
    }
};
