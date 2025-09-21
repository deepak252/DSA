#include <bits/stdc++.h>

using namespace std;

class MaxHeap{
private:
    vector<int> arr; // 0 indexed
public:
    int size(){
        return arr.size();
    }

    int top(){
        if(arr.empty()){
            return 0;
        }
        return arr[0];
    }

    void push(int num){
        int i = arr.size();
        arr.push_back(num);
        while(i > 0){
            if(arr[(i-1)/2] < arr[i]){
                swap(arr[(i-1)/2], arr[i]);
            }
            i = (i-1)/2;
        }
    }

    void heapify(int i){
        int maximum = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < arr.size() && arr[left] > arr[maximum]){
            maximum = left;
        }
        if(right < arr.size() && arr[right] > arr[maximum]){
            maximum = right;
        }
        if(maximum != i){
            swap(arr[maximum], arr[i]);
            heapify(i);
        }
    }

    void pop(){
        arr[0] = arr.back();
        arr.pop_back();
        if(arr.size() > 1){
            heapify(0);
        }
    }

};

int main(){
    MaxHeap heap = MaxHeap();

    int nums[] = {5, 12, 8, 20};

    for(auto num: nums){
         heap.push(num);
    }

    cout<<"Top: "<<heap.top()<<" "<<"Size: "<<heap.size()<<endl;
    while(heap.size()){
        cout<<heap.top()<<" ";
        heap.pop();
    }
    cout<<endl;
    // OUTPUT:
    // Top: 20 Size: 4
    // 20 12 8 5

    return 0;
}