#include<bits/stdc++.h>

using namespace std;


int searchIter(vector<int> &a, int target){
    int l=0, r=a.size()-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(target<a[mid]){
            r=mid-1;
        }else if(target>a[mid]){
            l=mid+1;
        }else{
            return mid;
        }
    }
    if(l<a.size() && l>=0 && a[l]==target)
        return l;
    return -1;
}

int main(){
    vector<int> a = {1,2,3,4,5,6,7,8};
    int target = 8;
    for(int i=-1;i<10;i++){
        cout<<i<<" is Present at index : "<<searchIter(a,i)<<endl;
    }
    // int index = searchIter(a,target);
    // cout<<"Index is "<<index<<endl;

}