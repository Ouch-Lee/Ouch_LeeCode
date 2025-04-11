#include <iostream>
#include <stdlib.h>
#include <vector>
#include <numeric>
#include <string>
#include <sstream>

using namespace std;
int main()
{
    int target;
    cin >> target;
    cin.ignore();

    vector<int> nums;
    string input;

    getline(cin, input);

    stringstream ss(input);
    string token;

    while(getline(ss, token, ','))
    {
        nums.push_back(stoi(token));
    }
    // cout << "target: " << target << endl; 
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i];
    // }
    // cout << endl;

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2 != 0) cout << 0;
    int left = (sum + target) / 2;
    vector<int> dp(left+1, 0);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = left; j >= nums[i]; j--)
        {
            dp[j] += dp[j-nums[i]];
        }
    }
    cout << dp[left];
    return 0;
}