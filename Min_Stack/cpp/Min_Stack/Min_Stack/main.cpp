//
//  main.cpp
//  Min_Stack
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    void push(int x) {
        if (minest.empty() || x <= minest.top()) minest.push(x);
        primary.push(x);
    }
    
    void pop() {
        if (primary.top() == minest.top()) minest.pop();
        primary.pop();
    }
    
    int top() {
        return primary.top();
    }
    
    int getMin() {
        return minest.top();
    }
private:
    stack<int> primary, minest;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
