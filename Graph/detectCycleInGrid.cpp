class Solution {
public:

    bool bfs(int sx, int sy, vector<vector<char>>& grid,
             vector<vector<bool>>& visited)
    {
        vector<int> dirX = {0, 0, 1, -1};
        vector<int> dirY = {1, -1, 0, 0};

        queue<pair<pair<int, int>, pair<int, int>>> q;

        visited[sx][sy] = true;
        q.push({{sx, sy}, {-1, -1}});

        while (!q.empty())
        {
            auto [node, parent] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newX = node.first + dirX[i];
                int newY = node.second + dirY[i];

                if (newX < 0 || newX >= grid.size() ||
                    newY < 0 || newY >= grid[0].size())
                {
                    continue;
                }

                if (grid[newX][newY] != grid[node.first][node.second])
                {
                    continue;
                }

                if (!visited[newX][newY])
                {
                    visited[newX][newY] = true;

                    q.push({
                        {newX, newY},
                        {node.first, node.second}
                    });
                }
                else if (newX != parent.first || newY != parent.second)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j])
                {
                    if (bfs(i, j, grid, visited))
                        return true;
                }
            }
        }

        return false;
    }
};
