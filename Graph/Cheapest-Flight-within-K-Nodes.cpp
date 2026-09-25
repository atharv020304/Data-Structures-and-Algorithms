class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &ele : flights) {
            int u = ele[0];
            int v = ele[1];
            int cost = ele[2];

            adj[u].push_back({v, cost});
        }

        vector<int> distance(n, INT_MAX);
        distance[src] = 0;

        queue<int> q;
        q.push(src);

        int stops = 0;

        while (!q.empty() && stops <= k) {

            int size = q.size();

            vector<int> temp = distance;

            while (size--) {

                int node = q.front();
                q.pop();

                for (auto &edge : adj[node]) {

                    int next = edge.first;
                    int price = edge.second;

                    if (distance[node] != INT_MAX &&
                        distance[node] + price < temp[next]) {

                        temp[next] = distance[node] + price;
                        q.push(next);
                    }
                }
            }

            distance = temp;
            stops++;
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
