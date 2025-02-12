#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1 = "hello";
    reverse(s1.begin(), s1.end());
    cout << s1 << endl;
}