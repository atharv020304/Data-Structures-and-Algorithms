class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l = 0 , r = 0;
        int ans = INT_MAX;;
        for(r = 0 ; r < nums.size() ;r++)
        {
            if(r-l+1 == k)
            {   
                ans = min(ans,nums[r] - nums[l]);
                l++;
            }
        }
        return ans;
    }
};