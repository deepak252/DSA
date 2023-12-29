#include <bits/stdc++.h>
#define show(a)             \
    for (auto itr : a)      \
        cout << itr << " "; \
    cout << endl;

using namespace std;

vector<int> findAllFactors(int num){
  vector<int> factors;
  int sqrt_num = sqrt(num);
  for(int i=1;i<=sqrt_num;i++){
    if(num%i==0){
      factors.emplace_back(i);
      if(num/i!=i){
        factors.emplace_back(num/i);
      }
    }
  }
  return factors;
}

int main(){
  vector<int> factors = findAllFactors(25);
  show(factors);
  return 0;
}