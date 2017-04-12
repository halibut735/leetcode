//
//  solution.h
//  Verify_Preorder_Serialization_of_a_Binary_Tree
//
//  Created by 中央政治局常委 on 16/2/29.
//  Copyright © 2016年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <string>
using namespace std;


class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty() || preorder[0] == '#') return false;
        int pos = 0;
        for (pos = 0; pos < preorder.size() && preorder[pos] != ','; ++ pos ) ;
        
    }
};
#endif /* solution_h */
