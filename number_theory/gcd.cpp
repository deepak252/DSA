#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b,a%b);
}
//Iterative
int gcd2(int a, int b){
  while(b!=0){
    int temp = b;
    b = a%b;
    a = temp;
  }
  return a;
}

int main(){
  cout<<gcd2(12,18)<<endl;
  return 0;
}