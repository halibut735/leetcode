//
//  main.cpp
//  Range_Sum_Query_Mutable
//
//  Created by 中央政治局常委 on 15/11/29.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> nums({1, 2, 3, 4, 5, 6});
    NumArray test(nums);
    cout << test.sumRange(2, 2) << endl;
    test.update(2, 5);
    cout << test.sumRange(2, 2) << endl;
    return 0;
}
