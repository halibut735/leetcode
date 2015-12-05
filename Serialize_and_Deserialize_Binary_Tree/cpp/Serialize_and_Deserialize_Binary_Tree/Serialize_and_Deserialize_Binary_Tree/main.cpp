//
//  main.cpp
//  Serialize_and_Deserialize_Binary_Tree
//
//  Created by 中央政治局常委 on 15/11/28.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    string code("1,2,#,");
    Codec test;
    test.deserialize(code);
    cout << test.serialize(test.deserialize(code)) << endl;
    return 0;
}
