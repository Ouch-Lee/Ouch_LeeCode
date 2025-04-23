#include <iostream>
#include <vector>
#include <climits> // 需要包含此头文件以使用INT_MAX

using namespace std;

int main() {
    int n, m, s, t;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<int> inDegree(n, 0); // 更改变量名以更清晰表示入度
    vector<int> result;

    for (int i = 0; i < m; i++) {
        cin >> s >> t;
        grid[s][t] = 1;
        inDegree[t]++;
    }

    for (int i = 0; i < n; i++) {
        // 找到当前入度为0的节点
        int cur = -1;
        for (int j = 0; j < n; j++) {
            if (inDegree[j] == 0) {
                cur = j;
                break;
            }
        }

        if (cur == -1) {
            cout << -1 << endl;
            return 0;
        }

        result.push_back(cur);
        inDegree[cur] = -1; // 标记为已处理

        // 更新所有邻接节点的入度
        for (int j = 0; j < n; j++) {
            if (grid[cur][j] == 1) {
                inDegree[j]--;
            }
        }
    }

    if (result.size() == n) {
        for (int i = 0; i < n - 1; i++) cout << result[i] << " ";
        cout << result[n - 1];
    } else cout << -1 << endl;
    return 0;
}