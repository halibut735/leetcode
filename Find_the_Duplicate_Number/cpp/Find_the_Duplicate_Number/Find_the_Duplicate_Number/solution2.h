//
//  solution2.h
//  Find_the_Duplicate_Number
//
//  Created by 中央政治局常委 on 15/12/2.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution2_h
#define solution2_h
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = int(nums.size()) - 1, middle = 0, cnt = 0;
        while (low < high) {
            middle = (low + high) / 2;
            cnt = 0;
            for (int each : nums)
                if (each <= middle) cnt ++;
            if (cnt <= middle) low = middle + 1;
            else high = middle;
        }
        return low;
    }
};


#endif /* solution2_h */
