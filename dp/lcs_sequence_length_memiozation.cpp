#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
// length of longest common subsequence
int LCSsequenceLength(string s1, string s2, int l1, int l2)
{
    if(l1==0 || l2==0) return 0;
    if(dp[l1][l2]!=-1) return dp[l1][l2];

    if(s1[l1-1]==s2[l2-1]){
        return dp[l1][l2] = 1+LCSsequenceLength(s1,s2,l1-1, l2-1);
    }else{
        return dp[l1][l2] = max(LCSsequenceLength(s1, s2, l1, l2 - 1), LCSsequenceLength(s1, s2, l1 - 1, l2));
    }
}

int main()
{
    memset(dp,-1,sizeof(dp));
    string s1 = "abcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdef";
    string s2 = "acdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefs";
    // string s1 = "abcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdef";
    // string s2 = "acdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefsacdgbefs";
    // string s1 = "abcdef";
    // string s2 = "acdgbefs";

    cout << LCSsequenceLength(s1, s2, s1.length(), s2.length()) << endl;
}