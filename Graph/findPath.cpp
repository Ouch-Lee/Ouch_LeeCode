#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int N = 0;
vector<int> father(101, 0);
void init() {
    for (int i = 0; i < N; ++i) {
        father[i] = i;
    }
}

int find(int a)
{
    return a == father[a] ? a : father[a] = find(father[a]);
}

bool isSame(int u, int v)
{
    u = find(u);
    v = find(v);
    return u == v;
}

// 把u当成v的老爸
void join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return; // 已经是同一个爸了直接返回
    father[v] = u;
}

int main()
{
    int  M;
    cin >> N >> M;
    // cin.ignore(); 一次性输入不需要每次都忽略换行符
    // 初始化
    init();
    for (int i = 0; i < M; i++) // 循环次数应该是 M 而不是 N
    {
        int u, v;
        cin >> u >> v;
        join(u, v);
        // cin.ignore(); 一次性输入不需要每次都忽略换行符
    }
    int source , destination;
    cin >> source >> destination;
    // check一下
    if (isSame(source, destination)) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}