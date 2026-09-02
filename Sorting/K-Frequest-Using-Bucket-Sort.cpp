class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        // Count how often each number appears
        unordered_map<int, int> frequency;

        for (int num : nums) {
            frequency[num]++;
        }


        // bucket[i] stores numbers that appear exactly i times
        vector<vector<int>> bucket(n + 1);

        for (auto& [num, count] : frequency) {
            bucket[count].push_back(num);
        }


        vector<int> answer;

        // Start from the highest frequency
        for (int freq = n; freq >= 1; freq--) {

            for (int num : bucket[freq]) {

                answer.push_back(num);
                if (answer.size() == k) {
                    return answer;
                }
            }
        }

        return answer;
    }
};
