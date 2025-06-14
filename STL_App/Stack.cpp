#include <iostream>
#include <Stack>

using namespace std;

int main()
{
    // 首先创建一个栈
    stack<int> theStack;
    // 【堆】一些元素进去
    for (int i = 0; i < 5; i++)
    {
        theStack.push(i); // 应该是 [0,1,..4,] =>top
    }
    // 访问栈顶元素
    std::cout << "Top element is: " << theStack.top() << std::endl; // 4
    theStack.pop();
    std::cout << "After popping, top element is: " << theStack.top() << std::endl;

    cout << "the size is :" << theStack.size() <<endl;
    return 0;
}