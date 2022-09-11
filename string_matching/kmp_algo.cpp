#include <iostream>
#include<vector>
using namespace std;

// Prefix
void genereateLPS(string &pat, vector<int> &lps){
    int n=pat.length();
    int j=0;
    lps[0]=0;
    for(int i=1;i<n;i++){
        if(pat[i]==pat[j]){
            j++;
            lps[i]= j;
        }else{
            if(j>0){
                j=lps[j-1];
                i--;
            }else{
                lps[i] = 0;
            }
        }
    }
}


int kmpMatch(string &str, string &pat){
    int n = str.length();
    int m=pat.length();
    // m<=n
    vector<int> lps(m);
    genereateLPS(pat,lps);
    int j=0;
    for(int i=0;i<n;i++){
        if(str[i]==pat[j]){
            j++;
            if(j==m){
                return i-j+1; //found
            }
        }else{
            if(j>0){
                j=lps[j-1];
                i--;
            }
        }
    }
    return -1; // not found
}

int main(){
    string str = "abcdabcabce";
    string pat= "abce";
    cout<<kmpMatch(str,pat)<<endl;   
}