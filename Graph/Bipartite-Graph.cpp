class Solution {
public:

    bool helper(vector<vector<int>>& graph, int curr, vector<int>& color, int currColor)
    {
        queue<int> q;
        q.push(curr);
        color[curr] = currColor;

        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            for(auto& ele : graph[front])
            {
                if(color[ele] == color[front])
                {
                    return false;
                } else if(color[ele] == -1) {
                    color[ele] = 1 - color[front];
                    q.push(ele);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);

        for(int i = 0; i < v; i++)
        {
            if(color[i] == -1)
            {
                if(!helper(graph, i, color, 0))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
