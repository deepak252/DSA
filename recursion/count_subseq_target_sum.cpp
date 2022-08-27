#include<bits/stdc++.h>

using namespace std;

int countSubseq(vector<int>& arr, int sum, int currSum, int i){
    if(sum==currSum){
        return 1;
    }
    if(i>=arr.size() || currSum>sum){
        return 0;
    }
    return countSubseq(arr, sum, currSum+arr[i], i+1)+ countSubseq(arr, sum, currSum, i+1);
}

int main(){
    vector<int> arr={1,2,1,1};
    int sum=2;
    cout<<countSubseq(arr,sum,0,0)<<endl;
}