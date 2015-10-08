//
//  main.cpp
//  Wildcard_Matching
//
//  Created by 中央政治局常委 on 15/10/1.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "solution.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Solution sol;
    cout << sol.isMatch("abbbaaaaaaaabbbabaaabbabbbaabaabbbbaabaabbabaabbabbaabbbaabaabbabaabaabbbbaabbbaabaaababbbbabaaababbaaa",
                        "ab**b*bb*ab**ab***b*abaa**b*a*aaa**bba*aa*a*abb*a*a") << endl;
    return 0;
}
