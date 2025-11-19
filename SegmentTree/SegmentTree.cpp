#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    int n; // size
    vector<long long> tree;

    SegmentTree(int n)
    {
        this->n = n;
        tree.resize(4 * n); // safe upper bound in worst case recursion shape
    }

    void BuildTree(vector<int> &arr, int index, int left, int right)
    {
        if (left == right)
        {
            tree[index] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        BuildTree(arr, 2 * index, left, mid);
        BuildTree(arr, (2 * index) + 1, mid + 1, right);
        tree[index] = tree[2 * index] + tree[(2 * index) + 1];
    }

    void update(int idx, int val, int i, int l, int r)
    {
        if (l == r)
        {
            tree[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, 2 * i, l, mid);
        else
            update(idx, val, 2 * i + 1, mid + 1, r);
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    long long RangeSum(int start, int end, int idx, int l, int r)
    {
        // Completely outside range
        if (l > end || r < start)
            return 0;

        // Completely inside range
        if (l >= start && r <= end)
            return tree[idx];

        int mid = (l + r) / 2;

        return RangeSum(start, end, 2 * idx, l, mid) + RangeSum(start, end, 2 * idx + 1, mid + 1, r);
    }
};

int main()
{

    vector<int> arr = {5, 1, 2, 6, 7, 8, 4, 3};
    SegmentTree st(arr.size());
    st.BuildTree(arr, 1, 0, arr.size() - 1);
    st.update(3, 10, 1, 0, arr.size() - 1);
    long long res = st.RangeSum(2, 5, 1, 0, arr.size() - 1);
    return 0;
}