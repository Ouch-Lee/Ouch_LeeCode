#include <iostream>
#include <stdlib.h>
#include <vector>
#include <numeric>

using namespace std;
int main()
{
    int N; // N表示数组长度
    cin >> N;
    vector<int> nums(N);
    for(int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }
    int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum/2;
        vector<int> dp(target+1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]);
            }
        }
        for(int i = 0; i < dp.size(); i++)
        {
            cout << dp[i] << " ";
        }
        if (dp[target] == target) return true;
        else return false;
}