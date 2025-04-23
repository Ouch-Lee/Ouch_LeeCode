#include <iostream>
#include <vector>

using namespace std;
int main()
{
    // input
    int N, M, u, v, w;
    cin >> N >> M;
    vector<vector<vector<int>>> grid(N+1, vector<vector<int>>(N+1, vector<int>(N+1, 10005)));
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        grid[u][v][0] = w;
        grid[v][u][0] = w;
    }

    // dp
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                grid[i][j][k] = min(grid[i][j][k-1], grid[i][k][k-1] + grid[k][j][k-1]);
            }
        }
    }
    int z, start, end;
    cin >> z;
    while (z--) {
        cin >> start >> end;
        if (grid[start][end][N] == 10005) cout << -1 << endl;
        else cout << grid[start][end][N] << endl;
    }
    return 0;
}