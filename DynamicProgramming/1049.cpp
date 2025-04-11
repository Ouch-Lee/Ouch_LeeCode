#include <iostream>
#include <stdlib.h>
#include <vector>
#include <numeric>
#include <string>
#include <sstream>

using namespace std;

int main() {
    vector<int> stones;
    string input;

    getline(cin, input);

    // 使用 stringstream 解析输入
    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
        // 将字符串转换为整数
        stones.push_back(stoi(token));
    }

    int weight = accumulate(stones.begin(), stones.end(), 0);
    int half_weight = weight/2;
    vector<int> dp(half_weight+1, 0);
    for (int i = 1; i < stones.size(); i++)
    {
        for (int j = half_weight; j >= stones[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    int left = weight - dp[half_weight] * 2;
    cout << left ;
    return 0;
}