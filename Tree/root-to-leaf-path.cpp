class Solution {
public:
    vector<vector<int>> ans;

    void traversal(TreeNode* root, vector<int>& temp) {
        if (!root) return;
        temp.push_back(root->data);

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(temp);
        } else {
            if (root->left) traversal(root->left, temp);
            if (root->right) traversal(root->right, temp);
        }
        temp.pop_back();
    }

    vector<vector<int>> allRootToLeaf(TreeNode* root) {
        vector<int> temp;
        traversal(root, temp);
        return ans;
    }
};
