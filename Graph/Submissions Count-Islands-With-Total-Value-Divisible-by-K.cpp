class Solution {
public:
    int count = 0;

    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int k)
    {   
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dirX = { 0,0,1,-1};
        vector<int> dirY = { 1,-1,0,0};

        queue<pair<int,int>> q;
        long long sum = 0;

        visited[i][j] = true;
        q.push({i,j});
        sum += grid[i][j];

        while(!q.empty()){

            auto temp = q.front();
            q.pop();

            for(int t = 0;  t < 4; t++)
            {
                int newX = temp.first + dirX[t];
                int newY = temp.second + dirY[t];

                if( newX >= 0 && newX < m && newY >= 0 && newY < n )
                {
                    if(!visited[newX][newY] && grid[newX][newY] > 0)
                    {
                        visited[newX][newY] = true;
                        q.push({newX,newY});
                        sum += grid[newX][newY];
                    }
                }
            }
        }

        if(sum % k == 0)
        {
            count++;
        }

    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0 ; i < m ;i++)
        {
            for(int j=0; j < n; j++)
            {
                if(!visited[i][j] && grid[i][j] > 0)
                {
                    bfs(grid,visited,i,j,k);
                }
            }
        }
        return count;
    }
};
