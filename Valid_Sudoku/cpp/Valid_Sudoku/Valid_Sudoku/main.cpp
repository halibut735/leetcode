//
//  main.cpp
//  Valid_Sudoku
//
//  Created by 中央政治局常委 on 15/12/9.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++ i) {
            int flag1[10] = {0};
            int flag2[10] = {0};
            int flag3[10] = {0};
            for (int j = 0; j < 9; ++ j) {
                if (board[i][j] == '.') ;
                else if (flag1[board[i][j] - '1']) return false;
                else flag1[board[i][j] - '1'] ++;
                if (board[j][i] == '.') ;
                else if (flag2[board[j][i] - '1']) return false;
                else flag2[board[j][i] - '1'] ++;
                if (board[i/3*3 + j/3][i%3*3 + j%3] == '.') ;
                else if (flag3[board[i/3*3 + j/3][i%3*3 + j%3] - '1']) return false;
                else flag3[board[i/3*3 + j/3][i%3*3 + j%3] - '1'] ++;
            }
        }
        return true;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
