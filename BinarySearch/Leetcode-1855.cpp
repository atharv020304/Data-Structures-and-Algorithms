//TLE
// class Solution {
// public:
//     int maxDistance(vector<int>& nums1, vector<int>& nums2) {
//         int maxD = INT_MIN;
//         for(int i = 0 ; i < nums1.size(); i++)
//         {
//             for(int j = 0 ; j < nums2.size(); j++)
//             {
//                 if(i <= j && nums1[i] <= nums2[j])
//                 {
//                     maxD = max( maxD , j - i );
//                 }
//             }
//         }
//         return maxD > 0 ? maxD : 0 ;
//     }
// };


class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;

        for (int i = 0; i < nums1.size(); i++) {

            int low = i, high = nums2.size() - 1;
            int best = -1;

            while (low <= high) {
                int mid = (low + high) / 2;

                if (nums2[mid] >= nums1[i]) {
                    best = mid;       // valid
                    low = mid + 1;    // try to go further right
                } else {
                    high = mid - 1;   // go left
                }
            }

            if (best != -1) {
                ans = max(ans, best - i);
            }
        }

        return ans;
    }
};