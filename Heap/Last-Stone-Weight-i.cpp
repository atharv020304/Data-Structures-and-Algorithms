class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto ele : stones)
        {
            pq.push(ele);
        }

        while(true)
        {
            if(pq.empty())
            {
                return 0;
            }

            if(pq.size() == 1)
            {
                return pq.top();
            }
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x == y)
            {   
                continue;
            }else{
                y = y - x;
                if(y > 0)
                  pq.push(y);
            }
        }

    }
};
