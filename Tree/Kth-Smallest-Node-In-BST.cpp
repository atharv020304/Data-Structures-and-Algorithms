class Solution {
    int count = 0;

public:
    int inorder(TreeNode* root, int k) {
        if (root == nullptr)
            return -1;

        int left = inorder(root->left, k);
        if (left != -1)
            return left;

        count++;
        if (count == k)
            return root->val;

        return inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};
