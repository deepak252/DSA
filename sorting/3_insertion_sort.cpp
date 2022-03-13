#include<bits/stdc++.h>
using namespace std;

#include "../custom_headers/swap.h"
#include "../custom_headers/display.h"

typedef vector<int> VI;

void insertionSort(VI &arr){
    int l=arr.size();
    //  METHOD 1
    // for(int i=0;i<l-1;i++){
    //     int key=arr[i+1];
    //     for(int j=i;j>=0;j--){
    //         if(arr[j]>key ){
    //             arr[j+1]=arr[j];
    //             if(j==0){
    //                 arr[j]=key;
    //             }
    //         }else{
    //             arr[j+1]=key;
    //             break;
    //         }
    //     }
    // }

    //  METHOD 2

    for(int i=1;i<l;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    VI arr = {5, 3, 23, 6, 1};
    insertionSort(arr);
    display(arr);
}