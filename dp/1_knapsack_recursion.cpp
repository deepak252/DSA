//** 0-1 Knapsack problem ***//

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> VI;

int knapsack(VI price, VI weight, int W,int n){ //W=capacity of bag
    if(W==0 || n==0){
        return 0;
    }
    if(weight[n-1]<=W){
        return max(price[n-1]+knapsack(price, weight, W - weight[n - 1], n - 1), knapsack(price, weight, W, n - 1));
    }else{
        return knapsack(price, weight, W, n - 1);
    }
}

int main(){
    // VI weight = {1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5};
    // VI price = {1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7};
    VI weight = {1, 3, 4, 5};
    VI price = {1, 4, 5, 7};
    int W=8;
    int max_profit=knapsack(price,weight,W,weight.size());
    cout<<max_profit<<endl;
}