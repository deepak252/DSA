#include<bits/stdc++.h>

using namespace std;
// Prime Factorization of all the numbers upto n

vector<int> preCompute(int n){
    vector<int> sieve(n+1); // Stores Smallest Prime Factor
    for(int i=2; i<=n; i++){
        if(sieve[i]){
            continue;
        }
        for(int j=i; j<=n; j+=i){
            if(!sieve[j]){
                sieve[j] = i;
            }
        }
    }
    return sieve;
}

vector<vector<int>> allPrimeFactorsUpTo(int n){
    vector<vector<int>> factors(n+1);
    vector<int> sieve = preCompute(n);

    for(int i=2; i<=n; i++){
        int x = i;
        while(x>1){ // (log n)
            factors[i].push_back(sieve[x]); // push smallest prime factor
            x/=sieve[x];
        }
    }
    return factors;
}

int main(){
    int n = 100;
    vector<vector<int>> factors = allPrimeFactorsUpTo(n);

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
// 1: 
// 2: 2 
// 3: 3 
// 4: 2 2 
// 5: 5 
// 6: 2 3 
// 7: 7 
// 8: 2 2 2 
// 9: 3 3 
// 10: 2 5 
// 11: 11 
// 12: 2 2 3 