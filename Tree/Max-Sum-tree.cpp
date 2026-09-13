class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr;

        auto maxIt = std::max_element(nums.begin() + left, nums.begin() + right + 1);
        int maxIndex = maxIt - nums.begin();

        TreeNode* root = new TreeNode(*maxIt);
        root->left  = helper(nums, left, maxIndex - 1);
        root->right = helper(nums, maxIndex + 1, right);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, (int)nums.size() - 1);
    }
};
