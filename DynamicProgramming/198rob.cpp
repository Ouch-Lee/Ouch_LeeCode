#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    vector<int> nums;
    string input;
    getline(cin, input);

    stringstream ss(input);  // 实例化ss，需要传参
    // 解析input
    string token;
    while(getline(ss, token, ','))
    {
        nums.push_back(stoi(token));
    }

    vector<int> dp(nums.size() , 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
        dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
    }
    for (int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
        // return dp[nums.size()];

}