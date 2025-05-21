#include <iostream>
#include <vector>
#include <unordered_map>
#include "string.h"

using namespace std;

int* string2Arr(string str)
    {
        int arr[26];
        for (char a : str)
        {
            arr[a - 'a']++;
        }
        return arr;
    }

int main()
{
    string test = "eat";
    int arr[26] = string2Arr(test);
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    } 
    cout << endl;
}