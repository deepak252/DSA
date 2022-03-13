#include <bits/stdc++.h>

using namespace std;
typedef vector<int> VI;

void swap1(int &a, int &b)
{
    a = (b + a) - (b = a);
}

void swap2(int * a,int * b){
    *a = (*b+*a)-(*b=*a);
}

int main()
{
    VI arr = {5, 3, 23, 6, 1};
    swap1(arr[0], arr[2]);
    swap2(&arr[0], &arr[2]);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}