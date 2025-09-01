class Solution {
public:
    struct CompareByRatio {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            double ratioA = ((a[0]+1.0) / (a[1]+1)) - ((double)a[0]/a[1]);
            double ratioB = ((b[0]+1.0)/(b[1]+1)) - ((double)b[0]/b[1]);
            return ratioA < ratioB;
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<int>, vector<vector<int>>, CompareByRatio> pq;

        for (auto &r : classes) {
            pq.push(r);
        }

        while (extraStudents > 0) {
            vector<int> temp = pq.top(); 
            pq.pop();
            temp[1] += 1;
            temp[0] += 1;
            extraStudents--;
            pq.push(temp);
        }

        double ans = 0;
        while (!pq.empty()) {
            vector<int> t = pq.top(); 
            pq.pop();
            ans += (double)t[0] / t[1]; 
        }
        return ans / classes.size(); 
    }
};
