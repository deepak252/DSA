#include <bits/stdc++.h>
using namespace std;
#include "../custom_headers/dp.h"

int dp[1001][1001];
// length of longest common subsequence
int LCSsequenceLength(string s1, string s2, int l1, int l2)
{
    string subseq = "";
    for(int i=1;i<l1+1;i++){
        for(int j=1;j<l2+1;j++){
            if(s1[i-1]==s2[j-1]){
                // dp[i][j] = 1 + max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = 1 + dp[i - 1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[l1][l2];
}

string LCSsequence(string s1, string s2, int l1, int l2)
{
    LCSsequenceLength(s1, s2, s1.length(), s2.length());

    string subseq = "";
    int j=l2;
    for(int i=l1;i>0;i--){
        if(s1[i-1]==s2[j-1]){
            subseq=s1[i-1]+subseq;
        }else if(dp[i-1][j]<dp[i][j-1]){
            i++; //move left

        }else{
            j++; //move upward
        }
        j--;
    }

    return subseq;
}

int main()
{
    memset(dp, 0, sizeof(dp));
    // string s1 = "abcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdef";
    // string s2 = "acdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefs";
    string s1 = "abcdefabcdef";
    string s2 = "acdgbefsacdgbefs";

    // cout << LCSsequenceLength(s1, s2, s1.length(), s2.length()) << endl;
    cout << LCSsequenceLength(s1, s2, s1.length(), s2.length()) << endl;
    cout << LCSsequence(s1, s2, s1.length(), s2.length()) << endl;

    showdp(dp,s1.length()+1, s2.length()+1);
    
}