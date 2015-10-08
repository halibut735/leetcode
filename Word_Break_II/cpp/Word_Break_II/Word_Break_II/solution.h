//
//  solution.h
//  Word_Break_II
//
//  Created by 中央政治局常委 on 15/10/6.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> ret, sentence;
        vector<long> bpoints(1, -1);
        unordered_map<long, vector<long>> breakPoints;
        string subStr;
        long lastPos;
        
        for (int i = 0; i < s.size(); ++ i) {
            for (long j = bpoints.size() - 1; j >= 0; --j) {
                lastPos = bpoints[j];
                subStr = s.substr(lastPos + 1, i - lastPos);
                if (wordDict.count(subStr)) {
                    breakPoints[i].push_back(lastPos);
                    if (i != bpoints.back())
                        bpoints.push_back(i);
                }
            }
        }
        
        generateSequence(ret, breakPoints, s, s.size() - 1, sentence);
        return ret;
    }
    
private:
    void generateSequence(vector<string>& ret, unordered_map<long, vector<long>>& breakPoints, const string & s, long pos, vector<string> &sentence){
        if (pos == -1) {
            ret.push_back(vecToStr(sentence));
            return ;
        }
        
        for (auto each:breakPoints[pos]) {
            sentence.push_back(s.substr(each + 1,pos - each));
            generateSequence(ret, breakPoints, s, each, sentence);
            sentence.pop_back();
        }
    }
    
    string vecToStr(vector<string> vec){
        string ret;
        reverse(vec.begin(), vec.end());
        for (auto & each:vec) {
            ret += each + " ";
        }
        if (!ret.empty()) ret.pop_back();
        return ret;
    }
};

#endif /* solution_h */
