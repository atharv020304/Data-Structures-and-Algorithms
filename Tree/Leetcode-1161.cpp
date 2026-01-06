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
    vector<int> ans;

    void levelOrder(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(sum);
        }
    }

    int findmaxidx(vector<int>& ans) {
        int idx = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] > maxi) {
                maxi = ans[i];
                idx = i;
            }
        }
        return idx + 1; 
    }

    int maxLevelSum(TreeNode* root) {
        ans.clear();
        levelOrder(root);
        return findmaxidx(ans);
    }
};
