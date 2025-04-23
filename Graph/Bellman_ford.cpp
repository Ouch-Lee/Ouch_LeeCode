#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main()
{
    int n, m, s, t, v;
    cin >> n >> m;
    vector<int> minDist(n+1, INT_MAX);
    vector<vector<int>> grid;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> t >> v;
        grid.push_back({s, t, v});
    }
    int start = 1;
    int end = n;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int from = grid[j][0];
            int to = grid[j][1];
            int val = grid[j][2];
            if (minDist[from] != INT_MAX) {
                minDist[to] = min(minDist[from], minDist[to] + val);
            }
        }
    }
    if (minDist[end] == INT_MAX) cout << "unconnected" << endl; // 不能到达终点
    else cout << minDist[end] << endl; // 到达终点最短路径
    return 0;
}