class Solution {
public:
    int calcDist(int x1, int y1,int x2,int y2){
        int res = ((x1*x1 - 2*x1*x2 + x2*x2) + (y1*y1 - 2*y1*y2 + y2*y2));
        return res;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [&](const pair<int,int>& a,const pair<int,int>& b){
            int res1 = calcDist(a.first, a.second, 0, 0);
            int res2 = calcDist(b.first, b.second, 0, 0);
            return res1 < res2; 
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for(int i = 0 ; i < points.size() ; i++){
            pq.push({points[i][0], points[i][1]});
            if(pq.size() > k) pq.pop(); 
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            ans.push_back({t.first, t.second});
        }

        return ans;
    }
};
