#include <bits/stdc++.h>
using namespace std;

#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define cases(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define show(a)             \
    for (auto itr : a)      \
        cout << itr << " "; \
    cout << endl;
#define debugln(x) cerr << #x << " = " << x << endl;
#define debug(x) cerr << #x << " = " << x << "  ";

#define endl "\n"
#define largest 1e18

typedef long long int lli;
typedef long double ld;
typedef vector<int> VI;

void solve(int t){
    
}

int main()
{
    fastIO;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }

    // auto start = chrono::high_resolution_clock::now();
    
    // bool is_prime = isPrime(num);

    // auto end = chrono::high_resolution_clock::now();

    // chrono::duration<double, milli> duration = end - start;

    // cout<<is_prime<<endl;
    // cout << "Execution time: " << duration.count() << " ms\n"; // 117.416 ms
}