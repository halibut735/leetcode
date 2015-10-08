//
//  solution.h
//  Word_Search_II
//
//  Created by 中央政治局常委 on 15/9/30.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        set<string> beforeRet;
        //判断边界条件
        if (!board.size() || !board[0].size() || !words.size()) {
            return ret;
        }
        long row = board.size(), column = board[0].size(); //长宽
        vector<vector<bool>> is_visited(row, vector<bool>(column, false)); //标志位，用于dfs
        map<char, vector<postion>> hashmap; //标记26个字母在board中的位置
        //置hashmap为空，设置大小
        for (char chr = 'a'; chr <= 'z'; ++ chr) {
            vector<postion> tmp;
            hashmap[chr] = tmp;
        }
        //初始化hashmap
        for (int i = 0; i < row; ++ i) {
            for (int j = 0; j < column; ++ j) {
                hashmap[board[i][j]].push_back(postion(i, j));
            }
        }
        
        //构建字典树
        root = new triNode;
        for (auto & str:words) {
            insertWord(str);
        }
        
        for (int i = 0;i < 26; ++ i) {
            if (!root->chr[i]) continue;
            char tail[2] = {char('a' + i), 0};
            string catStr(tail);
            for (auto & start:hashmap['a' + i]) {
                dfs(root->chr[i], start.x, start.y, beforeRet, board, is_visited, catStr);
            }
        }
        for (auto & each:beforeRet) {
            ret.push_back(each);
        }
        return ret;
    }
private:
    struct triNode{
        triNode *chr[26];
        bool isWord;
        triNode():isWord(false){
            for (auto & each:chr)
                each = NULL;
        }
    } *root;
    
    void insertWord(const string & str){
        triNode * pos = root;
        //root need to be initialized.
        for (auto & chr:str) {
            int chrIndex  = chr - 'a';
            if (!pos->chr[chrIndex]) {
                pos->chr[chrIndex] = new triNode;
            }
            pos = pos->chr[chrIndex];
        }
        pos->isWord = true;
    }
    
    
    void dfs(triNode* pos, int x, int y, set<string> & beforeRet, vector<vector<char>>& board, vector<vector<bool>> &is_visited, string & catStr){
        if (!pos) return ;
        int horizontal[4] = {-1, 1, 0, 0};
        int vertical[4] = {0, 0, 1, -1};
        is_visited[x][y] = true;
        int xx, yy;
        char tmpChr = 'a' - 1, tail[2] = {};
        long row = board.size(), column = board[0].size();
        
        if (pos->isWord && !beforeRet.count(catStr)) beforeRet.emplace(catStr);
        for (auto & each:pos->chr) {
            tmpChr ++;
            if (!each) continue;
            for (int i = 0; i < 4; ++ i) {
                xx = x + horizontal[i];
                yy = y + vertical[i];
                if (xx < 0 || xx >= row || yy < 0 || yy >= column || is_visited[xx][yy]) continue;
                if (tmpChr == board[xx][yy]) {
                    tail[0] = tmpChr;
                    catStr += tail;
                    dfs(each, xx, yy, beforeRet, board, is_visited, catStr);
                    catStr.pop_back();
                }
            }
        }
        is_visited[x][y] = false;
    }
    
    
    struct postion{
        int x, y;
        postion(int a, int b):x(a), y(b){}
    };
};

#endif /* solution_h */
