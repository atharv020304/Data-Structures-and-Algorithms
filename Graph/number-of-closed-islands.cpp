class Solution {
public:
    int ans = 0;

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dirX = {0,0,-1,1};
        vector<int> dirY = {-1,1,0,0};

        bool closed = true;

        stack<pair<int,int>> q;
        visited[i][j] = true;
        q.push({i,j});

        while(!q.empty())
        {
            auto temp = q.top();
            q.pop();

            if(temp.first == 0 || temp.first == n-1 || temp.second == 0 || temp.second == m-1)
            {
                closed = false;
            }

            for(int t = 0 ; t < 4; t++)
            {
                int newX = temp.first + dirX[t];
                int newY = temp.second + dirY[t];

                if(newX < 0 || newX >= n || newY < 0 || newY >= m)
                {
                    continue;
                }

                if(grid[newX][newY] == 0 && visited[newX][newY] == false)
                {
                    visited[newX][newY] = true;
                    q.push({newX,newY});
                }
            }
        }

        if(closed)
        {
            ans++;
        }
    }

    int closedIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        ans = 0;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 0 && visited[i][j] == false)
                {
                    dfs(grid, visited, i, j);
                }
            }
        }

        return ans;
    }
};
