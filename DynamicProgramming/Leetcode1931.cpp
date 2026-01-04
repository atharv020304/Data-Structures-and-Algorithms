class Solution {
public:
    int M = 1e9 + 7;

    vector<string> states;

    void gen(int m, int idx, string &curr) {
        if(idx == m) {
            states.push_back(curr);
            return;
        }
        for(char c : {'R','G','B'}) {
            if(idx > 0 && curr[idx - 1] == c) continue;
            curr.push_back(c);
            gen(m, idx + 1, curr);
            curr.pop_back();
        }
    }

    int colorTheGrid(int m, int n) {
        string curr = "";
        gen(m, 0, curr);

        int S = states.size();
        vector<vector<int>> dp(n, vector<int>(S, 0));

        for(int i = 0; i < S; i++) {
            dp[0][i] = 1;
        }

        for(int col = 1; col < n; col++) {
            for(int i = 0; i < S; i++) {
                for(int j = 0; j < S; j++) {
                    bool conflict = false;
                    for(int k = 0; k < m; k++) {
                        if(states[i][k] == states[j][k]) {
                            conflict = true;
                            break;
                        }
                    }
                    if(!conflict) {
                        dp[col][i] = (dp[col][i] + dp[col - 1][j]) % M;
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < S; i++) {
            ans = (ans + dp[n - 1][i]) % M;
        }

        return ans;
    }
};
