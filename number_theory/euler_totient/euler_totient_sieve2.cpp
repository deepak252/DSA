#include <bits/stdc++.h>

using namespace std;
// Efficient when we need totient values for all numbers [1 to n]
// The Euler Totient Function φ(n) counts how many integers in [1,n] are coprime (i.e. gcd = 1) with n.
// phi(n) = n*(1 - 1/p1)*(1 - 1/p2)*....*(1 - 1/pk)


vector<int> computeTotients(int n){
    vector<int> phi(n+1);

    for(int i=1; i<=n; ++i){
        phi[i] = i;
    }

    // Process all primes
    for (int p = 2; p <= n; p++) {
        if (phi[p] == p) { // p is prime
            // Apply formula for all multiples of p
            for (int j = p; j <= n; j += p) {
                phi[j] -= phi[j] / p;
            }
        }
    }

    // for(int p=2; p<=n; ++p){
    //     if(phi[p]==p){
    //         phi[p] = p-1;
    //         for(int j=2*p; j<=n; j+=p){
    //             phi[j]-=phi[j]/p;
    //         }
    //     }
    // }

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