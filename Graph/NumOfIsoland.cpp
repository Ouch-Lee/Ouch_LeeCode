#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

int dir[4][2] = {{1,0}, {0,-1}, {-1,0}, {0,1}}; 
// dfs 将与延边相连的岛都变成0
void dfs(vector<vector<int>> & grid, int x, int y)
{   
    grid[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int x_next = x + dir[i][0];
        int y_next = y + dir[i][1];
        if (x_next >= grid.size() || x_next < 0 || y_next >= grid[0].size() || y_next < 0) continue;
        if (grid[x_next][y_next] == 1) dfs(grid, x_next, y_next);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    cin.ignore();
    
    vector<vector<int>> grid(N, vector<int>(M,0));
    for (int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);
        istringstream iss(line);
        for (int j = 0; j < M; j++)
        {
            iss >> grid[i][j];
        }
    }
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (grid[i][0] == 1) dfs(grid, i, 0);
        if (grid[i][M-1] == 1) dfs(grid, i, M-1);
    }
    for (int j = 0; j < M; j++)
    {
        if (grid[0][j] == 1) dfs(grid, 0, j);
        if (grid[N-1][j] == 1) dfs(grid, N-1, j);
    }
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < M-1; j++)
        {
            if (grid[i][j] == 1) result++;
        }
    }
    cout << result;
    return 0;
}