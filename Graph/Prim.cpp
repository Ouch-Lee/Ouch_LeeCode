#include <iostream>
#include <vector>
#define MAX_DIS 10001
#include <climits>

using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> grid(V + 1, vector<int>(V + 1, MAX_DIS));
    int v1, v2, val;
    
    for (int i = 0; i < E; i++)
    {
        cin >> v1 >> v2 >> val;
        grid[v1][v2] = val;
        grid[v2][v1] = val;
    }
    // 首先用什么数据结构存最小生成树？=> vector<bool> 判断是否在BSP里面
    vector<bool> isVisited(V+1, false);
    // 用一个minDistance 存每个节点离当前BSP最小的距离
    vector<int> minDistance(V+1, MAX_DIS);

    // 开始迭代
    for (int i = 1; i < V; i++)
    {
        // 找到离生成树最近的节点
        int cur = -1; // 选中哪个节点 加入最小生成树
        int minVal = INT_MAX;
        for (int j = 1; j <= V; j++) // 遍历没加过的节点，找到最小距离
        {
            if (!isVisited[j] && minDistance[j] < minVal)
            {
                minVal = minDistance[j];
                cur = j;
            }
        }
        // 加入最近节点
        isVisited[cur] = true;
        // 更新minDis
        for (int j = 1; j <= V; j++)
        {
            if (!isVisited[j] && grid[cur][j] < minDistance[j])
            {
                minDistance[j] = grid[cur][j];
            }
        }
    }
    int result = 0;
    for (int i = 2; i <= V; i++) { // 不计第一个顶点，因为统计的是边的权值，v个节点有 v-1条边
        result += minDistance[i];
    }
    cout << result << endl;
}