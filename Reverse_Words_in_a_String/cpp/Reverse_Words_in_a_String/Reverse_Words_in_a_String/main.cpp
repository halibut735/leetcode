//
//  main.cpp
//  Reverse_Words_in_a_String
//
//  Created by 中央政治局常委 on 15/11/11.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution test;
    string str("  the sky is   blue  ");
    test.reverseWords(str);
    cout << str << endl;
    return 0;
}
