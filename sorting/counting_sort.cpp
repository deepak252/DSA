#include<bits/stdc++.h>

using namespace std;

#include "../custom_headers/swap.h"
#include "../custom_headers/display.h"

typedef vector<int> VI;

void countingSort(VI &arr){
    int max = 0;
    int n = arr.size();
    VI sorted_arr(n);
    for(int i=0;i<n;i++){
        if(max<arr[i]) max = arr[i];
    }
    VI count(max+1,0);
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<count.size();i++){
        count[i] +=count[i-1];
    }
    display(count);

    for(int i =n-1;i>=0;i--){
        sorted_arr[--count[arr[i]]] = arr[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = sorted_arr[i];
    }
    display(count);
    display(sorted_arr);
}

int main(){
    // VI arr = {10, 1, 20, 25, 4, 5, 22, 9, 12, 12, 10};
    VI arr = {3,3,1,5,5,1};
    countingSort(arr);
    display(arr);
}