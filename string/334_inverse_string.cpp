#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0, j = n -1; i < j; i++, j--)
        {
            char tmpchar = s[i];
            s[i] = s[j];
            s[j] = tmpchar;
        }
}

int main()
{
    vector<char> s1 = {'h','e','l','l','o'};
    reverseString(s1);
    for (char c : s1) {
        cout << c;
    }
    cout << endl;
    return 0;
}