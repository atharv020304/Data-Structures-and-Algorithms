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


//simpler approch
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> ans;
        
        for (int len = 1; len <= 9; ++len) {
            for (int i = 0; i + len <= 9; ++i) {
                int num = stoi(digits.substr(i, len));
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};
