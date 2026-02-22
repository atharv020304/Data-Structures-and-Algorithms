class Solution {
    public int binaryGap(int n) {
        int max_d = 0;
        int prev= -1;
        int curr = n;

        while(curr != 0)
        {
            int pos = Integer.numberOfTrailingZeros(curr);

            if(prev != -1)
            {
                int distance = pos - prev;
                max_d = Math.max(max_distance, distance);
            }
            prev = pos;

            curr = curr & (curr-1)
        }
        return max_d;
    }
}