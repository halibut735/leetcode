//
//  main.cpp
//  Pascal's_Triangle
//
//  Created by 中央政治局常委 on 15/12/15.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret({{1}});
        if (!numRows) return {};
        for (int i = 1; i < numRows; ++ i) {
            vector<int> row(ret[i - 1].size() + 1);
            for (int j = 0; j < ret[i - 1].size() + 1; ++ j) {
                row[j] = (j ? ret[i - 1][j - 1] : 0) + (j < ret[i - 1].size() ? ret[i - 1][j] : 0);
            }
            ret.push_back(row);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    test.generate(0);
    return 0;
}
