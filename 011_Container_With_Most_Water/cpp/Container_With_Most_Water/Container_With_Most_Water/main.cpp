//
//  main.cpp
//  Container_With_Most_Water
//
//  Created by 中央政治局常委 on 15/10/4.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include "solution.h"
using namespace std;

fstream handle("/Users/bingoboy/Downloads/cases.txt");
int main(int argc, const char * argv[]) {
    int height;
    vector<int> input;
    while (handle >> height) {
        input.push_back(height);
    }
    
    Solution sol;
    sol.maxArea(input);
    return 0;
}
