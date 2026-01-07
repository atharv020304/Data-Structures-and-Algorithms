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
    long long M = 1e9 + 7;
    long long A = 0;

    long long f(TreeNode* n) {
        if (!n) return 0;

        n->val += f(n->left) + f(n->right);
        return n->val;
    }

    int maxProduct(TreeNode* r) {
        long long T = f(r);

        queue<TreeNode*> q;
        q.push(r);

        while (!q.empty()) {
            TreeNode* x = q.front();
            q.pop();

            if (!x) continue;

            long long P = (T - x->val) * x->val;
            A = max(A, P);

            if (x->left)  q.push(x->left);
            if (x->right) q.push(x->right);
        }

        return A % M;
    }
};
