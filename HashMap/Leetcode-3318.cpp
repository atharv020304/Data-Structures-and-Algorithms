class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        for(int i=0;i<=nums.size()-k;i++){
            map<int,int,greater<int>> mp;
            int sum = 0;
            for(int j=0;j<k;j++){
                mp[nums[i+j]]+=1;
            }
            multimap<int,int,greater<int>> mlp;
            for( auto& p:mp){
                mlp.insert({p.second,p.first});
            }
            int cnt=0;
            for(const auto& it:mlp){
                if(cnt==x){
                    break;
                }
                sum += it.first * it.second;
                cnt++;
            }
            res.push_back(sum);
        }
        return res;
    }
};