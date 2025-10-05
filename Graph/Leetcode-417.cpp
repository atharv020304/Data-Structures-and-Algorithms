class Solution {
public:
    void dfs(vector<vector<int>>& h, int r, int c, vector<vector<bool>>& vis){
        int m = h.size(), n = h[0].size();
        vis[r][c] = true;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto d : dir){
            int nr = r + d.first, nc = c + d.second;
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && !vis[nr][nc] && h[nr][nc] >= h[r][c])
                dfs(h,nr,nc,vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h){
        int m = h.size(), n = h[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false));

        for(int i = 0; i < m; i++) dfs(h,i,0,pac);
        for(int j = 0; j < n; j++) dfs(h,0,j,pac);

        for(int i = 0; i < m; i++) dfs(h,i,n-1,atl);
        for(int j = 0; j < n; j++) dfs(h,m-1,j,atl);

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
