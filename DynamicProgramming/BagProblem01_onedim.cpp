#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
int main()
{
    int M, N; // M 表示有M件材料；N表示空间最大值
    cin >> M >> N;
    vector<int> space(M);
    vector<int> value(M);
    for (int i = 0; i < M; i++) cin >> space[i];
    for (int j = 0; j < M; j++) cin >> value[j];

    // 初始化dp
    vector<int> dp(N+1, 0);
    for (int j = space[0]; j <= N; j++) dp[j] = value[0];

    // 递推
    for (int i = 0; i < M; i++)
    {
        for (int j = N; j >= space[i]; j--)
        {

                dp[j] = max(dp[j], dp[j-space[i]] + value[i]);
        }
    }


    // for (int i = 0; i < N+1; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[N] << endl;

    return dp[N];
}