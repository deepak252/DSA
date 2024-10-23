#include <bits/stdc++.h>
using namespace std;

vector<int> rollingHash(string &str, string &pat){
    int n = str.size(), m = pat.size();
    vector<int> indices;
    if(n<m) return indices;

    long long MULTI = 26; 
    long long MOD = 1e9+7; // prime number
    long long mul = 1;
    long long str_hash = 0, pat_hash = 0;
    for(int i=m-1; i>=0; i--){
        pat_hash = (pat_hash + mul*(pat[i]-'a'+1))%MOD;
        str_hash = (str_hash + mul*(str[i]-'a'+1))%MOD;
        if(i>0) mul = (mul*MULTI)%MOD;
    }
    if(pat_hash == str_hash) indices.push_back(0);

    for(int i=m; i<n; i++){
        str_hash = (str_hash + MOD - (mul*(str[i-m]-'a'+1))%MOD)%MOD;    
        str_hash = (str_hash*MULTI + (str[i]-'a'+1))%MOD;  

        if(str_hash==pat_hash){
            indices.push_back(i-m+1);
        }  
    }

    return indices;

}
int main(){
    string s = "ababcabcabababdabcabababd";
    string pat= "abababd";
    vector<int> indexes = rollingHash(s, pat);
    for(auto i: indexes){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}