#include <iostream>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    string beginStr, endStr, str;
    cin >> beginStr >> endStr;
    unordered_set<string> strSet;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        strSet.insert(str);
        cin.ignore();
    }

    unordered_map<string, int> visitMap;
    visitMap.insert(pair<string, int>(beginStr, 1));
    queue<string> que;
    que.push(beginStr);
    while (!que.empty())
    {
        string word = que.front();
        que.pop();
        int path = visitMap[word];
        // 开始找相差一个的字母
        for (int i = 0; i < word.size(); i++)
        {
            string newStr = word;
            for (int j = 0; j < 26; j++)
            {
                newStr[i] = 'a' + j;
                if (newStr == endStr) 
                {
                    cout << path+1 << endl;
                    return 0;
                }
                if (strSet.find(newStr) != strSet.end() && visitMap.find(newStr) == visitMap.end())
                {
                    // 说明list里面有，且没有访问过
                    que.push(newStr);
                    visitMap.insert(pair<string, int>(newStr, path+1));
                }
            }
        }
    }
    cout << 0 <<endl;
    return 0;
}