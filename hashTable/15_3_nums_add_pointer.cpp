#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i = 0; nums[i] < 0 && i < len - 2; i++)
        {
            // 重复的直接跳过
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = len-1;
            while (left < right)
            {
                int tmpAdd = nums[i] + nums[left] + nums[right];
                if(tmpAdd > 0) 
                {
                    right--;
                }else if (tmpAdd < 0)
                {
                    left++;
                }else if (tmpAdd == 0)
                {
                    // 把这三个数存进去
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 处理重复的情况
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    right--;
                    left++;
                }
            }
            
        }
        return result;
    }    
};