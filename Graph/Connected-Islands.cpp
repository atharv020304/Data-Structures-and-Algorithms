class Solution {
public:

    int ans = 0;

    void bfs(int sx, int sy,
             vector<vector<char>>& grid,
             vector<vector<bool>>& visited)
    {
        vector<int> dirX = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dirY = {-1,  0,  1, -1, 1, -1, 0, 1};

        queue<pair<int, int>> q;

        visited[sx][sy] = true;
        q.push({sx, sy});

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                int newX = node.first + dirX[i];
                int newY = node.second + dirY[i];

                if (newX < 0 || newX >= grid.size() ||
                    newY < 0 || newY >= grid[0].size())
                {
                    continue;
                }

                if (!visited[newX][newY] &&
                    grid[newX][newY] == '1')
                {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }

        ans++;
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(
            n, vector<bool>(m, false)
        );

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    bfs(i, j, grid, visited);
                }
            }
        }

        return ans;
    }
};



//using dfs stack 

class Solution {
public: 

    int ans = 0;
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        vector<int> dirX = { 0,0,1,-1};
        vector<int> dirY = {1,-1,0,0 };

        int currX = i;
        int currY = j;

        stack<pair<int,int>> st;
        visited[currX][currY] = true;
        st.push({currX,currY});

        while(!st.empty())
        {
            auto temp = st.top();
            st.pop();

            for(int i = 0 ; i < 4 ; i++)
            {
                int newX = temp.first + dirX[i];
                int newY = temp.second + dirY[i];

                if(newX >=0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == '1' && !visited[newX][newY])
                {
                    visited[newX][newY] = true;
                    st.push({newX,newY});
                }
            }
        }
        ans ++;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0 ; i < m; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(grid,visited,i,j);
                }
            }
        }
        return ans;
    }
};
