#include <iostream>

using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    int dp[2] = {0,1};
    for (int i = 2; i <= n; i++)
    {
        int sum = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = sum;
    } 
    return dp[1];
};
