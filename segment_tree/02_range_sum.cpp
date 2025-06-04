// Given an array arr[], efficiently compute the sum of elements from index l to r, i.e.,
// sum = arr[l] + arr[l+1] + ... + arr[r]
#include <bits/stdc++.h>

using namespace std;

class SegmentTree{
private:
    vector<int> arr;
    vector<int> seg;
    void build(int i, int low, int high){
        if(low==high){
            seg[i] = arr[low];
            return;
        }
        int mid = (low + high)/2;
        build(i*2+1, low, mid);
        build(i*2+2, mid+1, high);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    int query(int i, int low, int high, int l, int r){
        if(high<l || low>r){
            return 0;
        }
        if(low>=l && high<=r){
            return seg[i];
        }
        int mid = (low+high)/2;
        int left = query(i*2+1, low, mid, l, r);
        int right = query(i*2+2, mid+1, high, l, r);
        return left+right;
    }

    void pointUpdate(int i, int low, int high, int node, int val){
        if(low==high){
            seg[i] = val;
            return;
        }
        int mid = (low+high)/2;
        if(node<=mid){
            pointUpdate(2*i+1, low, mid, node, val);
        }else{
            pointUpdate(2*i+2, mid+1, high, node, val);
        }
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

public:
    SegmentTree(vector<int>& arr){
        this->arr = arr;
        this->seg.resize(arr.size()*4);
        build(0, 0, arr.size()-1);
    }

    int findRangeSum(int l, int r){
        return query(0, 0, arr.size()-1, l, r);
    }

    void updateNode(int node, int val){
        pointUpdate(0, 0, arr.size()-1, node, val);
    }
};


int main(){
    vector<int> arr = {2,3,1,5,4};
    SegmentTree seg_tree = SegmentTree(arr);

    cout<<seg_tree.findRangeSum(0, 2)<<endl;    // 6
    seg_tree.updateNode(1, 7);
    cout<<seg_tree.findRangeSum(0, 2)<<endl;    // 10
    cout<<seg_tree.findRangeSum(3, 4)<<endl;
    cout<<seg_tree.findRangeSum(2, 3)<<endl;
    cout<<seg_tree.findRangeSum(0, 4)<<endl;    // 19
    seg_tree.updateNode(4, 100);
    cout<<seg_tree.findRangeSum(0, 4)<<endl;    // 115

    return 0;
}
