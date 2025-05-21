class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int i = 0; 
        int j = height.size() - 1;
        int tmpArea;
        while (i < j)
        {
            tmpArea = min(height[i], height[j]) * (j - i);
            result = tmpArea > result ? tmpArea : result;
            if (height[i] >= height[j]) j--;
            else i++; 
        }
        return result;
    }
};