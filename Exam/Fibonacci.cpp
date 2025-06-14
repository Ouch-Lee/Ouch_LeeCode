#include <iostream>
using namespace std;

// 函数定义：根据给定的前两项和n返回斐波那契数列的第n项
int ccinabofi(int a1, int a2, int n) {
    if (n == 1) return a1;  // 返回第 1 项
    if (n == 2) return a2;  // 返回第 2 项
    
    int prev1 = a1;  // 第 1 项
    int prev2 = a2;  // 第 2 项
    int current = 0;

    // 从第 3 项开始计算
    for (int i = 3; i <= n; ++i) {
        current = prev1 - prev2;  // 根据公式 F(n) = F(n-1) - F(n-2)
        prev1 = prev2;  // 更新前一项
        prev2 = current;  // 更新当前项
    }

    return current;
}

int main() {
    // 测试样例
    int a1 = 13, a2 = 8;

    // 输入n，计算斐波那契数列的第n项
    for (int n = 1; n <= 8; ++n) {
        cout << "n = " << n << ", ccinabofi(" << a1 << ", " << a2 << ", " << n << ") = " << ccinabofi(a1, a2, n) << endl;
    }

    return 0;
}
