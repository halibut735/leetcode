//
//  main.cpp
//  Contains_Duplicate_II
//
//  Created by 中央政治局常委 on 15/12/16.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (!k) return false;
        unordered_set<int> alreadyk;
        for (int i = 0; i < k + 1 && i < nums.size(); ++ i) {
            if (alreadyk.count(nums[i])) return true;
            alreadyk.insert(nums[i]);
        }
        for (int i = k + 1; i < nums.size(); ++ i) {
            alreadyk.erase(alreadyk.find(nums[i - k - 1]));
            if (alreadyk.count(nums[i])) return true;
            alreadyk.insert(nums[i]);
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
