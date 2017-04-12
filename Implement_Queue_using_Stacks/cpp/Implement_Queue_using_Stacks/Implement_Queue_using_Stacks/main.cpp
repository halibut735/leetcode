//
//  main.cpp
//  Implement_Queue_using_Stacks
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stkIn.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        moveStk();
        stkOut.pop();
    }
    
    // Get the front element.
    int peek(void) {
        moveStk();
        return stkOut.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        moveStk();
        return stkOut.empty() && stkIn.empty();
    }
    void moveStk(void) {
        if (!stkOut.empty()) return;
        while (!stkIn.empty()) {
            stkOut.push(stkIn.top());
            stkIn.pop();
        }
    }
private:
    stack<int> stkIn, stkOut;
};

int main(int argc, const char * argv[]) {
    Queue que;
    que.push(1);
    que.push(2);
    cout << que.peek() << endl;
    que.push(3);
    cout << que.peek() << endl;
    que.pop();
    cout << que.peek() << endl;
    return 0;
}
