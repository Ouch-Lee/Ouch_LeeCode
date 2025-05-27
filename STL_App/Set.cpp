#include <iostream>
#include <set>

using namespace std;

int main()
{
    // 构造一个set
    set<int> setDemo = {0,2,1,3}; 
    setDemo.insert(0); // 应该只有一个0
    setDemo.insert(5);
    setDemo.insert(4);
    // set内部竟然会自动进行排序！
    // setDemo.erase(4);
    for (int n : setDemo)
    {
        cout << n << endl;
        // setDemo.erase(n);
    }
    if (setDemo.empty()) cout << "set is empty" << endl;

    set<char> charSet = {'b', 'e', 'c', 'a'};
    charSet.insert('d');
    charSet.erase('c');
    for (char c : charSet)
    {
        cout << c << endl;
    }
    if (charSet.find('a') != charSet.end()) cout << "found !" << endl;  
    return 0;
}