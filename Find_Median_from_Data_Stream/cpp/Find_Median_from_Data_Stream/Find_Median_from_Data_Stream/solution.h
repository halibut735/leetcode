//
//  solution.h
//  Find_Median_from_Data_Stream
//
//  Created by 中央政治局常委 on 15/10/21.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> lessNums;
    priority_queue<int, vector<int>, greater<int>> greaterNums;
    // Adds a number into the data structure.
    void addNum(int num) {
        if (greaterNums.size() >= lessNums.size()) {
            if (lessNums.empty()) {
                lessNums.push(num);
                return;
            }
            int rightNum = greaterNums.top();
            if (num > rightNum) {
                greaterNums.pop();
                greaterNums.push(num);
                num = rightNum;
            }
            lessNums.push(num);
        }
        else {
            int leftNum = lessNums.top();
            if (num < leftNum) {
                lessNums.pop();
                lessNums.push(num);
                num = leftNum;
            }
            greaterNums.push(num);
        }
    }
    
    // Returns the median of current data stream
    double findMedian() {
        if ((lessNums.size() + greaterNums.size()) % 2) {
            return lessNums.top();
        }
        else {
            return (lessNums.top() + greaterNums.top()) / 2.0;
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
#endif /* solution_h */
