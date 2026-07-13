// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int> ans;
//         for (int start = 1; start <= 9; ++start) {
//             int num = start;
//             int next = start + 1;
//             while (num <= high && next <= 10) {
//                 if (num >= low) ans.push_back(num);
//                 num = num * 10 + next;
//                 next++;
//             }
//         }
//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };
