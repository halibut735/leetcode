//
//  main.cpp
//  Move_Zeroes
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> tmp;
        int cnt = 0;
        for (int each : nums) {
            if (each) tmp.push_back(each);
            else cnt ++;
        }
        nums = tmp;
        nums.insert(nums.end(), cnt, 0);
    }
};


int main(int argc, const char * argv[]) {
    
    return 0;
}
