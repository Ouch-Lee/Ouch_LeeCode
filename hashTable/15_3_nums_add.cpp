#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            unordered_set<int> tmpset;
            for(int j = i+1; j < nums.size(); j++)
            {
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])
                    continue;
                int target = -nums[i] - nums[j]; // 要在set中找的值
                if(tmpset.find(target) != tmpset.end())
                {
                    // 有
                    vector<int> tmpvec = {nums[i], target, nums[j]};
                    result.push_back(tmpvec);
                    tmpset.erase(target);
                }else
                {
                    tmpset.insert(nums[j]);
                }
            }
        }
        return result;
    }
};