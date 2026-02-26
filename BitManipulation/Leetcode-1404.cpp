// class Solution {
// public:
//     long long makenumber(string s)
//     {   
//         long long ans = 0;
//         for(int i = 0 ; i < s.size() ; i++)
//         {
//             if(s[i] == '1')
//             {
//                 ans += (1LL << (s.size() - i - 1));
//             }
//         }
//         return ans;
//     }

//     int numSteps(string s) {
//         long long num = makenumber(s);
//         int count = 0;
//         while(num != 1)
//         {
//             if(num % 2 != 0)
//             {
//                 num += 1;
//             } 
//             else 
//             {
//                 num /= 2;
//             }
//             count++;
//         }
//         return count;
//     }
// };


class Solution {
public:
    int numSteps(string s) {
        int count = 0;

        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back();
            } else {
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    s = '1' + s;
                }
            }
            count++;
        }

        return count;
    }
};