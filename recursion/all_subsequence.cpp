#include<bits/stdc++.h>

using namespace std;

void allSubseq(vector<int> &arr,vector<int> seq, int i){
    if(i>=arr.size()){
        for(int i=0;i<seq.size();i++)
            cout<<seq[i]<<" ";
        cout<<endl;
        return;
    }
    allSubseq(arr,seq,i+1);
    seq.push_back(arr[i]);
    allSubseq(arr,seq,i+1);
}

int main(){
    vector<int> arr={3,5,1,2};
    vector<int> temp={};
    allSubseq(arr,temp,0);
}