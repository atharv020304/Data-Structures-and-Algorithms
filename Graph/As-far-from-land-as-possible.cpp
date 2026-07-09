class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    q.push({i, j});

        int ans = -1;   
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int t = 0; t < 4; t++) {
                int nRow = r + dr[t];
                int nCol = c + dc[t];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 0) {
                    grid[nRow][nCol] = grid[r][c] + 1;
                    ans = max(ans, grid[nRow][nCol] - 1);
                    q.push({nRow, nCol});
                }
            }
        }

        return ans;
    }
};
