//
//  main.cpp
//  Implement_Stack_using_Queues
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
    }
    
    // Removes the element on top of the stack.
    void pop() {
        int len = (int) que.size();
        for (int i = 0; i < len - 1; ++ i) {
            que.push(que.front());
            que.pop();
        }
        que.pop();
    }
    
    // Get the top element.
    int top() {
        int len = (int) que.size();
        for (int i = 0; i < len - 1; ++ i) {
            que.push(que.front());
            que.pop();
        }
        len = que.front();
        que.push(que.front());
        que.pop();
        return len;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};


int main(int argc, const char * argv[]) {
    Stack test;
    test.push(1);
    test.push(2);
    cout << test.top() << endl;
    return 0;
}

