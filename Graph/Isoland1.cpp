#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>

using namespace std;

int dir[4][2] = {{1,0}, {0,-1}, {-1,0}, {0,1}}; 
void dfs(vector<vector<int>> & grid, vector<vector<bool>> &visited, int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) // 四个方向都搜一遍
    {
        int x_next = x + dir[i][0];
        int y_next = y + dir[i][1];
        if (x_next >= grid.size() || x_next < 0 || y_next >= grid[0].size() || y_next < 0) continue;
        // 如果查过了或者是海水直接跳过
        if (grid[x_next][y_next] == 1 && !visited[x_next][y_next])
        {
            visited[x_next][y_next] = true;
            dfs(grid, visited, x_next, y_next);
        }
        
    }
}


int main()
{
    int N, M; // N行M列
    cin >> N >> M;
    cin.ignore(); // 仅在此处跳过N/M后的换行符
    vector<vector<int>> grid(N, vector<int>(M,0));
    for (int i = 0; i < N; i++)
    {
        string line;
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
                // visited[i][j] = true;
                dfs(grid, visited, i, j);
            }
        }   
    }
    cout << result;
    return 0;
}