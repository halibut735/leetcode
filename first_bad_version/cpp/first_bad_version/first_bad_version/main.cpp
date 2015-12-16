//
//  main.cpp
//  first_bad_version
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ll = 1, rr = n + 1;
        if (isBadVersion(1)) return 1;
        while (ll < rr) {
            int middle = ll + (rr - ll) / 2;
            if (isBadVersion(middle) && !isBadVersion(middle - 1)) return middle;
            if (isBadVersion(middle)) rr = middle;
            else ll = middle + 1;
        }
        return ll;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
