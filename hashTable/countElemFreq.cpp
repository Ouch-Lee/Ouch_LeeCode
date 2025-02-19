#include <iostream>
#include <vector>
#include <unordered_map>

void countElements(const std::vector<int>& nums) {
    std::unordered_map<int, int> countMap;  // 键是数组元素，值是出现次数

    // 遍历数组，统计每个元素的出现次数
    for (int i = 0; i < nums.size(); i++) {
        countMap[nums[i]]++;  // 如果键不存在，会自动初始化为0，然后加1
    }

    // 输出统计结果
    std::cout << "Element counts:" << std::endl;
    for (const auto& pair : countMap) {
        std::cout << "Element " << pair.first << " appears " << pair.second << " times." << std::endl;
    }
}

int main() {
    std::vector<int> nums = {-1,-1,-5,-5,-5,1, 1, 1, 2, 2, 3};  // 示例数组
    countElements(nums);  // 调用函数统计元素出现次数
    return 0;
}