#include<bits/stdc++.h>

using namespace std;

// Range sum: query, update, query, upd....
// range sum queries and point updates (adding a number to an element in the array)
class SegmentTree{
private: 
    vector<int> nums, seg;
    int n;
    
    void build(int index, int low, int high){
        if(low==high){
            seg[index] = nums[low];
            return;
        }
        int mid = (low+high)/2;
        build(index*2+1, low, mid);
        build(index*2+2, mid+1, high);
        seg[index] = seg[index*2+1]+seg[index*2+2];
    }

    int query(int index, int low, int high, int l, int r){
        if(r<low || l>high){
            return 0;
        }
        if(l<=low && r>=high){
            return seg[index];
        }
        int mid = (low+high)/2;
        int left = query(2*index+1, low, mid, l, r);
        int right = query(2*index+2, mid+1, high, l, r);
        return left+right;
    }

    void addNum(int index, int low, int high, int& pos, int& num){
        if(low==high){
            return;
        }
        int mid = (low+high)/2;
        if(pos<=mid){
            addNum(2*index+1, low, mid, pos, num); // move to the left sub tree
        }else{
            addNum(2*index+2, mid+1, high, pos, num); // move to the right sub tree
        }
        seg[index]+=num;
    }


public:
    SegmentTree(vector<int> nums){
        this->nums = nums;
        n = nums.size();
        seg.resize(4*n);
        build(0, 0, n-1);
        // for(auto s: seg) cout<<s<<" ";
        // cout<<endl;
    }

    int rangeSum(int l, int r){
        return query(0, 0, n-1, l, r);
    }

    void addNum(int index, int num){
        addNum(0, 0, n-1, index, num);
    }
};

int main(){
    vector<int> arr = {2,3,1,5,4};
    SegmentTree seg_tree = SegmentTree(arr);

    cout<<seg_tree.rangeSum(0, 2)<<endl;
    seg_tree.addNum(0, 12);
    cout<<seg_tree.rangeSum(0, 2)<<endl;
    cout<<seg_tree.rangeSum(3, 4)<<endl;
    cout<<seg_tree.rangeSum(2, 3)<<endl;
    cout<<seg_tree.rangeSum(0, 4)<<endl;

    return 0;
}

