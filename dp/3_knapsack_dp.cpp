// Iterative approach with tabulation
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> VI;

int dp[1000][1001];

void showdp(int,int);

int knapsack(VI price, VI weight, int W,int n){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(weight[i-1]<=j){
                dp[i][j] = max(price[i - 1] + dp[i-1][j - weight[i - 1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}


int main(){
    cout<<INT_MAX<<endl;
    memset(dp,0,sizeof(dp));
    VI weight = {1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5, 1, 3, 4, 5};
    VI price = {1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7, 1, 4, 5, 7};
    int W = 200;
    // VI weight = {1, 3, 4, 5};
    // VI price = {1, 4, 5, 7};
    // int W = 7;
    int max_profit = knapsack(price, weight, W, weight.size());
    cout << max_profit << endl;

    // showdp(weight.size()+1, W+1);

    
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