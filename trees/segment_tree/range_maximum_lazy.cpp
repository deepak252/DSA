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
        seg[i] = max(seg[2*i + 1], seg[2*i + 2]);
    }

    // Add delta with in range [ql, qr]
    void rangeUpdate(int i, int l, int r, int ql, int qr, int delta) {
        if(lazy[i] != 0) {
            seg[i] += lazy[i];
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
            seg[i] += delta;
            if(l != r) {
                lazy[2*i + 1] += delta;
                lazy[2*i + 2] += delta;
            }
            return;
        }
        // partial overlap
        int mid = (l + r) >> 1;
        rangeUpdate(2*i + 1, l, mid, ql, qr, delta);
        rangeUpdate(2*i + 2, mid + 1, r, ql, qr, delta);
        seg[i] = max(seg[2*i + 1], seg[2*i + 2]);
    }

    int queryLazy(int i, int l, int r, int ql, int qr) {
        if(lazy[i] != 0) {
            seg[i] += lazy[i];
            if(l != r) {
                seg[2*i + 1] += lazy[i];
                seg[2*i + 2] += lazy[i];
            }
            lazy[i] = 0;
        }
        if(l > qr || r < ql) {
            return INT_MIN;
        }
        if(l >= ql && r <= qr) {
            return seg[i];
        }
        int mid = (l + r) >> 1;
        int left = queryLazy(2*i + 1, l, mid, ql, qr);
        int right = queryLazy(2*i + 2, mid + 1, r, ql, qr);
        return max(left, right);
    }

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);
        lazy.resize(4*n);
        build(0, 0, n-1, nums);
    }

    int rangeMax(int l, int r) {
        return queryLazy(0, 0, n-1, l, r);
    }

    void rangeUpdate(int l, int r, int delta) {
        rangeUpdate(0, 0, n-1, l, r, delta);
    }
};


int main() {
    vector<int> arr = {2,3,1,5,4};
    SegmentTree seg = SegmentTree(arr);

    cout<<seg.rangeMax(0, 2)<<endl;    // 3
    cout<<seg.rangeMax(3, 4)<<endl;    // 5

    // seg.pointUpdate(2, 7);
    // seg.pointUpdate(4, 9);

    seg.rangeUpdate(2, 2, 7); // {2,3,8,5,4};
    seg.rangeUpdate(4, 4, 9); // {2,3,8,5,13};

    cout<<seg.rangeMax(0, 2)<<endl;    // 8
    cout<<seg.rangeMax(3, 4)<<endl;    // 13

    seg.rangeUpdate(0, 2, 2); // {4,5,10,5,4};
    seg.rangeUpdate(3, 4, 3); // {4,5,10,8, 16};

    cout<<seg.rangeMax(0, 2)<<endl;    // 10
    cout<<seg.rangeMax(3, 4)<<endl;    // 16

    return 0;
}