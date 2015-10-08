//
//  solution.h
//  Text_Justification
//
//  Created by 中央政治局常委 on 15/9/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        queue<string> que;
        int lenOfLine = 0;
        string lastLine;
        
        for (auto & each:words) {
            if (lenOfLine + each.size() <= maxWidth) {
                lenOfLine += each.size() + 1;
                que.push(each);
            }
            else {
                ret.push_back(formALine(que, lenOfLine - que.size(), maxWidth));
                lenOfLine = 0;
                que.push(each);
                lenOfLine += each.size() + 1;
            }
        }
        while (!que.empty()) {
            lastLine += que.front();
            que.pop();
            lastLine += " ";
        }
        lastLine.pop_back();
        lastLine += generateSpace(maxWidth - lastLine.size());
        ret.push_back(lastLine);
        return ret;
    }
private:
    string formALine(queue<string> & que, int wordsLen, int maxWidth){
        string ret;
        if (que.size() == 1) {
            ret += que.front();
            que.pop();
            ret += generateSpace(maxWidth - wordsLen);
            return ret;
        }
        
        int average = (maxWidth - wordsLen) / (que.size() - 1);
        int padding = maxWidth - wordsLen - average * (que.size() - 1);
        
        while (!que.empty()) {
            ret += que.front();
            que.pop();
            if (que.empty()) {
                return ret;
            }
            ret += generateSpace(average + (padding-- > 0? 1 : 0));
        }
        return ret;
    }
    
    
    string generateSpace (int b){
        string ret;
        for (int i = 0; i < b; ++i)
            ret += " ";
        return ret;
    }
};

#endif /* solution_h */
