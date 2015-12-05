//
//  solution.h
//  Range_Sum_Query_Mutable
//
//  Created by 中央政治局常委 on 15/11/29.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        root = build(nums, 0, nums.size());
    }
    
    void update(int i, int val) {
        renew(root, i, val);
    }
    
    int sumRange(int i, int j) {
        return query(i, j, root);
    }
private:
    struct node {
        int bl, br, sum;
        node * ll, * rr;
        node (int _l = 0, int _r = 0, int _sum = 0):bl(_l), br(_r), sum(_sum), ll(NULL), rr(NULL) {}
    } * root;
    
    node * build(vector<int> &nums, int bl, int br) {
        if (bl == br) return NULL;
        if (bl + 1 == br) return new node(bl, bl, nums[bl]);
        node *ret = new node(bl, br - 1);
        int middle = (bl + br) / 2;
        ret->ll = build(nums, bl, middle);
        ret->rr = build(nums, middle, br);
        ret->sum = ret->ll->sum + ret->rr->sum;
        return ret;
    }
    
    int renew(node *root, int i, int val) {
        if (root->bl == i && root->br == i) {
            int diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int middle = (root->bl + root->br + 1) / 2;
        int diff = renew(i < middle ? root->ll : root->rr, i, val);
        root->sum += diff;
        return diff;
    }
    
    int query(int i, int j, node * root) {
        if (i == root->bl && j == root->br) return root->sum;
        int middle = (root->bl + root->br + 1) / 2, lsum = 0, rsum = 0;
        lsum = i < middle ? query(i, min(j, middle - 1), root->ll) : 0;
        rsum = j >= middle ? query(max(i, middle), j, root->rr) : 0;
        return lsum + rsum;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
#endif /* solution_h */
