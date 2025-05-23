#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int integerBreak(int n) {
    vector<int> dp(n+1);
    dp[0]= 0;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= i/2; j++)
        {
            dp[i] = max(dp[i], max(j*dp[i-j], (i-j) * j));
        }
    }
    for (int i = 0; i < n+1; i++)
    {
        cout << dp[i] << " ";
    }
    cout << " ";
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    integerBreak(10);
    return 1;
}