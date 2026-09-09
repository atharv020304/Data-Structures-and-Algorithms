// multisource bfs
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        // Multi-source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                // Out of bounds
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Only process empty rooms
                if (rooms[nr][nc] != INT_MAX)
                    continue;

                // Distance = current distance + 1
                rooms[nr][nc] = rooms[r][c] + 1;

                q.push({nr, nc});
            }
        }
    }
};
