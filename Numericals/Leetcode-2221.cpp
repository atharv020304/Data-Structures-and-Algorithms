class Solution {
public:
    int recursion(vector<int> arr, int n) {
        if (n == 1) {
            return arr[0];
        }
        vector<int> temp;
        temp.reserve(n - 1);
        for (int i = 0; i < n - 1; i++) {
            temp.push_back((arr[i] + arr[i + 1]) % 10);
        }
        return recursion(temp, n - 1);
    }

    int triangularSum(vector<int>& nums) {
        return recursion(nums, nums.size());
    }
};
