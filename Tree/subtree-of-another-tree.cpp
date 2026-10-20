class Solution {
public:
    bool flag = false;

    bool isSameTree(TreeNode* curr, TreeNode* subRoot)
    {
        if(curr == NULL && subRoot == NULL)
        {
            return true;
        }
        if(curr == NULL || subRoot == NULL)
        {
            return false;
        }

        if(curr -> val != subRoot->val )
        {
            return false;
        }

        return isSameTree(curr->left,subRoot->left) && isSameTree(curr->right, subRoot->right);
    }

    void iter(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL || subRoot == nullptr)
        {
            return;
        }
        if(root->val == subRoot->val)
        {
            if (isSameTree(root, subRoot)) {
                flag = true;
            }
        }
        if(root->left) {
            iter(root->left, subRoot);
        }
        if(root->right)
        {
            iter(root->right, subRoot);
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        flag = false;        
        iter(root, subRoot); 
        return flag;
    }
};
