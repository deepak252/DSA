// Segment Tree: A data structure which stores the resultant of a given range in a given index in in arr
#include <bits/stdc++.h>

using namespace std;

class SegmentTree{
private: 
    int n = 0;
    vector<int> seg;
    vector<int> nums;

    void build(int ind, int low, int high){
        if(low==high){
            seg[ind] = nums[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1, low, mid);
        build(2*ind+2, mid+1, high);
        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    }

    int rangeQuery(int ind, int low, int high, int l, int r){
        if(l<=low && r>=high){
            return seg[ind];
        }
        if(r<low || l>high){
            return INT_MIN;
        }
        int mid = (low+high)/2;
        int left = rangeQuery(2*ind+1, low, mid, l, r);
        int right = rangeQuery(2*ind+2, mid+1, high, l, r);

        return max(left, right);
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
};

int main(){
    vector<int> arr = {2,3,1,5,4};
    SegmentTree seg_tree = SegmentTree(arr);

    cout<<seg_tree.findRangeMax(0, 2)<<endl;
    cout<<seg_tree.findRangeMax(3, 4)<<endl;


    return 0;
}