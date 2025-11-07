#include <bits/stdc++.h>

using namespace std;

/**
 * 1-Indexed Binary Indexed Tree (Fenwick Tree).
 * 
 * Purpose:
 * - Efficiently performs prefix sum queries and point updates in O(log n) time.
 * - Can be used for Range Queries.
 * - Supports operations on an array where:
 *     - update(i, x): Adds x to the element at index i.
 *     - query(i): Returns the sum of elements from index 1 to i.
 * 
 * Use Cases:
 * - Prefix sums
 * - Frequency counting
 */
class FenwickTree{
private:
    int n;
    vector<int> arr;

public:
    FenwickTree(int n){
        this->n = n + 1;
        arr.resize(n + 1);
    }

    void update(int i, int val) {
        if(i<=0){
            return;
        }
        while(i < n) {
            arr[i] += val;
            i += (i&-i);
        }
    }

    int queryPrefixSum(int i) {
        if(i<=0 || i>n){
            return 0;
        }
        int res = 0;
        while(i > 0) {
            res += arr[i];
            i -= (i&-i);
        }
        return res;
    }

    void showPrefixSum(){
        for(int i=1; i<=n; i++){
            cout<<queryPrefixSum(i)<<" ";
        }
        cout<<endl;
    }
};

int main() {
    FenwickTree ft = FenwickTree(10);
    // 1-indexed
    ft.update(6, 4);
    ft.showPrefixSum();
    ft.update(3, 5);
    ft.showPrefixSum();
    ft.update(3, -5);
    ft.showPrefixSum();
    ft.update(1, 2);
    ft.showPrefixSum();
    ft.update(10, 3);
    ft.showPrefixSum();


    // 0 0 0 0 0 4 4 4 4 4 4 
    // 0 0 5 5 5 9 9 9 9 9 9 
    // 0 0 0 0 0 4 4 4 4 4 4 
    // 2 2 2 2 2 6 6 6 6 6 6 
    // 2 2 2 2 2 6 6 6 6 9 9

    return 0;
}