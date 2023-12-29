
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b,a%b);
}

int solve(string s){
  vector<int> char_count(26);
  int ans = 0;
  for(char c: s){
    char_count[c-'a']++;
  }

  for(int i=0;i<26;i++){
    ans = gcd(ans, char_count[i]);
  }
  return ans;

}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  cin >> t;
  while(t--)
  {
    string s;
    cin>>s;
    int ans = solve(s);
    cout<<ans<<endl;
  }

  return 0;
}