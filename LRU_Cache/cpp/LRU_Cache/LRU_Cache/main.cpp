//
//  main.cpp
//  LRU_Cache
//
//  Created by 中央政治局常委 on 15/9/30.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include "solution.h"
using namespace std;

int main(int argc, const char * argv[]) {
    LRUCache sol(2);
    sol.set(2, 1);
    sol.set(3, 2);
    cout << sol.get(3) << endl;
    cout << sol.get(2) << endl;
    sol.set(4, 3);
    cout << sol.get(2) << endl;
    cout << sol.get(3) << endl;
    cout << sol.get(4) << endl;
    return 0;
}
