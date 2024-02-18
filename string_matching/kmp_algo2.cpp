#include <bits/stdc++.h>

using namespace std;

vector<int> generateLPS(string &pat){
    int m = pat.size();
    vector<int> lps(m);
    for(int i=1, j=0; i<m; i++){
        while(j>0 && pat[i]!=pat[j]) j = lps[j-1];
        if(pat[i]==pat[j]) j++;
        lps[i]=j;
    }
    return lps;
}

vector<int> kmpSearch(string &s, string &pat){
    int n = s.size(), m = pat.size();
    vector<int> lps = generateLPS(pat);
    vector<int> indexes;
    for(int i=0, j=0; i<n; i++){
        while(j>0 && pat[j]!=s[i]) j = lps[j-1];
        if(pat[j]==s[i]) j++;
        if(j==m){
            indexes.push_back(i-j+1);
            j = lps[j-1];
        }
    }
    return indexes;
}
int main(){
    string s = "ababcabcabababdabcabababd";
    string pat= "abababd";
    vector<int> indexes = kmpSearch(s, pat);
    for(auto i: indexes){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}