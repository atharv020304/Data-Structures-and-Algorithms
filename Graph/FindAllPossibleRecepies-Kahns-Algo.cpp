class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies)
    {
        int n = recipes.size();

        vector<string> result;

        unordered_set<string> s(supplies.begin(), supplies.end());

        unordered_map<string, vector<int>> adj;

        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto &ele : ingredients[i])
            {
                if (!s.count(ele))
                {
                    adj[ele].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int> que;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
            }
        }

        // Kahn's algorithm
        while (!que.empty())
        {
            int temp = que.front();
            que.pop();

            result.push_back(recipes[temp]);

            if (adj.count(recipes[temp]))
            {
                for (auto &index : adj[recipes[temp]])
                {
                    indegree[index]--;
                    if (indegree[index] == 0)
                    {
                        que.push(index);
                    }
                }
            }
        }

        return result;
    }
};
