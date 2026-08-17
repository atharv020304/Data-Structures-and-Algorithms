class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            for (auto ele : graph[i])
            {
                adj[ele].push_back(i);
            }
        }

        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            indegree[i] = adj[i].size();
        }

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            for (auto ele : adj[temp])
            {
                indegree[ele]--;

                if (indegree[ele] == 0)
                {
                    q.push(ele);
                }
            }
        }

        vector<int> res;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};
