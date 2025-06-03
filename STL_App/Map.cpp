#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, int> myMap;
    myMap['a'] = 1;
    myMap['b'] = 2;
    myMap['c'] = 3;
    for (map<char, int>::iterator it = myMap.begin(); it != myMap.end(); it++)
    {
        cout << "the value of " << it->first << " is " << it->second << endl;
    }
    myMap.erase('a');
    cout << "After erase : " << endl;
    for (map<char, int>::iterator it = myMap.begin(); it != myMap.end(); it++)
    {
        cout << "the value of " << it->first << " is " << it->second << endl;
    }
    myMap.clear();
    cout << "After clear : " << endl;
    for (map<char, int>::iterator it = myMap.begin(); it != myMap.end(); it++)
    {
        cout << "the value of " << it->first << " is " << it->second << endl;
    }
    return 0;
}