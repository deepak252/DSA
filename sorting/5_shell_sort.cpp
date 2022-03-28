#include<bits/stdc++.h>

using namespace std;

#include "../custom_headers/swap.h"
#include "../custom_headers/display.h"

typedef vector<int> VI;

void shellSort(VI &arr){
    int n = arr.size();
    int gap = n/2;
    while(gap>0){
        for(int i=0;i+gap<n;i++){
            if(arr[i]>arr[i+gap]){
                swap(arr[i], arr[i+gap]);
                int j=i;
                while(j-gap>=0 && arr[j]<arr[j-gap]){
                    swap(arr[j-gap], arr[j]);
                    j-=gap;
                }

            }
        }
        gap/=2;
    }
}

int main(){
    VI arr = {10, 1, 20, 25, 4, 5, 22, 9, 12, 12, 10};
    shellSort(arr);
    display(arr);
}