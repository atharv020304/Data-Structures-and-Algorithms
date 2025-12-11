class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        vector<int> rmax(n + 1, 0), rmin(n + 1, n + 1);
        vector<int> cmax(n + 1, 0), cmin(n + 1, n + 1);

        for (auto &p : b) {
            int x = p[0], y = p[1];
            rmax[y] = max(rmax[y], x);
            rmin[y] = min(rmin[y], x);
            cmax[x] = max(cmax[x], y);
            cmin[x] = min(cmin[x], y);
        }

        int ans = 0;
        for (auto &p : b) {
            int x = p[0], y = p[1];
            if (rmin[y] < x && x < rmax[y] && cmin[x] < y && y < cmax[x])
                ans++;
        }

        return ans;
    }
};
