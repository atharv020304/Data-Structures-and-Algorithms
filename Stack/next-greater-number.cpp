class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> monoStack;
        unordered_map<int, int> nxtGreaterMp;

        for (auto it = nums2.rbegin(); it != nums2.rend(); ++it)
        {
            int ele = *it;
            while (!monoStack.empty() && monoStack.top() < ele)
                monoStack.pop();

            nxtGreaterMp[ele] = monoStack.empty() ? -1 : monoStack.top();
            monoStack.push(ele);
        }

        vector<int> ans;
        for (int ele : nums1)
            ans.push_back(nxtGreaterMp[ele]);

        return ans;
    }
};
