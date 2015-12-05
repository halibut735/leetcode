//
//  solution.h
//  Clone_Graph
//
//  Created by 中央政治局常委 on 15/11/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <fstream>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};



class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int, UndirectedGraphNode *> already;
        if (!node) return NULL;
        return dfs(node, already);
    }
private:
    UndirectedGraphNode *dfs(UndirectedGraphNode *original, map<int, UndirectedGraphNode *> &already) {
        if (!original || already.count(original->label)) return NULL;
        UndirectedGraphNode * ret = new UndirectedGraphNode(original->label);
        already[original->label] = ret;
        for (auto each:original->neighbors) {
            if (already.count(each->label))
                ret->neighbors.push_back(already[each->label]);
            else
                ret->neighbors.push_back(dfs(each, already));
        }
        return ret;
    }
};









#endif /* solution_h */
