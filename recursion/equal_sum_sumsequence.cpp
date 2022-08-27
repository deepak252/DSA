#include<bits/stdc++.h>

using namespace std;

void allSubseqTargetSum(vector<int> arr, int sum,int currSum, vector<int> subseq,int i){
    if(sum==currSum){
        for(int i=0;i<subseq.size();i++){
            cout<<subseq[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(i>=arr.size() || currSum>sum){
        return;
    }
    allSubseqTargetSum(arr, sum, currSum, subseq, i + 1);
    subseq.push_back(arr[i]);
    allSubseqTargetSum(arr, sum, currSum + arr[i], subseq, i + 1);
}
int ccount=0;

bool anySubseqTargetSum(vector<int> arr, int sum, int currSum, vector<int> subseq, int i)
{
    ccount++;
    cout << ccount << endl;
    if(sum==currSum){
        // susequence found
        for (int j = 0; j < subseq.size(); j++)
        {
            cout << subseq[j] << " ";
        }
        cout << endl;
        return true;
    }
    if (i >= arr.size() || currSum > sum)
        return false;

    if (!anySubseqTargetSum(arr, sum, currSum, subseq, i + 1))
    {
        subseq.push_back(arr[i]);
        return anySubseqTargetSum(arr, sum, currSum + arr[i], subseq, i + 1);
    }
    return true;
}

int main(){
    // vector<int> arr={1,2,1,1,2,1,1,2,1,};
    vector<int> arr={1,2,1};
    int targetSum = 3;
    // allSubseqTargetSum(arr, targetSum, 0, {}, 0);
    anySubseqTargetSum(arr, targetSum, 0, {}, 0);
}