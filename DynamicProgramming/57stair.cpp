#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
using namespace std; 

int main()
{
    int n, m;
    cin >> n >> m;
    if (m >= n) 
    {
        cout << "what are doing man?" << endl;
        return 0;
    }
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i >= j) dp[i] += dp[i - j];
        }
    }
    cout << dp[n] << endl;
    // return dp[n];
    return 0;
}