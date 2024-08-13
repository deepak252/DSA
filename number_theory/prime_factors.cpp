#include <bits/stdc++.h>
#define show(a)         \
  for (auto itr : a)    \
    cout << itr << " "; \
  cout << endl;

using namespace std;

// vector<int> findAllPrimes(int num){
//   vector<bool> is_prime(num+1, true);
//   vector<int> primes;
//   int sqrt_num = sqrt(num);
//   for(int i=2;i<=sqrt_num;i++){
//     if(is_prime[i]){
//       for(int j=i*i;j<=num;j+=i){
//         is_prime[j] = false;
//       }
//     }
//   }
//   for(int i=2;i<=num;i++){
//     if(is_prime[i]) primes.emplace_back(i);
//   }
//   return primes;
// }

// vector<int> findAllPrimeFactors(int num){
//   vector<int> primes = findAllPrimes(num);
//   vector<int> prime_factors;
//   int sqrt_num = sqrt(num);
//   for(int i=0;i<primes.size();i++){
//     if(primes[i]>sqrt_num){
//       break;
//     }
//     if(num%primes[i] == 0){
//       prime_factors.emplace_back(primes[i]);
//     }
//   }
//   return prime_factors;
// }

vector<int> findAllPrimeFactors(int num)
{
  set<int> prime_factors;
  while (num % 2 == 0)
  {
    prime_factors.insert(2);
    num /= 2;
  }
  for (int i = 3; i <= sqrt(num); i = i + 2)
  {
    while (num % i == 0)
    {
      prime_factors.insert(i);
      num = num / i;
    }
  }
  if(num>2) prime_factors.insert(num);
  return vector<int>(prime_factors.begin(), prime_factors.end());
}

int main()
{
  auto prime_factors = findAllPrimeFactors(720720);
  show(prime_factors);
  return 0;
}