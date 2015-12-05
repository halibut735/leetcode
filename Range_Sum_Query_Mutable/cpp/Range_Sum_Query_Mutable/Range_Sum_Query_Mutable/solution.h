//
//  solution.h
//  Range_Sum_Query_Mutable
//
//  Created by 中央政治局常委 on 15/11/29.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums):clone(nums) {
        array.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++ i)
            add(array, i + 1, nums[i]);
    }
    
    void update(int i, int val) {
        int diff = val - clone[i];
        clone[i] = val;
        add(array, i + 1, diff);
    }
    
    int sumRange(int i, int j) {
        return query(array, j + 1) - query(array, i);
    }
private:
    vector<int> array, clone;
    inline int lowbit(int pos) {
        return pos & -pos;
    }
    void add(vector<int> & nums, int pos, int val) {
        long len = nums.size();
        while (pos < len) {
            nums[pos] += val;
            pos += lowbit(pos);
        }
    }
    int query(vector<int> & nums, int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += nums[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
#endif /* solution_h */
