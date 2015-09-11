//
//  solution.h
//  Letter Combinations of a Phone Number
//
//  Created by 中央政治局常委 on 15/9/10.
//  Copyright (c) 2015年 中央政治局常委. All rights reserved.
//
//  深度优先算法

#ifndef Letter_Combinations_of_a_Phone_Number_solution_h
#define Letter_Combinations_of_a_Phone_Number_solution_h
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;


class Solution {
public:
    Solution(){
        tel_comb[0] = " ";
        tel_comb[1] = "1";
        tel_comb[2] = "abc";
        tel_comb[3] = "def";
        tel_comb[4] = "ghi";
        tel_comb[5] = "jkl";
        tel_comb[6] = "mno";
        tel_comb[7] = "pqrs";
        tel_comb[8] = "tuv";
        tel_comb[9] = "wxyz";
        inter_tmp = "";
    }
    
    
    void dfs(const string &digits, int depth, string &inter_tmp){
        if (depth == digits.size()) {
            ret.push_back(inter_tmp);
            return ;
        }
        for (int i = 0; i < tel_comb[digits[depth] - '0'].size(); ++ i) {
            inter_tmp += tel_comb[digits[depth] - '0'].at(i);
            dfs(digits, depth + 1, inter_tmp);
            inter_tmp.erase(inter_tmp.end() -1);
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        if (!digits.size())
            return ret;
        dfs(digits, 0, inter_tmp);
        print_vec(ret);
        return ret;
    }
    
    
    void print_vec(vector<string> & vec){
        for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++ it) {
            cout << *it << endl;
        }
    }
private:
    vector<string> ret;
    map<int, string> tel_comb;
    string tmp;
    string inter_tmp;
};


#endif
