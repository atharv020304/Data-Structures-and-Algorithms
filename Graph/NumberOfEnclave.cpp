class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows,vector<int>(cols,0));

        queue<pair<int,int>> queue;

        for(int i = 0 ; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if( i==0 || j == 0 || i==rows-1 || j==cols-1)
                {
                    if(grid[i][j] == 1)
                    {
                        queue.push({i,j});
                        visited[i][j] = 1;
                    }
                }
            }
        }

        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

        while(!queue.empty())
        {
            pair<int, int> current = queue.front();
            queue.pop();
            int i = current.first;
            int j = current.second;

            for(int k = 0 ; k < 4 ;k++ )
            {
                int inew = i + dir[k][0];
                int jnew = j + dir[k][1];

                if( inew >=0 && jnew >=0 && inew < rows && jnew < cols && grid[inew][jnew] == 1 && visited[inew][jnew] == 0){
                    visited[inew][jnew] = 1;
                    queue.push({inew,jnew});
                }
            }
        }

        int count =0; 
        for(int x = 0 ; x < rows; x++)
        {
            for(int y = 0; y < cols; y++)
            {
                if(grid[x][y] == 1 && visited[x][y] == 0)
                {
                        count++;
                }
            }
        }

        return count;
    }
};
