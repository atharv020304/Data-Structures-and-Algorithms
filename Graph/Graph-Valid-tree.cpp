class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
        stack<pair<int, int>> st;
        st.push({start, -1});
        visited[start] = true;

        while (!st.empty()) {
            auto [node, parent] = st.top();
            st.pop();

            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    st.push({nei, node});
                } else if (nei != parent) {
                    return false; 
                }
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        if (!dfs(adj, visited, 0)) {
            return false;
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};
