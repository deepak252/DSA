#include<bits/stdc++.h>

using namespace std;
#include "../custom_headers/swap.h"
#include "../custom_headers/display.h"
typedef vector<int> VI;

void bubbleSort(VI &arr)
{
    int l=arr.size();
    // for(int i=0;i<l;i++){
    //     for(int j=0;j<l-1;j++){
    //         if(arr[i]<arr[j])
    //             swap(arr[i], arr[j]);
    //     }
    // }
    for(int i=0;i<l;i++){
        for(int j=1;j<l-i;j++){
            if(arr[j]<arr[j-1])
                swap(arr[j],arr[j-1]);
        }
    }
}

int main(){
    VI arr = {5,3,23,6,1};
    bubbleSort(arr);
    display(arr);
    
}