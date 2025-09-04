#include <bits/stdc++.h>

using namespace std;
// The Euler Totient Function φ(n) counts how many integers in [1,n] are coprime (i.e. gcd = 1) with n.
// phi(n) = n*(1 - 1/p1)*(1 - 1/p2)*....*(1 - 1/pk)

int phi(int n){
    int res = n;
    
    for(int p=2; p*p<=n; ++p){
        // If p divides n, then p is a prime factor
        if(n%p==0){
            // Remove ALL factors of p from n (divide until it's no longer divisible)
            while(n%p==0){
                n/=p;
            }
            // Apply the formula: res *= (1 - 1/p) => res -= res/p
            res-=res/p;
        }
    }

    // If n > 1 here, then whatever remains is a prime > sqrt(original n)
    if(n>1){
        res-=res/n;
    }

    return res;
}

int main(){
    for(int i=1; i<=100; ++i){
        cout<<i<<" "<<phi(i)<<endl;
    }
    return 0;
}

