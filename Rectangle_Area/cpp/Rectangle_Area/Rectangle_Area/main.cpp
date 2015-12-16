//
//  main.cpp
//  Rectangle_Area
//
//  Created by 中央政治局常委 on 15/12/16.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (E > C || A > G || B > H || F > D) return (C - A) * (D - B) + (G - E) * (H - F);
        int x1 = max(A, E), y1 = max(B, F), x2 = min(C, G), y2 = min(D, H);
        return (C - A) * (D - B) + (G - E) * (H - F) - (x2 - x1) * (y2 - y1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
