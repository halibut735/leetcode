//
//  solution.h
//  Rotate_Array
//
//  Created by 中央政治局常委 on 15/9/10.
//  Copyright (c) 2015年 中央政治局常委. All rights reserved.
//

#ifndef Rotate_Array_solution_h
#define Rotate_Array_solution_h

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int>::size_type size = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end() -k);
        nums.erase(nums.begin(), nums.begin() + size - k);
    }
    void print_vector(vector<int> &nums){
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); i ++) {
            cout << *i << endl;
        }
    }
};

#endif
