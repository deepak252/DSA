#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> seg;
    vector<int> lazy;

    void build(int i, int l, int r, vector<int>& nums) {
        if(l == r) {
            seg[i] = nums[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2*i + 1, l, mid, nums);
        build(2*i + 2, mid + 1, r, nums);
        seg[i] = seg[2*i + 1] + seg[2*i + 2];
    }

    // Adds delta to each number with in indexes range [l, r]
    void rangeUpdate(int i, int l, int r, int ql, int qr, int delta) {
        if(lazy[i] != 0) {
            seg[i] += (r-l+1)*lazy[i];
            if(l != r) {
                lazy[2*i + 1] += lazy[i];
                lazy[2*i + 2] += lazy[i];
            }
            lazy[i] = 0;
        }
        // no overlap
        if(l > qr || r < ql) {
            return;
        }
        // full overlap
        if(l >= ql && r <= qr) {
            seg[i] += (r-l+1)*delta;
            if(l != r) {
                lazy[2*i + 1] += delta;
                lazy[2*i + 2] += delta;
            }
            return;
        }
        int mid = (l + r) >> 1;
        rangeUpdate(2*i + 1, l, mid, ql, qr, delta);
        rangeUpdate(2*i + 2, mid+1, r, ql, qr, delta);
        seg[i] = seg[2*i + 1] + seg[2*i + 2];
    }
    
    int queryLazy(int i, int l, int r, int ql, int qr) {
        if(lazy[i] != 0) {
            seg[i] += (r-l+1)*lazy[i];
            if(l != r) {
                lazy[2*i + 1] += lazy[i];
                lazy[2*i + 2] += lazy[i];
            }
            lazy[i] = 0;
        }
        // no overlap
        if(l > qr || r < ql) {
            return 0;
        }
        // full overlap
        if(l >= ql && r <= qr) {
            return seg[i];
        }
        int mid = (l + r) >> 1;
        int left = queryLazy(2*i + 1, l, mid, ql, qr);
        int right = queryLazy(2*i + 2, mid+1, r, ql, qr);
        return left + right;
    }

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        seg.resize(n*4);
        lazy.resize(n*4);
        build(0, 0, n-1, nums);
    }

    void rangeUpdate(int l, int r, int delta) {
        rangeUpdate(0, 0, n-1, l, r, delta);
    }

    int queryRangeSum(int l, int r) {
        return queryLazy(0, 0, n-1, l, r);
    }
};

int main() {
    vector<int> arr = {2,3,1,5,4};
    SegmentTree segTree = SegmentTree(arr);

    cout<<segTree.queryRangeSum(0, 2)<<endl;    // 6
    segTree.rangeUpdate(1, 3, 2); //  {2,5,3,7,4};
    cout<<segTree.queryRangeSum(0, 2)<<endl;    // 10
    cout<<segTree.queryRangeSum(3, 4)<<endl;    // 11
    cout<<segTree.queryRangeSum(2, 3)<<endl;    // 10
    cout<<segTree.queryRangeSum(0, 4)<<endl;    // 21
    segTree.rangeUpdate(4, 4, 10); //  {2,5,3,7, 14};
    cout<<segTree.queryRangeSum(0, 4)<<endl;    // 31
}