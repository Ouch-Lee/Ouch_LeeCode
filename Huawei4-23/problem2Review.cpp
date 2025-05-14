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
        // 获取当前节点
        NodeState cur = que.front();
        que.pop();
        // 当前节点颜色，及其目标颜色
        int id = cur.idx;
        int sh = cur.shift;
        int initClr = colorVal(inital[id]);
        int tarClr = colorVal(traget[id]);

        // 经过sh后颜色变为
        int nowClr = (initClr + sh) % 3;
        int press = (tarClr - nowClr + 3) % 3;

        result += press;
        int newShift = (sh + press) % 3;
        // 处理子节点
        int left_id = 2 * id + 1; int right_id = 2 * id + 2;
        NodeState leftNode = {left_id, newShift};
        NodeState rightNode = {right_id, newShift};
        if (left_id < n && inital[left_id] != 0) que.push(leftNode);
        if (right_id < n && inital[right_id] != 0) que.push(rightNode);
    }
    cout << result << endl;
    return 0;
}