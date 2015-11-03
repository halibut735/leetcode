//
//  solution.h
//  Search_a_2D_Matrix
//
//  Created by 中央政治局常委 on 15/10/26.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty() || target < matrix[0][0])
            return false;
        long row = binarySearchRow(matrix, target);
        return binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
private:
    long binarySearchRow(vector<vector<int>>& matrix, int target){
        long row = matrix.size();
        long left = 0, right = row, middle;
        while (left + 1 < right) {
            middle = (left + right) / 2;
            if (matrix[middle][0] == target)
                return middle;
            else if (matrix[middle][0] < target)
                left = middle;
            else
                right = middle;
        }
        return left;
    }
};
#endif /* solution_h */
