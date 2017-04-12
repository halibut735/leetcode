//
//  main.cpp
//  407 Trapping Rain Water II
//
//  Created by 中央政治局常委 on 2016/9/26.
//  Copyright © 2016年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        size_t row = heightMap.size(), column = heightMap[0].size();
        vector<vector<int>> withwater(heightMap);
        for (int i = 0; i < row; ++ i) {
            int cur_max = heightMap[i][0];
            for (int j = 0; j < column; ++ j) {
                <#statements#>
            }
        }
    }
};


int main(int argc, const char * argv[]) {
    
    return 0;
}
