//
//  main.cpp
//  Find_Median_from_Data_Stream
//
//  Created by 中央政治局常委 on 15/10/21.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

fstream handle("/Users/bingoboy/Downloads/cases.txt");
int main(int argc, const char * argv[]) {
    MedianFinder test;
    int tmp;
    while (handle >> tmp) {
        test.addNum(tmp);
    }
    cout << test.findMedian() << endl;
    return 0;
}
