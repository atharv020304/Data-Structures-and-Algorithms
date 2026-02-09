class Solution {
public:
    vector<TreeNode*> arr;
    void traversal(TreeNode* root)
    {
        if(!root){
            return;
        }
        traversal(root->left);
        arr.push_back(root);
        traversal(root->right);
    }

    TreeNode* TreeBuilder(int start, int end)
    {   
        if(start>end){
            return NULL;
        }

        int mid = (start + end) / 2;

        TreeNode* root = arr[mid];
        root->left = TreeBuilder(start,mid-1);
        root->right = TreeBuilder(mid+1,end);

        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {

        traversal(root);

        return TreeBuilder(0,arr.size()-1);
        
    }
};