//
//  main.cpp
//  Group_Anagrams
//
//  Created by 中央政治局常委 on 15/11/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution test;
    vector<string> strs({"aab", "aba", "ccb", "msn", "nsm"});
    test.groupAnagrams(strs);
    return 0;
}
