// Uses recursive pattern with memoization
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> VI;

int dp[1000][1001];

void showdp(int, int);

int knapsack(VI price, VI weight, int W,int n){
    if(n==0 || W==0) return 0;
    if (dp[n][W]!=-1) return dp[n][W]; 
    if(weight[n-1]<W){
        return dp[n][W] = max(price[n-1]+knapsack(price, weight, W - weight[n - 1], n-1), knapsack(price, weight, W, n-1));
    }else{
        return dp[n][W] = knapsack(price, weight, W, n - 1);
    }
    // return dp[n][W];
}

int main(){
    memset(dp,-1,sizeof(dp));
    VI weight = {1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5};
    VI price = {1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7};
    int W = 200;
    // VI weight = {1, 3, 4, 5};
    // VI price = {1, 4, 5, 7};
    // int W = 8;
    knapsack(price, weight, W, weight.size());
    cout << dp[weight.size()][W] << endl;

    // showdp(weight.size() + 1, W + 1);

}

void showdp(int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}