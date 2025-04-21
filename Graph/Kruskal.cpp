#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Edge
{
    int v1;
    int v2;
    int val;
};

// 节点数量
int n = 10001;
// 并查集标记节点关系的数组
vector<int> father(n, -1); // 节点编号是从1开始的，n要大一些

void init() {
    for (int i = 0; i < n; ++i) {
        father[i] = i;
    }
}

// 并查集的查找操作
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]); // 路径压缩
}

// 并查集的加入集合
void join(int u, int v) {
    u = find(u); // 寻找u的根
    v = find(v); // 寻找v的根
    if (u == v) return ; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
    father[v] = u;
}

int main()
{
    int V, E;
    int v1_, v2_, val_;
    int result = 0;
    cin >> V >> E;
    vector<Edge> edges;
    for (int i = 0; i < E; i++)
    {
        Edge edge;
        cin >> v1_ >> v2_ >> val_;
        edge.v1 = v1_;
        edge.v2 = v2_;
        edge.val = val_;
        edges.push_back(edge);
    }
    // 排序
    sort(edges.begin(), edges.end(), [](const Edge & e1, const Edge & e2){return e1.val < e2.val;});
    init();
    for (Edge edge : edges)
    {
        // 最短的
        int x = find(edge.v1);
        int y = find(edge.v2);

        if (x != y)
        {
            result += edge.val;
            join(x,y);
        }
    }
    cout << result << endl;
    return 0;
}

