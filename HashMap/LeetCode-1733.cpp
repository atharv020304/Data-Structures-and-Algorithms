class Solution {
public:
    bool findcommonlangauge(vector<int>& a , vector<int>& b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]) return true;
            else if(a[i] < b[j]) i++;
            else j++;
        }
        return false;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> sadUsers;
        for(auto &f : friendships){
            int u = f[0]-1, v = f[1]-1;
            if(!findcommonlangauge(languages[u], languages[v])){
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }

        unordered_map<int,int> freq;
        for(auto u : sadUsers){
            for(auto lang : languages[u]){
                freq[lang]++;
            }
        }

        int mostCommon = 0;
        for(auto &p : freq) mostCommon = max(mostCommon, p.second);

        return sadUsers.size() - mostCommon;
    }
};
