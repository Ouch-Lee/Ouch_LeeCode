class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> theMap = {{nums[0], 0}};
        for (int i = 1; i < nums.size(); i++)
        {
            if (theMap.count(nums[i]))
            {
                if (abs(i - theMap[nums[i]]) <= k) return true;
                else theMap[nums[i]] = i;
            }
            theMap.insert({nums[i], i});
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0) return false; // k=0时无法满足i≠j且差≤0
        unordered_set<int> window; // 用unordered_set更高效
        
        for (int i = 0; i < nums.size(); ++i) {
            // 当前元素是否在窗口内存在重复？
            if (window.count(nums[i])) return true;
            
            window.insert(nums[i]);
            
            // 保持窗口大小不超过k
            if (i >= k) {
                window.erase(nums[i - k]);
            }
        }
        return false;
    }
};