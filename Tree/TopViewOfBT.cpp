/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
// same logic as bottom view, just insted of overriding the hd in map everytime, we need to put only once for each node 
class Solution{
    public:
    vector<int> topView(TreeNode *root){
        vector<int> ans;
        if(root == nullptr) return ans;

        map<int,int> mp;
        queue<pair<TreeNode*, int>> q;

        q.push({root,0});

        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();

            TreeNode* curr = temp.first;
            int hd = temp.second;

            if(mp.find(hd) == mp.end()){
                mp[hd] = curr->data;
            }

            if(curr->left)
            {
                q.push({curr->left, hd - 1});
            }

            if(curr->right)
            {
                q.push({curr->right, hd + 1});
            }
        }
        for(auto it : mp)
        {
            ans.push_back(it.second);
        }
    return ans;
    }
};
