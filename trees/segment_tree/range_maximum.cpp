#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> seg;

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

    int query(int i, int l, int r, int ql, int qr) {
        if(l > qr || r < ql) {
            return INT_MIN;
        }
        if(l >= ql && r <= qr) {
            return seg[i];
        }
        int mid = (l + r) >> 1;
        int left = query(2*i + 1, l, mid, ql, qr);
        int right = query(2*i + 2, mid + 1, r, ql, qr);
        return max(left, right);
    }

    void pointUpdate(int i, int l, int r, int qi, int val) {
        if(l > qi || r < qi) {
            return;
        }
        if(l == r) {
            seg[i] = val;
            return;
        }
        int mid = (l + r) >> 1;
        pointUpdate(2*i + 1, l, mid, qi, val);
        pointUpdate(2*i + 2, mid + 1, r, qi, val);
        seg[i] = max(seg[2*i + 1], seg[2*i + 2]);
    }

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);
        build(0, 0, n-1, nums);
    }

    void pointUpdate(int i, int val) {
        pointUpdate(0, 0, n-1, i, val);
    }

    int rangeMax(int l, int r) {
        return query(0, 0, n-1, l, r);
    }
};


int main() {
    vector<int> arr = {2,3,1,5,4};
    SegmentTree seg = SegmentTree(arr);

    cout<<seg.rangeMax(0, 2)<<endl;    // 3
    cout<<seg.rangeMax(3, 4)<<endl;    // 5

    seg.pointUpdate(2, 7);
    seg.pointUpdate(4, 9);

    cout<<seg.rangeMax(0, 2)<<endl;    // 7
    cout<<seg.rangeMax(3, 4)<<endl;    // 9


    return 0;
}