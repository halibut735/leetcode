//
//  solution.h
//  Find_the_Duplicate_Number
//
//  Created by 中央政治局常委 on 15/10/9.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while (slow != fast);
        fast = 0;
        do {
            slow = nums[slow];
            fast = nums[fast];
        } while (slow != fast);
        return fast;
    }
};
#endif /* solution_h */
