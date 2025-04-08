#include <iostream>
#include <stdlib.h>

using namespace std;

// int fib(int n) {
//     if (n >= 2) return fib(n-1) + fib(n-2);
//     else return n; 
// }
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
}

int main()
{
    int input;
    cin >> input;
    cout << fib(input) << endl;
    return 0;
}

