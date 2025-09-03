#include<bits/stdc++.h>

using namespace std;

// Count prime numbers upto n
int countPrimes(int n){
    if(n<2){
        return 0;
    }
    vector<bool> sieve(n+1, true);
    for(long long i=3; i*i<=n; i+=2){
        if(sieve[i]){
            for(long long j=i*i; j<=n; j+=2*i){
                sieve[j] = false;
            }
        }
    }
    int res = 1;
    for(int i=3; i<=n; i+=2){
        res+=sieve[i];
    }
    return res;
}

int main(){
    cout<<countPrimes(2)<<endl;
    cout<<countPrimes(3)<<endl;
    cout<<countPrimes(4)<<endl;
    cout<<countPrimes(5)<<endl;
    return 0;
}