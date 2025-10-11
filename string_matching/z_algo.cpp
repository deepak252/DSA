#include <bits/stdc++.h>
using namespace std;


// Z[i] = length of the longest substring starting at i that matches the prefix of the string.

vector<int> zFunction(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            int k = i - l;
            
            // Case 2: reuse the previously computed value
            z[i] = min(r - i + 1, z[k]);
        }

        // Try to extend the Z-box beyond r
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        // Update the [l, r] window if extended
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
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

    return 0;
}