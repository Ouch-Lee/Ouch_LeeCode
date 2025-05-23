#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left, right;
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] >= 0) break;
            cout << "i: " << i << endl;
            left = i + 1;
            right = n - 1;
            int tmpTarget = -nums[i];
            while (left < right)
            {
                int tmpSum = nums[left] + nums[right];
                if (tmpSum > tmpTarget) right--;
                else if (tmpSum < tmpTarget) left++;
                else if (tmpSum == tmpTarget) 
                {
                    vector<int> tmpRsult = {nums[i], nums[left], nums[right]};
                    result.push_back(tmpRsult);
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                    continue;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<vector<int>> result = solution.threeSum(nums);
    
    cout << "Result: " << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i != triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
