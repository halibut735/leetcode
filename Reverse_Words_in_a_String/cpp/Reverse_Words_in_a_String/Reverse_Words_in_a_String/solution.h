//
//  solution.h
//  Reverse_Words_in_a_String
//
//  Created by 中央政治局常委 on 15/11/11.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

//网上的做法 逆转两次，第一次逆转整体句子，第二次逆转单词
//第二种方法，我觉得挺好，用栈存单词，结束了这个单词，弹出，放到结果里面，棒(๑•̀ㅂ•́)و✧！

class Solution {
public:
    void reverseWords(string &s) {
        stringstream ss(s);
        vector<string> vec;
        string tmp;
        while (ss >> tmp) {
            vec.push_back(tmp);
        }
        reverse(vec.begin(), vec.end());
        s.clear();
        for (auto each:vec) {
            s.append(each);
            s.append(1, ' ');
        }
        if (!s.empty()) s.pop_back();
    }
};
#endif /* solution_h */
