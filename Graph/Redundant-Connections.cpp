class Solution {
public:

    bool hasPath(int src, int target, vector<vector<int>>& adj)
    {
        int n = adj.size();

        vector<bool> visited(n, false);
        stack<int> st;

        st.push(src);
        visited[src] = true;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (node == target)
                return true;

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    st.push(neighbor);
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();

        vector<vector<int>> adj(n + 1);
        vector<int> ans;

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            if (hasPath(u, v, adj))
            {
                ans = {u, v};
            }
            else
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        return ans;
    }
};
