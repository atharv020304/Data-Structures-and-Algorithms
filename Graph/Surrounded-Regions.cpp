class Solution {
public:
    bool inBounds(vector<vector<char>>& board, int i, int j)
    {
        return i >= 0 && i < (int)board.size() && j >= 0 && j < (int)board[0].size();
    }

    void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j)
    {
        vector<int> dirX = {0,0,1,-1};
        vector<int> dirY = {1,-1,0,0};
        queue<pair<int,int>> q;

        visited[i][j] = true;
        q.push({i,j});

        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int newX = temp.first + dirX[k];
                int newY = temp.second + dirY[k];

                if(inBounds(board, newX, newY) && !visited[newX][newY] && board[newX][newY] == 'O')
                {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++)
        {
            if(!visited[i][0] && board[i][0] == 'O') bfs(board, visited, i, 0);
            if(!visited[i][n-1] && board[i][n-1] == 'O') bfs(board, visited, i, n-1);
        }
        for(int j = 0; j < n; j++)
        {
            if(!visited[0][j] && board[0][j] == 'O') bfs(board, visited, 0, j);
            if(!visited[m-1][j] && board[m-1][j] == 'O') bfs(board, visited, m-1, j);
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
    }
};