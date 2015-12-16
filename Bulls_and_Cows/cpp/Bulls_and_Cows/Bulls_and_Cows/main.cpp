//
//  main.cpp
//  Bulls_and_Cows
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> ref1, ref2;
        int aa = 0, bb = 0;
        for (int i = 0; i < secret.size(); ++ i) {
            if (secret[i] == guess[i])
                aa ++;
            ref1[secret[i]] ++;
            ref2[guess[i]] ++;
        }
        for (auto each : ref1) {
            cout << each.first << " " << each.second << " " << ref2[each.first] << endl;
            bb += min(each.second, ref2[each.first]);
        }
        
        return to_string(aa) + "A" + to_string(bb - aa) + "B";
    }
};



int main(int argc, const char * argv[]) {
    Solution test;
    string s1, s2;
    cout << test.getHint("1807", "7810") << endl;
    return 0;
}
