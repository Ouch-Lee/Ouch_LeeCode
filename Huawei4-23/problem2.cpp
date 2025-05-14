#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct  NodeState
{
    int idx;  // 对应数组位置
    int shift; // 偏移量
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> initial(n);
    vector<int> target(n);
    for (int &x : initial) cin >> x;
    for (int &x :target) cin >>x;

    auto colorVal = [](int c) ->int{
        return (c == 0) ? -1 : (c-1);
    };

    long long ans = 0;
    queue<NodeState> q;
    if (n > 0 && initial[0] != 0)
    {
        q.push({0, 0});
    }

    while (!q.empty())
    {
        NodeState cur = q.front();
        q.pop();

        int i = cur.idx;
        int sh = cur.shift;

        if (initial[i] == 0) continue;

        int initClr = colorVal(initial[i]); // 
        int targClr = colorVal(target[i]);

        int nowClr = (initClr + sh) % 3;
        int press = (targClr - nowClr + 3) % 3;

        ans += press;
        int newShift = (sh + press) % 3;

        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && initial[l] != 0) q.push({l, newShift});
        if (r < n && initial[r] != 0) q.push({r, newShift});
    }

    cout << ans << endl;
    return 0;
}
