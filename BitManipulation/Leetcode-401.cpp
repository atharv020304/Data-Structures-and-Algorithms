class Solution {
public:
    int cntbits(int x)
    {
        int count = 0;
        while(x)
        {
            x &= (x-1);
            count++;
        }
        return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for(int i = 0 ; i < 12 ; i++)
        {
            for(int j = 0 ; j < 60 ; j++)
            {
                if(cntbits(i)+cntbits(j) == turnedOn)
                {
                    string time = to_string(i) + ":";
                    if(j < 10) 
                        time += "0";
                    time += to_string(j);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};