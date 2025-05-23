#include <bits/stdc++.h>

using namespace std;

// class FenwickTree{
// private: 
//     int n;
//     vector<int> arr;
// public:
//     FenwickTree(int size){
//         this->n = size+1;
//         arr.resize(size+1);
//     }

//     void add(int i, int num){
//         if(i<=0 || i>=n) return;
//         while(i<n){
//             arr[i]+=num;
//             i=i+(i&(-i));
//         }
//     }

//     // Get sum from index 0 to i
//     int sum(int i){
//         if(i>=n || i<0) return -1;
//         int sum = 0;
//         while(i>0){
//             sum+=arr[i];
//             i=i-(i&(-i));
//         }
//         return sum;
//     }

//     void show(){
//         for(auto num: arr) cout<<num<<" ";
//         cout<<endl;
//     }

//     void showPrefixSum(){
//         for(int i=1; i<n; i++){
//             cout<<this->sum(i)<<" ";
//         }
//         cout<<endl;
//     }
// };

class FenwickTree{
private: 
    int n;
    // 1-index arr
    vector<int> arr;
public:
    FenwickTree(int size){
        this->n = size;
        arr.resize(size+1);
    }

    void add(int i, int num){
        while(i<=n){
            arr[i]+=num;
            i=i+(i&(-i));
        }
    }

    // Get sum from index 0 to i
    int sum(int i){
        int sum = 0;
        while(i>0){
            sum+=arr[i];
            i=i-(i&(-i));
        }
        return sum;
    }

    void show(){
        for(auto num: arr) cout<<num<<" ";
        cout<<endl;
    }

    void showPrefixSum(){
        for(int i=1; i<=n; i++){
            cout<<this->sum(i)<<" ";
        }
        cout<<endl;
    }
};

int main() {
    int n = 7;
    FenwickTree ft = FenwickTree(n);
    // 1-indexed
    ft.add(6, 4);
    ft.showPrefixSum();
    ft.add(3, 5);
    ft.showPrefixSum();
    ft.add(3, 5);
    ft.showPrefixSum();
    ft.add(1, 2);
    ft.showPrefixSum();
    ft.add(7, 3);
    ft.showPrefixSum();

    return 0;
}