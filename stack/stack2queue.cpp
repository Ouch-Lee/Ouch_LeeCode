#include <stack>
#include <iostream>

class MyQueue {
public:
    std::stack<int> theQueue;  // 用来存储队列元素

    // Push元素到队列
    void push(int x) {
        theQueue.push(x);
    }
    
    // Pop队列头部元素
    int pop() {
        std::stack<int> tmpStack;
        int result = 0;
        
        // 将除了头元素外的所有元素移到tmpStack
        while (theQueue.size() > 1) {
            tmpStack.push(theQueue.top());
            theQueue.pop();
        }
        
        // 获取队列头部元素
        result = theQueue.top();
        theQueue.pop();  // 弹出头部元素
        
        // 将tmpStack中的元素再放回theQueue
        while (!tmpStack.empty()) {
            theQueue.push(tmpStack.top());
            tmpStack.pop();
        }
        
        return result;
    }

    // Peek队列头部元素
    int peek() {
        std::stack<int> tmpStack;
        int result = 0;
        
        // 将除了头元素外的所有元素移到tmpStack
        while (theQueue.size() > 1) {
            tmpStack.push(theQueue.top());
            theQueue.pop();
        }

        // 获取队列头部元素
        result = theQueue.top();
        
        // 将tmpStack中的元素再放回theQueue
        while (!tmpStack.empty()) {
            theQueue.push(tmpStack.top());
            tmpStack.pop();
        }

        return result;
    }

    // 判断队列是否为空
    bool empty() {
        return theQueue.empty();
    }
};

// 测试代码
int main() {
    MyQueue q;
    
    // 测试 push 和 pop
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << "Peek: " << q.peek() << std::endl;  // 输出 1
    std::cout << "Pop: " << q.pop() << std::endl;    // 输出 1
    std::cout << "Peek after pop: " << q.peek() << std::endl;  // 输出 2
    std::cout << "Pop: " << q.pop() << std::endl;    // 输出 2
    std::cout << "Pop: " << q.pop() << std::endl;    // 输出 3
    
    // 测试 empty
    if (q.empty()) {
        std::cout << "Queue is empty." << std::endl;  // 输出 Queue is empty.
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    return 0;
}
