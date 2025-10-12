#include <bits/stdc++.h>
using namespace std;


// Z[i] = length of the longest substring starting at i that matches the prefix of the string.
vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}


int main() {
    string s = "aabxaabxcaabxaabxay";
    vector<int> Z = zFunction(s);

    cout << "Z-array:\n";
    for (int z : Z) cout << z << " ";
    cout << endl;
    // 0 1 0 0 4 1 0 0 0 8 1 0 0 5 1 0 0 1 0

    return 0;
}