class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>> t;

    string states[12] = {
        "RYG","RGY","RYR","RGR",
        "YRG","YGR","YGY","YRY",
        "GRY","GYR","GRG","GYG"
    };

    int solve(int n, int prev)
    {
        if(n == 0){
            return 1;
        }

        if(t[n][prev] != -1){
            return t[n][prev];
        }

        int res = 0;
        string last = states[prev];

        for(int c = 0; c < 12; c++){
            if(c == prev){
                continue;
            }

            string currSeq = states[c];
            bool conflict = false;

            for(int col = 0; col < 3; col++){
                if(currSeq[col] == last[col]){
                    conflict = true;
                    break;
                }
            }

            if(!conflict){
                res = (res + solve(n - 1, c)) % M;
            }
        }

        return t[n][prev] = res;
    }

    int numOfWays(int n) {
        t.resize(n, vector<int>(12, -1));

        int ans = 0;
        for(int i = 0; i < 12; i++){
            ans = (ans + solve(n - 1, i)) % M;
        }

        return ans;
    }
};
