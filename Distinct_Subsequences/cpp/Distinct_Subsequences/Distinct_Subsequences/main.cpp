//
//  main.cpp
//  Distinct_Subsequences
//
//  Created by 中央政治局常委 on 15/12/3.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    string s("rabbbit"), t("rabbit");
    //string s("cococ"), t("coc");
    Solution test;
    cout << test.numDistinct(s, t) << endl;
    return 0;
}
