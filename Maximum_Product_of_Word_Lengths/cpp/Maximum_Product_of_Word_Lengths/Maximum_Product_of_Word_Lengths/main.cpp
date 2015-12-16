//
//  main.cpp
//  Maximum_Product_of_Word_Lengths
//
//  Created by 中央政治局常委 on 15/12/16.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = (int) words.size();
        vector<long> chars(len, 0);
        int ret = 0;
        
        sort(words.begin(), words.end(), cmp);
        for (int i = 0; i < len; ++ i)
            for (char each : words[i]) chars[i] |= 1 << (each - 'a');
        
        for (int i = 0; i < len; ++ i) {
            if (words[i].size() * words[i].size() <= ret) break;
            for (int j = i + 1; j < len; ++ j) {
                if (words[i].size() * words[j].size() <= ret) break;
                if (chars[i] & chars[j]) continue;
                ret = max(ret, int(words[i].size() * words[j].size()));
            }
        }
        return ret;
    }
private:
    static bool cmp (const string &a, const string &b) {
        return a.size() > b.size();
    }
};

int main(int argc, const char * argv[]) {
    vector<string> words({"fed","dcccbfeaceeea","fadabbcdfbcdeffceea","fccfbddaccebbdeeba","fbdfce","dcd","fcdecaf","abdbcb","ddceefaa","efbaabaaffbafbffacafe","cdedbfbbcbcaaf","ddafcedfcdefadbbe","baaabda","fbfcabdeddda","bcdabf","ceedbfdacecebbcadec","fdfbccf","eea","ebeafdd","fcaadbdffababd","cdfabfdaebdfbcde","aebfffbffdfdae","fdfdeadfde","fcddabcfcbddcfcfbdcbd","eafdafcccffbe","dfebdabcdacccdd","dbeecabddadce","defbefecba","ede","eeee","fafcaaccdfbfdaeda","cbfbeaaadcdfeaacce","baf","baaffadbc","bbbffeaaeaffbbcae","ebaacbebabaaedeeffef","baacddbeadebec","dfbdbdeddffc","caffee","eadbdbcfefdabdffaa","bebeffaefccacd","ef","edef","abeecefaebbedaedbe","bcadffaacc","ddafd","abede","deecebffe","acddccbefeacfbbeea","efbffddafbeeabdbdcce","aabeafababefbebabf","acdeed","afadcfacaffbbdcdadfd","daeeaffffcba","cadfdcbc","ffdafedbce","abeebdec","dfbbaed","eddafecbbcdca","cbdcfeba","dc","cbfabcbecaddabbc","baaabebddfce","edcadfeffaec","badbffccecdacbfbab","cecbaeaad","dadbbeeeecc","adedfdfbaeafcdbeedde","adbcedebcfffcbaacfbe","dcaaabeafbcfeefdaeabe","dbdfcc","dadfceceedfeedaafc","bfdafecbaeeafedccc","feaabbaaffccfeaaaadf","ecafaadc","eaacfad","daeadcccbdae","afafaebfbdbec","aaefbdddadbb","fa","eb","eddaacdddacbfbefcd","bdecccabbddfdcd","cfdcceacebaacccffbeac","ddbefba","eacaac","aafdeffcedbabefadddd","cbdabfe","ebeaacdddfecaaad","face","bfdbffacfacdd","dcdfae","fbafceacefaecbddcf","dfaaaafffc","fdafdbccadd","acebdcbacdbceceedeeb","ddcdfadbdbebdffdfef","bbdfabbcaeabfcbbadea","ddcebbdfccabfcdffafdc","efcbfedbbdfdbdbbdbe","acfcd"});
    Solution test;
    cout << test.maxProduct(words) << endl;
    return 0;
}
