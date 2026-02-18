class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int val = n ^ (n >> 1);

        return (val & (val+1)) == 0;

    }
};