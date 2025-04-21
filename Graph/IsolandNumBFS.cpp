#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void bfs(vector<vector<int>> & grid, vector<vector<bool>> &visited, int x, int y)
{
    // 新建一个栈用来放当前节点的坐标
    queue<pair<int, int>> que;
    que.push({x,y});
    visited[x][y] = true;
    while (!que.empty())
    {
        pair<int, int> cur_cordinate = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextx = cur_cordinate.first + dir[i][0];
            int nexty = cur_cordinate.second+ dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // 越界了，直接跳过
            if (grid[nextx][nexty] == 1 && !visited[nextx][nexty])
            {
                que.push({nextx, nexty});
                visited[nextx][nexty] = true;
            }
        }
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M,0));
    for (int i = 0; i < N; i++)
    {
        string line;
        cin.ignore();
        getline(cin, line);
        istringstream iss(line);
        for (int j = 0; j < M; j++)
        {
            iss >>grid[i][j];
        }
    }
    int result = 0;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    // 遍历grid
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1) // 没标记过的大陆，且
            {
                result++;
                bfs(grid, visited, i, j);
            }
        }   
    }
    cout << result;
    return 0;
}