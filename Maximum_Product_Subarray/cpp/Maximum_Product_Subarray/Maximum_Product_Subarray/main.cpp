//
//  main.cpp
//  Maximum_Product_Subarray
//
//  Created by 中央政治局常委 on 15/11/18.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

fstream input("/Users/bingoboy/Desktop/in.txt");
fstream output("/Users/bingoboy/Desktop/out.txt");
int main(int argc, const char * argv[]) {
    vector<int> nums;
    Solution test;
    int tmp;
    while (input >> tmp) {
        nums.push_back(tmp);
    }
    cout << test.maxProduct(nums) << endl;
    return 0;
}
