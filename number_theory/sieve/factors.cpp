#include<bits/stdc++.h>

using namespace std;
// All factors of all the numbers upto n

vector<vector<int>> allFactors(int n){
    vector<vector<int>> factors(n+1);

    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            factors[j].push_back(i);
        }
    }
    return factors;
}

int main(){
    int n = 100;
    vector<vector<int>> factors = allFactors(n);

    for(int i=0; i<=n; i++){
        cout<<i<<": ";
        for(auto f: factors[i]){
            cout<<f<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// OUTPUT
// 0: 
// 1: 1 
// 2: 1 2 
// 3: 1 3 
// 4: 1 2 4 
// 5: 1 5 
// 6: 1 2 3 6 
// 7: 1 7 
// 8: 1 2 4 8 
// 9: 1 3 9 
// 10: 1 2 5 10 
// 11: 1 11 
// 12: 1 2 3 4 6 12 