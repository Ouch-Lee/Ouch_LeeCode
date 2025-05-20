#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> theMap;
        for (string str : strs)
        {
            string keyString = str;
            sort(keyString.begin(), keyString.end());
            theMap[keyString].push_back(str);
        }
        vector<vector<string>> result;
        for (const auto & pair : theMap)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};