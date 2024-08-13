#include <bits/stdc++.h>
#define show(a)             \
    for (auto itr : a)      \
        cout << itr << " "; \
    cout << endl;

using namespace std;

/**
 * Sieve of Eratosthenes:
 * all prime numbers <= num
*/
vector<int> findAllPrimes(int num){
  vector<bool> is_prime(num+1, true);
  vector<int> primes;
  for(long i=2;i*i<=num;i++){
    if(is_prime[i]){
      for(int j=i*i;j<=num;j+=i){
        is_prime[j]=false;
      }
    }
  }
  for(int i=2;i<=num;i++){
    if(is_prime[i]){
      primes.push_back(i);
    }
  }
  return primes;
}

int main(){
  vector<int> primes = findAllPrimes(sqrt(100000));
  cout<<primes.size()<<endl;
  show(primes);
  return 0;
}