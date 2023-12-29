#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, int h, vector<int>& arr){
  n = arr.size();
  int ans = 0;
  int h2=h;
  for(int i=n-1;i>=0;i--){
    // cout<<"mi = "<<m<<", hi = "<<h2;
    if(arr[i]>h){
      ans=i+1;
      return ans;
    }
    if(arr[i]>h2){
      m--;
      if(m==0){
        return i+1;
      }
      h2=h;
      i++;
    }else{
      h2-=arr[i];
    }
    // cout<<"; mf = "<<m<<", hf = "<<h2<<endl;
    if(m<=0){
      ans=i+1;
      break;
    }
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
    int n,m,h;
    cin>>n>>m>>h;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int ans = solve(n,m,h,arr);
    cout<<ans<<endl;
  }

  return 0;
}
