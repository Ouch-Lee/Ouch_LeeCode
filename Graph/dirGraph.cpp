#include <iostream>
#include <stdlib.h>
#include <vector>
// #include <>

using namespace std;

void dfs(const vector<vector<int>> &graph, vector<bool> &visited, int key)
{
    visited[key] = true;
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[key][i] == 1 && !visited[i])
        {
            dfs(graph, visited, i);
        } 
    }
    return;
}
int main()
{
    // input
    int N, K;
    cin >> N >> K;
    cin.ignore();
    vector<vector<int>> graph(N, vector<int>(N, 0));
    int x, y;
    for (int i = 0; i < K; i++)
    {
        cin >> x >> y;
        graph[x-1][y-1] = 1; 
        cin.ignore();
    }
    vector<bool> visited(N, false);
    // 从1开始遍历，找到所有能去的路，进行dfs
    dfs(graph, visited, 0);
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == false)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}