class Solution {
public:
    
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    int maxDist = 0;
    
    bool isObstacle(int x, int y, vector<vector<int>>& obs) {
        for(auto &o : obs) {
            if(o[0] == x && o[1] == y) return true;
        }
        return false;
    }
    
    pair<int,int> helper(vector<int>& commands, vector<vector<int>>& obs, int i, int j, int cnt, int dirindex)
    {
        if(cnt == commands.size())
        {
            return {i,j};
        }

        if(commands[cnt] > 0)
        {
            for(int k = 0 ; k < commands[cnt]; k++)
            {
                int ni = i + dir[dirindex][0];
                int nj = j + dir[dirindex][1];
                
                if(isObstacle(ni, nj, obs)) break;
                
                i = ni;
                j = nj;

                maxDist = max(maxDist, i*i + j*j);
            }
        }
        else if(commands[cnt] == -2)
        {
            dirindex = (dirindex + 3) % 4;
        }
        else if(commands[cnt] == -1)
        {
            dirindex = (dirindex + 1) % 4;
        }

        return helper(commands, obs, i, j, cnt+1, dirindex);
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
        helper(commands, obs, 0, 0, 0, 0);
        return maxDist;
    }
};
