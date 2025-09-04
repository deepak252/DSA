#include <bits/stdc++.h>

using namespace std;
// Efficient when we need totient values for all numbers [1 to n]
// The Euler Totient Function φ(n) counts how many integers in [1,n] are coprime (i.e. gcd = 1) with n.
// phi(n) = n*(1 - 1/p1)*(1 - 1/p2)*....*(1 - 1/pk)

vector<int> generateSieve(int n){
    vector<int> sieve(n+1); // stores Smallest Prime Factor (SPF)
    
    for(int i=2; i<=n; ++i){
        if(sieve[i]==0){
            for(int j=i; j<=n; j+=i){
                sieve[j] = i;
            }
        }
    }
    return sieve;
}


vector<int> computeTotients(int n){
    vector<int> sieve = generateSieve(n);
    vector<int> phi(n+1);

    for(int i=1; i<=n; ++i){
        int j = i;
        int res = j;
        int p = 0;
        while(j>1){
            if(p!=sieve[j]){
                res-=res/sieve[j];
                p = sieve[j];
            }
            j/=sieve[j];
        }
        phi[i] = res;
    }
    return phi;
}

int main(){
    int n = 100;
    vector<int> phi = computeTotients(n);
    for(int i=1; i<=n; ++i){
        cout<<i<<" "<<phi[i]<<endl;
    }
    return 0;
}
