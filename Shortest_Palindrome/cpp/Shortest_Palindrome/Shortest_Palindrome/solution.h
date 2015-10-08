//
//  solution.h
//  Shortest_Palindrome
//
//  Created by 中央政治局常委 on 15/10/2.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <fstream>
#include <sstream>
using namespace std;


class Solution {
public:
    string shortestPalindrome(string s) {
        long left = s.size()/2 - 1, right = s.size()/2;
        if (s.size() <= 1) return s;
        string ret, tmp;
        while (left >= 0 || right < s.size()) {
            if (left >= 0) {
                if (canBeShortest(s, left)) {
                    tmp = makeThePalindrome(s, left, -1, true);
                    ret = ret.empty() || ret.size() > tmp.size() ? tmp : ret;
                }
                if (canBeShortest(s, left, left + 1)) {
                    tmp = makeThePalindrome(s, left, left + 1, true);
                    ret = ret.empty() || ret.size() > tmp.size() ? tmp : ret;
                }
            }
            if (right < s.size()) {
                if (canBeShortest(s, right)) {
                    tmp = makeThePalindrome(s, right, - 1, false);
                    ret = ret.empty() || ret.size() > tmp.size() ? tmp : ret;
                }
                if (canBeShortest(s, right - 1, right)) {
                    tmp = makeThePalindrome(s, right - 1, right, false);
                    ret = ret.empty() || ret.size() > tmp.size() ? tmp : ret;
                }
            }
            left --;
            right ++;
            if (!ret.empty()) return ret;
        }
        return ret;
    }
private:
    bool canBeShortest(const string & s, long pos1, long pos2 = -1){
        long left ,right;
        switch (pos2) {
            case -1:
                left = pos1 - 1;
                right = pos1 + 1;
                break;
                
            default:
                left = pos1;
                right = pos2;
                break;
        }
        while (left >= 0 && right != s.size()) {
            if (s[left] != s[right]) return false;
            left --;
            right ++;
        }
        return true;
    }
    string makeThePalindrome(const string & s, long pos1, long pos2, bool isLeftDriectiron){
        long left, right;
        string ret;
        switch (pos2) {
            case -1:
                left = pos1 - 1;
                right = pos1  + 1;
                break;
                
            default:
                left = pos1;
                right = pos2;
                break;
        }
        if (isLeftDriectiron && pos2 == -1) {
            ret.insert(ret.end(), s.rbegin(), s.rbegin() + s.size() - right);
            ret.insert(ret.end(), s.begin() + left + 1, s.end());
        }
        else if (isLeftDriectiron && pos2 != -1) {
            ret.insert(ret.end(), s.rbegin(), s.rbegin() + s.size() - right);
            ret.insert(ret.end(), s.begin() + right, s.end());
        }
        else if (!isLeftDriectiron && pos2 == -1) {
            ret.insert(ret.end(), s.begin(), s.begin() + right);
            ret.insert(ret.end(), s.rend() - left - 1, s.rend());
        }
        else if (!isLeftDriectiron && pos2 != -1) {
            ret.insert(ret.end(), s.begin(), s.begin() + right);
            ret.insert(ret.end(), s.rend() - right, s.rend());
        }
        return ret;
    }
};
#endif /* solution_h */
