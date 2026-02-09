class Solution {
public:
    typedef long long ll;
    int len;
    vector<vector<ll>> dp;

    ll dfs(int idx, int state, vector<int>& arr) {
        if (idx == len) {
            if (state == 3) {
                return 0;
            } else {
                return LLONG_MIN / 2;
            }
        }

        if (dp[idx][state] != LLONG_MIN) {
            return dp[idx][state];
        }

        ll pick = LLONG_MIN / 2;
        ll drop = LLONG_MIN / 2;

        if (state == 0) {
            drop = dfs(idx + 1, 0, arr);
        }

        if (state == 3) {
            pick = arr[idx];
        }

        if (idx + 1 < len) {
            int a = arr[idx];
            int b = arr[idx + 1];

            if (state == 0 && b > a) {
                pick = max(pick, a + dfs(idx + 1, 1, arr));
            } else if (state == 1) {
                if (b > a) {
                    pick = max(pick, a + dfs(idx + 1, 1, arr));
                } else if (b < a) {
                    pick = max(pick, a + dfs(idx + 1, 2, arr));
                }
            } else if (state == 2) {
                if (b < a) {
                    pick = max(pick, a + dfs(idx + 1, 2, arr));
                } else if (b > a) {
                    pick = max(pick, a + dfs(idx + 1, 3, arr));
                }
            } else if (state == 3 && b > a) {
                pick = max(pick, a + dfs(idx + 1, 3, arr));
            }
        }

        return dp[idx][state] = max(pick, drop);
    }

    ll maxSumTrionic(vector<int>& arr) {
        len = arr.size();
        dp.assign(len + 1, vector<ll>(4, LLONG_MIN));
        return dfs(0, 0, arr);
    }
};
