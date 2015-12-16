//
//  main.cpp
//  Count_and_Say
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string pre = "11", cur;
        if (n == 1) return "1";
        int cnt = 0;
        char chr = 0;
        for (int i = 2; i < n; ++ i) {
            for (int j = 0; j < pre.size(); ++ j) {
                if (!cnt || chr != pre[j] ) {
                    if (cnt) cur += to_string(cnt);
                    if (cnt) cur.append(1, chr);
                    chr = pre[j];
                    cnt = 1;
                } else if (chr == pre[j]) {
                    cnt ++;
                }
            }
            cur += to_string(cnt);
            cur.append(1, chr);
            pre = cur;
            cur.clear();
            chr = 0;
            cnt = 0;
        }
        return pre;
    }
};



int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.countAndSay(5) << endl;
    return 0;
}
