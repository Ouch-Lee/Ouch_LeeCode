#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
int main()
{
    int M, N; // M 表示有M件材料；N表示空间最大值
    cin >> M >> N;
    vector<int> space(M);
    vector<int> value(N);
    for (int i = 0; i < M; i++) cin >> space[i];
    for (int j = 0; j < M; j++) cin >> value[j];

    vector<vector<int>> dp(M, vector<int>(N+1, 0));
    for (int i = 1; i < N + 1; i++)
    {
        if (i >= space[0]) dp[0][i] = value[0];
    }
    // 递推一下
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < N+1; j++)
        {
            if (j >= space[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-space[i]] + value[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[M-1][N];
    return 0;
}