class Solution {
public:
    void fillset(unordered_set<int>& st, int element) {
        while (element) {
            st.insert(element);
            element = element / 10;
        }
    }  
    int iterateSet(unordered_set<int>& st, int ele) {
        int maxi = 0;
        while (ele) {
            if (st.find(ele) != st.end()) {
                int digits = 0;
                 int temp = ele;
                while (temp) {
                    digits++;
                    temp /= 10;
                }
                maxi = max(maxi, digits);
                break;  
            }
            ele = ele / 10;
        }
        return maxi;
    }
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        
        for (int num : arr1) {
            fillset(st, num);
        }
        
        int ans = 0;
        for (int num : arr2) {
            ans = max(ans, iterateSet(st, num));
        }
        
        return ans;
    }
};
