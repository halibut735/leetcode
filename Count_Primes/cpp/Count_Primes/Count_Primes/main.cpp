//
//  main.cpp
//  Count_Primes
//
//  Created by 中央政治局常委 on 15/12/16.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        int ret = 0;
        prime[0] = false, prime[1] = false;
        for (int i = 0; i * i < n; ++i) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        for (bool each : prime) if (each) ++ ret;
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
