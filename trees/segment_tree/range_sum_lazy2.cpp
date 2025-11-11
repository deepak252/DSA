#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> seg;
    vector<int> lazy;
    vector<int> hasLazy;

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

    void pushDown(int i, int l, int r) {
        if(!hasLazy[i]) {
            return;
        }
        seg[i] = (r - l + 1)*lazy[i];
        if(l != r) {
            lazy[2*i + 1] = lazy[i];
            lazy[2*i + 2] = lazy[i];
            hasLazy[2*i + 1] = hasLazy[2*i + 2] = true;
        }
        hasLazy[i] = false;
    }

    // Replace all nums with val within indexes range [l, r]
    void rangeUpdate(int i, int l, int r, int ql, int qr, int val) {
        pushDown(i, l, r);
        // no overlap
        if(l > qr || r < ql) {
            return;
        }
        // full overlap
        if(l >= ql && r <= qr) {
            seg[i] = (r-l+1)*val;
            if(l != r) {
                lazy[2*i + 1] = val;
                lazy[2*i + 2] = val;
                hasLazy[2*i + 1] = hasLazy[2*i + 2] = true;
            }
            return;
        }
        int mid = (l + r) >> 1;
        rangeUpdate(2*i + 1, l, mid, ql, qr, val);
        rangeUpdate(2*i + 2, mid+1, r, ql, qr, val);
        seg[i] = seg[2*i + 1] + seg[2*i + 2];
    }
    
    int queryLazy(int i, int l, int r, int ql, int qr) {
        pushDown(i, l, r);
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
        hasLazy.resize(n*4);
        build(0, 0, n-1, nums);
    }

    void rangeUpdate(int l, int r, int delta) {
        rangeUpdate(0, 0, n-1, l, r, delta);
    }

    int queryRangeSum(int l, int r) {
        return queryLazy(0, 0, n-1, l, r);
    }
};

int main() {#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> seg;
    vector<int> lazy;
    vector<int> hasLazy;

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

    void pushDown(int i, int l, int r) {
        if(!hasLazy[i]) {
            return;
        }
        seg[i] = (r - l + 1)*lazy[i];
        if(l != r) {
            lazy[2*i + 1] = lazy[i];
            lazy[2*i + 2] = lazy[i];
            hasLazy[2*i + 1] = hasLazy[2*i + 2] = true;
        }
        hasLazy[i] = false;
    }

    // Replace all nums with val within indexes range [l, r]
    void rangeUpdate(int i, int l, int r, int ql, int qr, int val) {
        pushDown(i, l, r);
        // no overlap
        if(l > qr || r < ql) {
            return;
        }
        // full overlap
        if(l >= ql && r <= qr) {
            seg[i] = (r-l+1)*val;
            if(l != r) {
                lazy[2*i + 1] = val;
                lazy[2*i + 2] = val;
                hasLazy[2*i + 1] = hasLazy[2*i + 2] = true;
            }
            return;
        }
        int mid = (l + r) >> 1;
        rangeUpdate(2*i + 1, l, mid, ql, qr, val);
        rangeUpdate(2*i + 2, mid+1, r, ql, qr, val);
        seg[i] = seg[2*i + 1] + seg[2*i + 2];
    }
    
    int queryLazy(int i, int l, int r, int ql, int qr) {
        pushDown(i, l, r);
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
        hasLazy.resize(n*4);
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
    segTree.rangeUpdate(1, 3, 2); //  {2,2,2,2,4};
    cout<<segTree.queryRangeSum(0, 2)<<endl;    // 6
    cout<<segTree.queryRangeSum(3, 4)<<endl;    // 6
    cout<<segTree.queryRangeSum(2, 3)<<endl;    // 4
    cout<<segTree.queryRangeSum(0, 4)<<endl;    // 12
    segTree.rangeUpdate(4, 4, 0); //  {2,2,2,2,10};
    cout<<segTree.queryRangeSum(0, 4)<<endl;    // 18
}
    vector<int> arr = {2,3,1,5,4};
    SegmentTree segTree = SegmentTree(arr);

    cout<<segTree.queryRangeSum(0, 2)<<endl;    // 6
    segTree.rangeUpdate(1, 3, 2); //  {2,2,2,2,4};
    cout<<segTree.queryRangeSum(0, 2)<<endl;    // 6
    cout<<segTree.queryRangeSum(3, 4)<<endl;    // 6
    cout<<segTree.queryRangeSum(2, 3)<<endl;    // 4
    cout<<segTree.queryRangeSum(0, 4)<<endl;    // 12
    segTree.rangeUpdate(4, 4, 10); //  {2,2,2,2,10};
    cout<<segTree.queryRangeSum(0, 4)<<endl;    // 18
}