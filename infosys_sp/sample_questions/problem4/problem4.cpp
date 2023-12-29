
#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int>& arr){
  n = arr.size();
  map<int,int> count_hash;
  int mid = (n-1)/2;
  
  for(int i=0;i<mid;i++){
    count_hash[arr[i]-i]++;
    count_hash[arr[n-1-i]-i]++;
  }
  count_hash[arr[mid]-mid]++;
  if(!(n&1)){
    count_hash[arr[mid+1]-mid]++;
  }

  // for(auto h: count_hash){
  //   cout<<h.first<<" "<<h.second<<endl;
  // }
  // cout<<endl;
  return n-count_hash.begin()->second;
}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int ans = solve(n,arr);
    cout<<ans<<endl;
  }

  return 0;
}