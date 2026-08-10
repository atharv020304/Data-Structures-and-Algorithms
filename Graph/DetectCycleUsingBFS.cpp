class Solution {
public:

    bool helper(int s, vector<int> adj[], vector<bool>& visited)
    {
        queue<pair<int, int>> q;

        visited[s] = true;
        q.push({s, -1});

        while (!q.empty())
        {
            auto [node, parent] = q.front();
            q.pop();

            for (auto ele : adj[node])
            {
                if (!visited[ele])
                {
                    visited[ele] = true;
                    q.push({ele, node});
                }
                else if (ele != parent)
                {
                    return true;
                }
            }
        }

        return false;
    }
    
    bool dfs(int s, vector<int> adj[], vector<bool>& visited)
    {
    stack<pair<int, int>> st;

    visited[s] = true;
    st.push({s, -1});

    while (!st.empty())
    {
        auto [node, parent] = st.top();
        st.pop();

        for (auto ele : adj[node])
        {
            if (!visited[ele])
            {
                visited[ele] = true;
                st.push({ele, node});
            }
            else if (ele != parent)
            {
                return true;
            }
        }
    }

    return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited))
                    return true;
            }
        }

        return false;
    }
};
