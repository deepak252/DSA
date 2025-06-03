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
    int size = 0;
    vector<int> arr;
public:
    FenwickTree(int n){
        size = n;
        arr.resize(n+1, 0);
    }

    void update(int i, int num){
        if(i<=0 || i>size){
            return;
        }
        while(i<=size){
            arr[i]+=num;
            i+=(i&-i);
        }
    }

    int query(int i){
        if(i<=0 || i>size){
            return 0;
        }
        int sum = 0;
        while(i>0){
            sum+=arr[i];
            i-=(i&-i);
        }
        return sum;
    }
    void showPrefixSum(){
        for(int i=1; i<=size; i++){
            cout<<query(i)<<" ";
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

    return 0;
}