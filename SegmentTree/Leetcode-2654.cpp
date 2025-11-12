
static constexpr int MAX_SIZE = 128;
int seg[MAX_SIZE];

struct SegmentTree {
    unsigned int n;

    SegmentTree(vector<int>& arr) : n(arr.size()) {
        build(arr, 1, 0, n - 1);
    }

    ~SegmentTree() {
        fill(seg, seg + (2u * bit_ceil(n)), 0);
    }

    void build(vector<int>& arr, int index, int left, int right) {
        if (left == right) {
            seg[index] = arr[left];
        } else {
            int mid = (left + right) / 2;
            build(arr, 2 * index, left, mid);
            build(arr, 2 * index + 1, mid + 1, right);
            seg[index] = gcd(seg[2 * index], seg[2 * index + 1]);
        }
    }

    int query(int index, int left, int right, int ql, int qr) const {
        if (qr < left || right < ql) return 0;
        if (ql <= left && right <= qr) return seg[index];
        int mid = (left + right) / 2;
        return gcd(
            query(2 * index, left, mid, ql, qr),
            query(2 * index + 1, mid + 1, right, ql, qr)
        );
    }

    int rangeGCD(int left, int right) const {
        return query(1, 0, n - 1, left, right);
    }
};

class Solution {
public:
    static int minOperations(vector<int>& nums) {
        int n = nums.size();
        int onesCount = count(nums.begin(), nums.end(), 1);
        if (onesCount > 0) return n - onesCount;

        SegmentTree tree(nums);
        int minLength = INT_MAX;

        for (int left = 0, right = 0; left < n; left++) {
            int currentGCD;
            while (right < n && (currentGCD = tree.rangeGCD(left, right)) > 1) right++;
            if (right < n && currentGCD == 1)
                minLength = min(minLength, right - left + 1);
        }

        return (minLength == INT_MAX) ? -1 : minLength + n - 2;
    }
};