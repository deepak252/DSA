#include <bits/stdc++.h>

using namespace std;

int solve(int e, int n, vector<int> &arr)
{
  sort(arr.begin(), arr.end(), greater<int>());
  int ans = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (e > 0)
    {
      e -= arr[i];
      ans++;
    }
    if (e > 0)
    {
      e -= arr[i];
      ans++;
    }
  }

  return e > 0 ? -1 : ans;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  cin >> t;
  while(t--)
  {
    int e,n;
    cin>>e>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int ans = solve(e,n,arr);
    cout<<ans<<endl;
  }

  return 0;
}