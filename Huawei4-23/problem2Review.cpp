#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NodeState
{
    int idx;
    int shift;
};

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> inital(n);
    vector<int> traget(n);
    for (int &x : inital) cin >> x;
    for (int &y : traget) cin >> y;

    // 将颜色映射左移一位，便于循环
    auto colorVal = [] (int c) -> int {
        return (c == 0) ? -1 : (c - 1);
    };

    long result = 0;

    // 构建队列进行层序遍历
    queue<NodeState> que;
    if (n > 0 && inital[0] != 0) 
    {
        que.push({0, 0});
    }

    while (!que.empty())
    {
        
    }
    
    return 0;
}