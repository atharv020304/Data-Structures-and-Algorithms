// class Solution {
// public:
//     vector<int> ans;

//     void helper(int num)
//     {   
//         vector<int> temp;
//         while(num){
//         int q = num % 10;
//         temp.push_back(q);
//         num = num / 10;
//         }
//         for(int i = temp.size()-1; i>=0 ;i--)
//         {
//             ans.push_back(temp[i]);
//         }
//     }

//     vector<int> separateDigits(vector<int>& nums) {
//         for(int i = 0 ; i < nums.size(); i++)
//         {
//             helper(nums[i]);
//         }

//         return ans;
//     }
// };


class Solution {
public:
    vector<int> ans;

    void helper(int num) {
        if (num >= 10)
            helper(num / 10);

        ans.push_back(num % 10);
    }

    vector<int> separateDigits(vector<int>& nums) {
        for (int num : nums) {
            helper(num);
        }

        return ans;
    }
};
