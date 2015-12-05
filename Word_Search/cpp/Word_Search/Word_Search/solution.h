//
//  solution.h
//  Word_Search
//
//  Created by 中央政治局常委 on 15/11/18.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        long row = board.size(), column = board[0].size();
        vector<vector<bool>> isVisited(row, vector<bool>(column));
        
        for (int i = 0; i < row; ++ i) {
            for (int j = 0; j < column; ++ j) {
                if (board[i][j] == word[0]) {
                    isVisited[i][j] = true;
                    if (dfs(board, word, 1, i, j, isVisited)) return true;
                    isVisited[i][j] = false;
                }
            }
        }
        return false;
    }
    
private:
    int dirx[4] = {1, -1, 0, 0};
    int diry[4] = {0, 0, 1, -1};
    bool dfs(const vector<vector<char>>& board, const string & word, int pos, int x, int y, vector<vector<bool>> &isVisited) {
        if (pos == word.size()) return true;
        for (int i = 0; i < 4; ++ i) {
            x += dirx[i];
            y += diry[i];
            if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] == word[pos] && !isVisited[x][y]) {
                isVisited[x][y] = true;
                if (dfs(board, word, pos + 1, x, y, isVisited)) return true;
                isVisited[x][y] = false;
            }
            x -= dirx[i];
            y -= diry[i];
        }
        return false;
    }
};
#endif /* solution_h */
