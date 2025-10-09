class Solution {
public:
    long long minTime(vector<int>& s, vector<int>& m) {
        int n = s.size(), p = m.size();
        vector<long long> d(n + 1, 0);
        for (int j = 0; j < p; j++) {
            for (int i = 0; i < n; i++)
                d[i + 1] = max(d[i + 1], d[i]) + 1LL * m[j] * s[i];
            for (int i = n - 1; i > 0; i--)
                d[i] = d[i + 1] - 1LL * m[j] * s[i];
        }
        return d[n];
    }
};
