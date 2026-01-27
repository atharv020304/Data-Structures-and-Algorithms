class Solution {
public:
    int helper(int n, vector<vector<int>>& edges, int src, int dest) {
 
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }
 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> dist(n, INT_MAX);
 
        dist[src] = 0;
        pq.push({0, src});
 
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
 
            if (d > dist[u]) continue;
 
            
            if (u == dest) return d;
 
            for (auto &[v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
 
        return -1; 
    }
 
    int minCost(int n, vector<vector<int>>& edges) {
 
        int size = edges.size();
 
        for (int i = 0; i < size; i++) {
            edges.push_back({
                edges[i][1],
                edges[i][0],
                edges[i][2] * 2
            });
        }
 
        return helper(n, edges, 0, n - 1);
    }
};