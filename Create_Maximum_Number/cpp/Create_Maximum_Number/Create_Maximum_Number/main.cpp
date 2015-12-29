//
//  main.cpp
//  Create_Maximum_Number
//
//  Created by 中央政治局常委 on 15/12/23.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret(k, 0);
        if (!k) return ret;
        int len = min(k, (int)nums1.size());
        for (int i = 0; i <= len; ++ i) {
            if (k - i > nums2.size()) continue;
            auto tmp = combine(topmaxn(nums1, i), topmaxn(nums2, k - i));
            if (cmp(ret, tmp)) ret = tmp;
        }
        return ret;
    }
private:
    vector<int> topmaxn(const vector<int> &nums, int k) {
        int index = 0;
        vector<int> ret(k);
        if (!k) return ret;
        for (int i = 0; i < nums.size(); ++ i) {
            while (nums[i] > ret[index - 1] && index > 0 && k - index < nums.size() - i)
                -- index;
            if (index < k)
                ret[index ++] = nums[i];
        }
        return ret;
    }
    
    bool cmp(const vector<int> &nums1, const vector<int> &nums2) {
        for (int i = 0; i < nums1.size(); ++ i) {
            if (nums1[i] < nums2[i]) return true;
            else if (nums1[i] > nums2[i]) return false;
        }
        return false;
    }
    
    
    bool geq(const vector<int> &nums1, int i, const vector<int> &nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            ++ i, ++ j;
        }
        return j == nums2.size() || (i != nums1.size() && nums1[i] > nums2[j]);
    }

    vector<int> combine(const vector<int> &nums1, const vector<int> &nums2) {
        vector<int> ret;
        for (int indexi = 0, indexj = 0; indexi != nums1.size() || indexj != nums2.size(); ) {
            if (geq(nums1, indexi, nums2, indexj))
                ret.push_back(nums1[indexi ++]);
            else
                ret.push_back(nums2[indexj ++]);
        }
        return ret;
    }
};



int main(int argc, const char * argv[]) {
    vector<int> nums1({3,4,6,5}), nums2({9,1,2,5,8,3});
    Solution test;
    test.maxNumber(nums1, nums2, 5);
    return 0;
}
