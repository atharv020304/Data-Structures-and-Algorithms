class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans;
        
        reverse(temperatures.begin(), temperatures.end());

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(st.top() - i);
            }

            st.push(i);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
