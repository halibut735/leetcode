//
//  main.cpp
//  Compare_Version_Numbers
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1, vec2;
        int pre = 0;
        version1.push_back('.');
        version2.push_back('.');
        for (int i = 0; i < version1.size(); ++ i) {
            if (version1[i] == '.') {
                vec1.push_back(stoi(version1.substr(pre, i - pre)));
                pre = i + 1;
            }
        }
        pre = 0;
        for (int i = 0; i < version2.size(); ++ i) {
            if (version2[i] == '.') {
                vec2.push_back(stoi(version2.substr(pre, i - pre)));
                pre = i + 1;
            }
        }
        pre = vec1.size() - vec2.size();
        if (pre > 0) vec2.insert(vec2.end(), pre, 0);
        else if (pre < 0) vec1.insert(vec1.end(), -pre, 0);
        for (int i = 0; i < vec1.size() && i < vec2.size(); ++ i) {
            if (vec1[i] < vec2[i]) return -1;
            else if (vec1[i] > vec2[i]) return 1;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
