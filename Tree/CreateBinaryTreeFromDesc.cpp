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
 //tle
// class Solution {
// public:

//     int findroot(unordered_map<int, pair<int,int>>& mp)
// {
//     unordered_set<int> children;

//     for(auto &ele : mp)
//         children.insert(ele.first);

//     for(auto &ele : mp)
//     {
//         int parent = ele.second.first;

//         if(children.count(parent) == 0)
//             return parent;
//     }

//     return -1;
// }

//     void ConstructTree(
//         unordered_map<int, pair<int,int>>& mp,
//         int parent,
//         TreeNode* root)
//     {
//         for(auto &ele : mp)
//         {
//             int child = ele.first;
//             int par = ele.second.first;
//             int isLeft = ele.second.second;

//             if(par == parent)
//             {
//                 if(isLeft)
//                 {
//                     root->left = new TreeNode(child);

//                     ConstructTree(
//                         mp,
//                         child,
//                         root->left
//                     );
//                 }
//                 else
//                 {
//                     root->right = new TreeNode(child);

//                     ConstructTree(
//                         mp,
//                         child,
//                         root->right
//                     );
//                 }
//             }
//         }
//     }

//     TreeNode* createBinaryTree(vector<vector<int>>& desc)
//     {
//         unordered_map<int, pair<int,int>> mp;

//         for(auto &ele : desc)
//         {
//             mp[ele[1]] = {ele[0], ele[2]};
//         }

//         int rt = findroot(mp);

//         TreeNode* root = new TreeNode(rt);

//         ConstructTree(mp, rt, root);

//         return root;
//     }
// };

//works as we build the tree while processing
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for(auto &d : descriptions)
        {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            if(!nodes.count(parent))
                nodes[parent] = new TreeNode(parent);

            if(!nodes.count(child))
                nodes[child] = new TreeNode(child);

            if(isLeft)
                nodes[parent]->left = nodes[child];
            else
                nodes[parent]->right = nodes[child];

            children.insert(child);
        }

        for(auto &d : descriptions)
        {
            if(!children.count(d[0]))
                return nodes[d[0]];
        }

        return nullptr;
    }
};