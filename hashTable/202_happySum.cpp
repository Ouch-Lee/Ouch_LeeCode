class Solution {
public:
    int getHappyNum(int n)
    {
        int result = 0;
        while (n > 0)
        {
            int digit = n % 10;
            result += digit * digit;
            n /= 10;
        } 
        return result;
    }
    bool isHappy(int n) {
        int cnt = 1;
        unordered_set<int> theSet;
        theSet.insert(n);
        while (cnt <= theSet.size())
        {
            n = getHappyNum(n);
            if (n == 1) return true;
            theSet.insert(n);
            cnt++;
        }
        return false;
    }
};