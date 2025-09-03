class Solution {
public:
    struct customComparator {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];  
        }
    };

    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), customComparator());
        int n = points.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int bestY = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                if (points[j][1] <= points[i][1]) {
                    if (points[j][1] > bestY) {
                        count++;
                        bestY = points[j][1];
                    }
                }
            }
        }
        return count;
    }
};

/*
Sorting:

Sort points by x ascending.

If x is the same, sort by y descending.

This ensures that for any i < j, points[j] is always to the right of points[i], and higher y values for same x are handled correctly.

Counting Pairs:

For each point (x1, y1) (top-left candidate), scan all points (x2, y2) with j > i.

Only consider (x2, y2) if y2 <= y1 (must be lower or equal).

bestY significance:

Tracks the maximum y seen so far while scanning rightwards.

Ensures we only count a pair if it is not blocked by another point with a higher y.

Prevents overcounting when multiple valid right-side points exist. */



