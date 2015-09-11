//
//  solution.h
//  Letter Combinations of a Phone Number
//
//  Created by 中央政治局常委 on 15/9/10.
//  Copyright (c) 2015年 中央政治局常委. All rights reserved.
//
//  广度优先算法

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
    vector<string> ret;
    
    Solution(){
        tel_comb["0"] = " ";
        tel_comb["1"] = "1";
        tel_comb["2"] = "abc";
        tel_comb["3"] = "def";
        tel_comb["4"] = "ghi";
        tel_comb["5"] = "jkl";
        tel_comb["6"] = "mno";
        tel_comb["7"] = "pqrs";
        tel_comb["8"] = "tuv";
        tel_comb["9"] = "wxyz";
    }
    
    vector<string> letterCombinations(string digits) {
        queue<string> que;
        for (int i = 0; i < tel_comb[digits.substr(0, 1)].size(); ++ i) {
            //cout << tel_comb[digits.substr(0, 1)].substr(i, 1) << endl;
            que.push(tel_comb[digits.substr(0, 1)].substr(i, 1));
        }
        for (int i = 1; i < digits.size(); ++ i) {
            while (que.front().size() <= i) {
                for (int j = 0; j < tel_comb[digits.substr(i, 1)].size(); ++ j) {
                    //cout << que.front() + tel_comb[digits.substr(i, 1)].substr(j, 1) << endl;
                    que.push(que.front() + tel_comb[digits.substr(i, 1)].substr(j, 1));
                }
                que.pop();
                //cout << que.size() << endl;
            }
        }
        while(!que.empty()){
            ret.push_back(que.front());
            que.pop();
        }
        print_vec(ret);
        return ret;
    }
    
    void print_vec(vector<string> & vec){
        for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++ it) {
            cout << *it << endl;
        }
    }
private:
    map<string, string> tel_comb;
    string tmp;
};


#endif
