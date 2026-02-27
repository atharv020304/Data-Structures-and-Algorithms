// class Solution {
// public:
//     vector<int> helper(int curr,int prev, vector<int>& nums)
//     {   
        
//         if(curr == nums.size())
//         {
//             return {};
//         }

//         vector<int> nt = helper(curr+1,prev,nums);

//         vector<int> t;
//         if(prev == -1 || nums[curr] % nums[prev] == 0)
//         {
//             t = helper(curr+1,curr,nums);
//             t.push_back(nums[curr]);
//         }

//         return nt.size() > t.size() ? nt : t; 
//     }
//     vector<int> largestDivisibleSubset(vector<int>& nums) { 
//         sort(nums.begin(),nums.end());
//         return helper(0,-1,nums);
//     }
// };
//memo 

class Solution {
public:
    vector<int> helper(int curr,int prev, vector<int>& nums,
                       vector<vector<vector<int>>>& dp,
                       vector<vector<int>>& vis)
    {   
        if(curr == nums.size())
        {
            return {};
        }

        if(vis[curr][prev+1])
        {
            return dp[curr][prev+1];
        }

        vector<int> nt = helper(curr+1,prev,nums,dp,vis);

        vector<int> t;
        if(prev == -1 || nums[curr] % nums[prev] == 0)
        {
            t = helper(curr+1,curr,nums,dp,vis);
            t.push_back(nums[curr]);
        }

        vis[curr][prev+1] = 1;
        dp[curr][prev+1] = nt.size() > t.size() ? nt : t;

        return dp[curr][prev+1]; 
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) { 
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1));
        vector<vector<int>> vis(n, vector<int>(n+1,0));

        return helper(0,-1,nums,dp,vis);
    }
};