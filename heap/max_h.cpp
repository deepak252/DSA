#include <bits/stdc++.h>

using namespace std;

class MaxH{
private:
    int size = 0;
    vector<int> arr;
public:
    void insert(int num){
        int n = size;
        arr.push_back(num);

        while(n){
            // Compare with parent
            if(arr[(n-1)/2] < arr[n]){
                swap(arr[(n-1)/2], arr[n]);
            }
            n = (n-1)/2;
        }

        size++;
    }

    void heapify(int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < size && arr[right] > arr[largest]){
            largest = right;
        }
        if(largest != i){
            heapify(largest);
        }

    }

    void remove(){
        arr[0] = arr[size-1];
        arr.pop_back();
        size--;
        heapify(0);
    }

    int top(){
        return arr[0];
    }
};


int main(){
    MaxH h = MaxH();
    h.insert(12);
    cout<<h.top()<<endl;
    return 0;
}