#include <bits/stdc++.h>

using namespace std;

/**
 * check a number is prime or not
*/
bool isPrime(int num){
  if(num<2) return false;
  int sqrt_n = sqrt(num);
  for(int i=2;i<=sqrt_n;i++){
    if(num%i==0){
      return false;
    }
  }
  return true;
}

int main(){
  cout<<isPrime(13)<<endl;
  return 0;
}