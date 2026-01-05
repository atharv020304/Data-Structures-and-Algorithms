class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negcount = 0;
        int mini = INT_MAX;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int x = matrix[i][j];

                if (x < 0) negcount++;

                int absx = abs(x);
                sum += absx;
                mini = min(mini, absx);
            }
        }

        if (negcount % 2 == 0) return sum;

        return sum - 2 * mini;
    }
};
