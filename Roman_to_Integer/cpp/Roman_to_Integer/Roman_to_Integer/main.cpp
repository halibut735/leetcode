//
//  main.cpp
//  Roman_to_Integer
//
//  Created by 中央政治局常委 on 15/12/16.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        char c[10][10][10]={{"0","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"0","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"0","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"}};
        int prep = 0, pos = 0, ret = 0;
        string tmp;
        
        while (s[pos] == 'M') pos ++;
        ret += pos * 1000;

        prep = pos;
        while (s[pos] == 'C' || s[pos] == 'D' || s[pos] == 'M') pos ++;
        tmp = s.substr(prep, pos - prep);
        for (int i = 0; i < 10; ++ i)
            if (tmp == c[2][i]) ret += 100 * i;
        
        prep = pos;
        while (s[pos] == 'X' || s[pos] == 'L' || s[pos] == 'C') pos ++;
        tmp = s.substr(prep, pos - prep);
        for (int i = 0; i < 10; ++ i)
            if (tmp == c[1][i]) ret += 10 * i;
        
        prep = pos;
        tmp = s.substr(prep);
        for (int i = 0; i < 10; ++ i)
            if (tmp == c[0][i]) ret += i;
        
        return ret;
    }
    string intToRoman(int num) {
        char c[10][10][10]={{"0","I","II","III","IV","V","VI","VII","VIII","IX"},
                            {"0","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                            {"0","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                            {"0","M","MM","MMM"}};
        int tmp=num;
        string st;
        if(tmp/1000!=0) st+=c[3][tmp/1000];
        if((tmp%1000)/100!=0) st+=c[2][(tmp%1000)/100];
        if((tmp%100)/10!=0) st+=c[1][(tmp%100)/10];
        if(tmp%10!=0) st+=c[0][tmp%10];
        return st;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.romanToInt(test.intToRoman(3876)) << endl;
    return 0;
}
