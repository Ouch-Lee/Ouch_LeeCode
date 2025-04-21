#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N + 1, vector<int>(N + 1, INT_MAX));
    int v1, v2, val;
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2 >> val;
        grid[v1][v2] = val;
    }

    vector<int> minDist(N+1, INT_MAX);
    vector<bool> isVisited(N+1, false);
    minDist[1] = 0;
    for (int i = 1; i <= N; i++) 
    {
        // 挑选没访问过且离源点最近的点
        int cur = -1;
        int minDis = INT_MAX;
        for (int j = 1; j <= N; j++)
        {
            if(!isVisited[j] && minDist[j] < minDis)
            {
                cur = j;
                minDis = minDist[j];
            }
        }
        // sign
        isVisited[cur] = true;
        // 更新minDist, 也即相邻点的距离
        for (int j = 1; j <= N; j++)
        {
            if (!isVisited[j] && grid[cur][j] != INT_MAX && grid[cur][j] + minDist[cur] < minDist[j])
            {
                minDist[j] = grid[cur][j] + minDist[cur];
            }
        }
    }
    if (minDist[N] == INT_MAX) cout << -1 << endl; // 不能到达终点
    else cout << minDist[N] << endl; // 到达终点最短路径
    return 0;
}