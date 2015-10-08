//
//  main.cpp
//  Shortest_Palindrome
//
//  Created by 中央政治局常委 on 15/10/2.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <fstream>
#include <sstream>
#include "solution2.h"
using namespace std;
fstream handle("/Users/bingoboy/Downloads/cases.txt");
int main(int argc, const char * argv[]) {
    Solution sol;
    cout << sol.shortestPalindrome("baabcddc") << endl;
    return 0;
}
