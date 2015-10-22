//
//  solution.h
//  Palindrome_Partitioning_II
//
//  Created by 中央政治局常委 on 15/10/21.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        vector<int> palindromeStart(s.size(), 0), cutCnt(s.size(), 0);
        for (int i = 1; i < s.size(); ++ i) {
            int matchIndex = palindromeStart[i - 1] - 1;
            if (matchIndex >= 0 && s[i] == s[matchIndex]) {
                palindromeStart[i] = matchIndex;
            }
            else if (i - 2 >= 0 && s[i] == s[i - 2]){
                palindromeStart[i] = i - 2;
            }
            else if (i - 1 >= 0 && s[i] == s[i - 1]){
                palindromeStart[i] = i - 1;
            }
            else {
                palindromeStart[i] = i;
            }
        }
        
        for (int i = 1; i < s.size(); ++ i) {
            if (palindromeStart[i] > 0) {
                cutCnt[i] = min(cutCnt[i - 1], cutCnt[palindromeStart[i] - 1]) + 1;
            }
            else {
                cutCnt[i] = 0;
            }
            
        }
        return cutCnt[s.size() - 1];
    }
};
#endif /* solution_h */
