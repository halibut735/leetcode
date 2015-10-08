//
//  solution2.h
//  Valid_Number
//
//  Created by 中央政治局常委 on 15/9/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution2_h
#define solution2_h


#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        status transitionTable[][6] = {
            //KEY_INVALID, KEY_SAPCE, KEY_SIGN, KEY_DIGITAL, KEY_DOT, KEY_EXPONENT,
            ST_INVALID, ST_HEAD_SPACE, ST_SIGN, ST_DIGITAL, ST_SPACE_DOT, ST_INVALID,    //ST_HEAD_SPACE
            ST_INVALID, ST_INVALID, ST_INVALID, ST_DIGITAL, ST_SPACE_DOT, ST_INVALID,    //ST_SIGN
            ST_INVALID, ST_TAIL_SAPCE, ST_INVALID, ST_DIGITAL, ST_DIGITAL_DOT, ST_EXPONENT,    //ST_DIGITAL
            ST_INVALID, ST_TAIL_SAPCE, ST_INVALID, ST_DIGITAL_ONLY, ST_INVALID, ST_EXPONENT,    //ST_DIGITAL_DOT
            ST_INVALID, ST_INVALID, ST_INVALID, ST_DIGITAL_ONLY, ST_INVALID, ST_INVALID,    //ST_SPACE_DOT
            ST_INVALID, ST_INVALID, ST_EXPONENT_SIGN, ST_DIGITAL_ONLY, ST_INVALID, ST_INVALID,    //ST_EXPONENT
            ST_INVALID, ST_TAIL_SAPCE, ST_INVALID, ST_DIGITAL_ONLY, ST_INVALID, ST_EXPONENT,    //ST_DIGITAL_ONLY
            ST_INVALID, ST_TAIL_SAPCE, ST_INVALID, ST_INVALID, ST_INVALID, ST_INVALID,    //ST_TAIL_SAPCE
            ST_INVALID, ST_INVALID, ST_INVALID, ST_DIGITAL_ONLY, ST_SPACE_DOT, ST_INVALID,    //ST_EXPONENT_SIGN
        };
        input_type_e input_type;
        status pre_status = ST_HEAD_SPACE;
        flag_exponent = false;
        for (int i = 0; i < s.size(); ++i) {
            switch (s.at(i)) {
                case ' ':
                    input_type = KEY_SAPCE;
                    break;
                    
                case '+':
                case '-':
                    input_type = KEY_SIGN;
                    break;
                    
                case 'e':
                    if (flag_exponent)
                        return false;
                    flag_exponent = true;
                    input_type = KEY_EXPONENT;
                    break;
                    
                case '.':
                    input_type = KEY_DOT;
                    break;
                    
                default:
                    input_type = is_digital(s[i]) ? KEY_DIGITAL : KEY_INVALID;
                    break;
            }
            
            pre_status = transitionTable[pre_status][input_type];
            if (pre_status == ST_INVALID) {
                return false;
            }
        }
        return pre_status == ST_DIGITAL || pre_status == ST_DIGITAL_ONLY || pre_status == ST_TAIL_SAPCE || pre_status == ST_DIGITAL_DOT;
    }
private:
    bool flag_exponent;
    enum input_type_e{
        KEY_INVALID,
        KEY_SAPCE,
        KEY_SIGN,
        KEY_DIGITAL,
        KEY_DOT,
        KEY_EXPONENT,
    };
    enum status{
        ST_INVALID = -1,
        ST_HEAD_SPACE,
        ST_SIGN,
        ST_DIGITAL,
        ST_DIGITAL_DOT,
        ST_SPACE_DOT,
        ST_EXPONENT,
        ST_DIGITAL_ONLY,
        ST_TAIL_SAPCE,
        ST_EXPONENT_SIGN,
    };
    bool is_digital(const char &c){
        if (c <= '9' && c >= '0')
            return true;
        else
            return false;
    }
};


#endif /* solution2_h */
