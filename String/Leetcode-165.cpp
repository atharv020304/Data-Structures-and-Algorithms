class Solution {
public:
    int compareVersion(string v1, string v2) {
        
        vector<int>arr1 = split(v1);
        vector<int>arr2 = split(v2);
        
        int maxi = max(arr1.size(),arr2.size());
        
        arr1.resize(maxi,0);
        arr2.resize(maxi,0);
        
        for(int i = 0 ;i < maxi ;i++){
            if(arr1[i] <arr2[i]){
                return -1;
            }else if(arr1[i] > arr2[i]){
                return 1;
            }
        }
        
        return 0;
    }
    
    
    vector<int>split(string s){
        vector<int> res;
        
        std::stringstream ss(s);
        string temp;
        while(getline(ss,temp,'.')){
            res.push_back(stoi(temp));
        }
        return res;
    }
};