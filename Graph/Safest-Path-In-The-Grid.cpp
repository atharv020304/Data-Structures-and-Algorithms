class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // safeness[i][j] = distance from nearest thief
        vector<vector<int>> safeness(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int, int>> bfsQueue;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    safeness[row][col] = 0;
                    visited[row][col] = true;
                    bfsQueue.push({row, col});
                }
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // Multi-source BFS
        while (!bfsQueue.empty()) {
            auto [row, col] = bfsQueue.front();
            bfsQueue.pop();

            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + dx[dir];
                int newCol = col + dy[dir];

                if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= n)
                    continue;

                if (visited[newRow][newCol])
                    continue;

                visited[newRow][newCol] = true;
                safeness[newRow][newCol] = safeness[row][col] + 1;
                bfsQueue.push({newRow, newCol});
            }
        }

        // bestSafeness[i][j] = maximum minimum safeness possible to reach (i,j)
        vector<vector<int>> bestSafeness(n, vector<int>(n, -1));

        priority_queue<pair<int, pair<int, int>>> pq;

        bestSafeness[0][0] = safeness[0][0];
        pq.push({bestSafeness[0][0], {0, 0}});

        while (!pq.empty()) {
            auto [currentSafeness, cell] = pq.top();
            pq.pop();

            auto [row, col] = cell;

            if (currentSafeness < bestSafeness[row][col])
                continue;

            if (row == n - 1 && col == n - 1)
                return currentSafeness;

            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + dx[dir];
                int newCol = col + dy[dir];

                if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= n)
                    continue;

                int pathSafeness = min(currentSafeness, safeness[newRow][newCol]);

                if (pathSafeness > bestSafeness[newRow][newCol]) {
                    bestSafeness[newRow][newCol] = pathSafeness;
                    pq.push({pathSafeness, {newRow, newCol}});
                }
            }
        }

        return 0;
    }
};