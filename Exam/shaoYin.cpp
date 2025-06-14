#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 自定义比较函数
bool compare(const std::string& a, const std::string& b) {
    return a + b > b + a;  // 如果 a+b 大于 b+a，a 应该排在前面
}

std::string largestNumber(std::vector<int>& nums) {
    std::vector<std::string> strNums;
    
    // 将整数转换为字符串
    for (int num : nums) {
        strNums.push_back(std::to_string(num));
    }
    
    // 对字符串数组进行排序
    std::sort(strNums.begin(), strNums.end(), compare);
    
    // 如果最大的数字是 '0'，说明所有数字都是 0
    if (strNums[0] == "0") {
        return "0";
    }
    
    // 拼接所有字符串并返回
    std::string result;
    for (const std::string& numStr : strNums) {
        result += numStr;
    }
    
    return result;
}

int main() {
    // std::vector<int> nums = {3, 30, 34, 5, 9}; 
    std::vector<int> nums = {2,20,23,4,8};
    std::string result = largestNumber(nums);
    std::cout << "Largest number: " << result << std::endl;
    return 0;
}
