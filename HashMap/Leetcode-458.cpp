class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int freq = 0;
        unordered_map<int,int> mp;
        int n = A.size();

        for(int i = 0 ; i < n ;i++)
        {
            if(++mp[A[i]] == 2){
                freq++;
            }
            if(++mp[B[i]] == 2)
            {
                freq++;
            }

            ans.push_back(freq);
        }
        return ans;
    }
};



