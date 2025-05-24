#include <string>
#include <queue>
#include <iostream>

using namespace std;

#define CHAR_NUM 26
bool isRepeat(int * arr)
{
    for (int i = 0; i < CHAR_NUM; i++)
    {
        if (arr[i] > 1) return true;
    }
    return false;
}

int lengthOfLongestSubstring(string s) {
    queue<char> the_que;
    int hashArr[CHAR_NUM] = {0};
    int result = 1;
    int len = 1;
    the_que.push(s[0]);
    hashArr[s[0] - 'a']++;
    for (int i = 1; i < s.size(); i++)
    {
        the_que.push(s[i]);
        len++;
        hashArr[s[i] - 'a']++;
        if (isRepeat(hashArr)) // 有重复
        {
            cout << "cur index = " << i << endl;
            while (the_que.front() != s[i])
            {
                the_que.pop();
                len--;
            } 
            the_que.pop();
            len--;
            hashArr[s[i] - 'a']--;
            cout << "cur len " << len << endl;
            result = len > result ? len : result;
        }
    }
    return result;
}

int main()
{
    string inStr;
    cin >> inStr;

    cout << lengthOfLongestSubstring(inStr) << endl;
    return 0;
}