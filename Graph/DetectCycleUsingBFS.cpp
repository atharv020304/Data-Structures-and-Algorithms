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

    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (helper(i, adj, visited))
                    return true;
            }
        }

        return false;
    }
};
