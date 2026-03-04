class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rowT;
        vector<int> colT;

        for(int i = 0 ; i < mat.size(); i++) {   
            int cnt = 0;
            for(int j = 0 ; j < mat[0].size(); j++){
                if(mat[i][j] == 1) {
                    cnt++;
                }
            }
            rowT.push_back(cnt);
        }

        for(int i = 0 ; i < mat[0].size(); i++) {   
            int cnt = 0;
            for(int j = 0 ; j < mat.size(); j++){
                if(mat[j][i] == 1) {
                    cnt++;
                }
            }
            colT.push_back(cnt);
        }

        int ans = 0;

        for(int i = 0 ; i < mat.size(); i++) {   
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 1 && rowT[i] == 1 && colT[j] == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};