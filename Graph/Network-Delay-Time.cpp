class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1); // src -> {dst,w}
        for(auto ele : times)
        {
            int src = ele[0];
            int dst = ele[1];
            int w = ele[2];

            adj[src].push_back({dst,w});
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0 ;
        pq.push({0,k});

        while(!pq.empty())
        {
            auto [curr,u] = pq.top();
            pq.pop();

            //skip
            if(curr > dist[u]){
                continue;
            }

            for( auto &ele : adj[u])
            {
                int v = ele.first;
                int wt = ele.second;

                if(dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;

    }
};
