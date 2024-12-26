#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> stack1, stack2;

    void transfer() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        if (stack2.empty()) transfer();
        int top = stack2.top();
        stack2.pop();
        return top;
    }

    int peek() {
        if (stack2.empty()) transfer();
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;  // Output: 1
    cout << q.pop() << endl;   // Output: 1
    cout << q.empty() << endl; // Output: 0
    return 0;
}
