class Solution {
public:
    
    int find_max(vector<int> nums)
    {   
        int maxi = nums[0];

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > maxi)
            {
                maxi = nums[i];
            }
        }
        return maxi;
    }

    bool maxcount(vector<int>& nums, int maxi)
    {
        int count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == maxi)
            {
                count++;
            }
        }

        if(count == 2)
        {
            return true;
        }

        return false;
    }

    bool helper(vector<int>& nums, int maxi)
    {   
        sort(nums.begin(), nums.end());

        for(int i = 0; i < maxi - 1; i++)
        {
            if(nums[i] != i + 1)
            {
                return false;
            }
        }

        return true;
    }

    bool isGood(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int maxi = find_max(nums);

        if(helper(nums, maxi) && maxcount(nums, maxi))
        {
            return true;
        }

        return false;
    }
};
