// class Solution {
// public:
//     vector<vector<int>> dp;

//     int asciiSum(string &s, int i) {
//         int sum = 0;
//         for (int k = i; k < s.size(); k++) sum += s[k];
//         return sum;
//     }

//     int solve(string &s1, string &s2, int i, int j) {
//         if (i == s1.size()) return asciiSum(s2, j);
//         if (j == s2.size()) return asciiSum(s1, i);

//         if (dp[i][j] != -1) return dp[i][j];

//         if (s1[i] == s2[j])
//             return dp[i][j] = solve(s1, s2, i + 1, j + 1);

//         return dp[i][j] = min(
//             s1[i] + solve(s1, s2, i + 1, j),
//             s2[j] + solve(s1, s2, i, j + 1)
//         );
//     }

//     int minimumDeleteSum(string s1, string s2) {
//         dp.assign(s1.size(), vector<int>(s2.size(), -1));
//         return solve(s1, s2, 0, 0);
//     }
// };


class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
            dp[i][m] = dp[i + 1][m] + s1[i];

        for (int j = m - 1; j >= 0; j--)
            dp[n][j] = dp[n][j + 1] + s2[j];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = min(
                        s1[i] + dp[i + 1][j],
                        s2[j] + dp[i][j + 1]
                    );
                }
            }
        }

        return dp[0][0];
    }
};
