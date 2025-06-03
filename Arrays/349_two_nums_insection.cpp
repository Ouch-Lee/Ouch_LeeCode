#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1;
    unordered_set<int> set2;
    vector<int> result;

    // 将nums1和nums2的元素分别插入到set1和set2中
    for (int n : nums1) set1.insert(n);
    for (int n : nums2) set2.insert(n);

    // 通过遍历set1来查找两集合的交集
    for (int n : set1) {
        if (set2.count(n)) {
            result.push_back(n);
        }
    }

    return result;
}

int main() {
    int m, n;
    
    // 输入第一个数组的大小和元素
    cin >> m;
    vector<int> nums1(m);
    for (int i = 0; i < m; ++i) {
        cin >> nums1[i];
    }

    // 输入第二个数组的大小和元素
    cin >> n;
    vector<int> nums2(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }

    // 获取交集
    vector<int> result = intersection(nums1, nums2);

    // 输出交集元素，按升序排列
    // sort(result.begin(), result.end());
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
