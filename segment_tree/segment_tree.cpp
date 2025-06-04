// Segment Tree: A data structure which stores the resultant of a given range in a given index in in arr
#include <bits/stdc++.h>

using namespace std;

class SegmentTree{
private: 
    int n = 0;
    vector<int> seg;
    vector<int> nums;

    void build(int i, int low, int high){
        if(low==high){
            seg[i] = nums[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*i+1, low, mid);
        build(2*i+2, mid+1, high);
        seg[i] = max(seg[2*i+1], seg[2*i+2]);
    }

    int rangeQuery(int i, int low, int high, int l, int r){
        if(high<l || low>r){
            return INT_MIN;
        }
        if(low>=l && high<=r){
            return seg[i];
        }
        int mid = (low+high)/2;
        int left = rangeQuery(2*i+1, low, mid, l, r);
        int right = rangeQuery(2*i+2, mid+1, high, l, r);

        return max(left, right);
    }
    // i: tree index(seg tree), node: array index
    void pointUpdate(int i, int low, int high, int node, int& newVal){
        if(low==high){
            seg[i] = newVal;
            return;
        }
        int mid = (low+high)>>1;
        if(node<=mid){
            pointUpdate(2*i+1, low, mid, node, newVal);
        }else{
            pointUpdate(2*i+2, mid+1, high, node, newVal);
        }
        seg[i] = max(seg[2*i+1], seg[2*i+2]);
    }

public: 
    SegmentTree(vector<int> nums){
        n = nums.size();
        seg.resize(n*4);
        this->nums = nums;
        build(0, 0, n-1);
    }

    int findRangeMax(int l, int r){
        return rangeQuery(0, 0, n-1, l, r);
    }

    void show(){
        for(auto s: seg) cout<<s<<" ";
        cout<<endl;
    }

    void updateNode(int node, int val){
        pointUpdate(0, 0, nums.size()-1, node, val);
    }
};

int main(){
    vector<int> arr = {2,3,1,5,4};
    SegmentTree seg_tree = SegmentTree(arr);

    cout<<seg_tree.findRangeMax(0, 2)<<endl;    // 3
    cout<<seg_tree.findRangeMax(3, 4)<<endl;    // 5

    seg_tree.updateNode(2, 7);
    seg_tree.updateNode(4, 9);

    cout<<seg_tree.findRangeMax(0, 2)<<endl;    // 7
    cout<<seg_tree.findRangeMax(3, 4)<<endl;    // 9


    return 0;
}