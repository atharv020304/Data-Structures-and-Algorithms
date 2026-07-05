class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        int minEdge = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &[next, weight] : adj[node]) {

                minEdge = min(minEdge, weight);

                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        return minEdge;
    }
};
