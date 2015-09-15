//
//  Header.h
//  Candy
//
//  Created by 中央政治局常委 on 15/9/13.
//  Copyright (c) 2015年 中央政治局常委. All rights reserved.
//

#ifndef Candy_Header_h
#define Candy_Header_h

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size());
        
        candies[0] = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] +1;
            }
            else {
                candies[i] = 1;
            }
        }
        
        candies[ratings.size() - 1] = max(candies[ratings.size() - 1], 1);
        for (int i = int(ratings.size())-2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i+1] + 1, candies[i]);
            }
            else {
                candies[i] = max(1, candies[i]);
            }
        }
        for (int i = 0; i < ratings.size(); ++i) {
            sum += candies[i];
        }
        print_vecs(ratings, candies);
        return sum;
    }
private:
    int sum;
    void print_vecs(vector<int> &a, vector<int> &b) {
        vector<int>::size_type cnt = a.size();
        for (int i = 0; i < cnt; ++i) {
            cout << "ratings: " << a[i] << "\tcandy: " << b[i] <<endl;
        }
    }
};

#endif
