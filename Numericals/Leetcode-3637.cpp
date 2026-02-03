class Solution {
public:
    bool isTrionic(vector<int>& nums) {
    int n = nums.size();

    for (int p = 1; p < n - 1; p++) {
        for (int q = p + 1; q < n - 1; q++) {

            bool ok = true;

            for (int i = 0; i < p; i++) {
                if (nums[i] >= nums[i + 1]) {
                    ok = false;
                    break;
                }
            }

            for (int i = p; i < q; i++) {
                if (nums[i] <= nums[i + 1]) {
                    ok = false;
                    break;
                }
            }

            for (int i = q; i < n - 1; i++) {
                if (nums[i] >= nums[i + 1]) {
                    ok = false;
                    break;
                }
            }

            if (ok) return true;
        }
    }
    return false;
}

};