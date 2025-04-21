#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int N = 0;
vector<int> father(101, 0);
void init() {
    for (int i = 0; i <= N; ++i) {
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

int main() {
    int s, t;
    cin >> N ;
    init();
    for (int i = 0; i < N; i++) {
        cin >> s >> t;
        if (isSame(s, t)) {
            cout << s << " " << t << endl;
            return 0;
        } else {
            join(s, t);
        }
    }
}