void showdp(int dp[][1001], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}