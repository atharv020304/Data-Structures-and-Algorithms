class Solution {
public:
    vector<string> removeAnagrams(vector<string>& arr) {
        int n = arr.size();
        vector<unordered_map<char, int>> freqMap(n);
        for (int i = 0; i < n; i++) {
            for (char c : arr[i]) freqMap[i][c]++;
        }
        vector<string> res;
        res.push_back(arr[0]);
        for (int i = 1; i < n; i++) {
            if (freqMap[i] != freqMap[i - 1]) res.push_back(arr[i]);
        }
        return res;
    }
};
