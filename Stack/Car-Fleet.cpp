class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> arr; // {position, speed}

        for (int i = 0; i < position.size(); i++) {
            arr.push_back({position[i], speed[i]});
        }

        // Sort by position in descending order
        sort(arr.begin(), arr.end(), [](const pair<int, int>& a,
                                        const pair<int, int>& b) {
            return a.first > b.first;
        });

        stack<double> st;

        for (int i = 0; i < arr.size(); i++) {
            // double because arrival time can be fractional
            double time = (double)(target - arr[i].first) / arr[i].second;

            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }

        return st.size();
    }
};

/*
Approach:
- Sort cars by position in descending order (closest to target first).
- Calculate each car's time to reach the target.
- If current car's time > previous fleet's time, it cannot catch the fleet ahead,
  so it forms a new fleet.
- Otherwise, it catches the fleet ahead and becomes part of that fleet.
- Use double because arrival time can be fractional.
*/
