#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void testBasicLbd()
{
    auto add = [] (int a, int b) -> int 
    {
        return a + b;
    };
    
    int x = 3;
    int y = 4;
    int z = add(x, y);
    cout << "z = " << z << endl;
    auto lambda = [x, &y] () -> void {
        y++;
        cout << "y = " << y << endl;
    };
    z = add(x, y);
    cout << "z = " << z << endl;
}
int main()
{
    vector<int> numbers = {3, 2, 1, 5, 4};
    sort(numbers.begin(), numbers.end(), [](int a, int b) -> bool{
        return a > b;
    });
    for (int num : numbers) {
        cout << num << " ";  // 输出: 5 4 3 2 1
    }
    return 0;
}