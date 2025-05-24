class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int result = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            if (charMap.count(s[right]) && charMap[s[right]] >= left)
            {
                left = charMap[s[right]] + 1; 
            }
            charMap[s[right]] = right;
            result = max(result, right - left + 1);
        }
        return result;
        }
};