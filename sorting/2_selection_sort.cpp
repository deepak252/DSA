#include<bits/stdc++.h>

using namespace std;
#include "../custom_headers/swap.h"
#include "../custom_headers/display.h"
typedef vector<int> VI;


// SELECT MINIMUM ELEMENT AND PLACE AT BEGINING OF ARRAY (OR SUBARRAY)
void selectionSort(VI &arr){
    int l=arr.size();
    for(int i=0;i<l;i++){
        int min_pos = i;
        for(int j=i+1;j<l;j++){
            if(arr[j]<=arr[min_pos]){
                min_pos=j;
            }
        }
        swap(arr[i],arr[min_pos]);
    }
}

int main(){
    VI arr = {5, 3, 23, 6, 1};
    selectionSort(arr);
    display(arr);
    
}