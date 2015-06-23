class Solution:
    # @param {string} str
    # @return {integer}
    def myAtoi(self, str):
        FlagOfNegative = False
        MaxInteger = 2147483647
        MinInteger = -2147483648
        ret = 0
        if str == None or str == '':
            return 0
        while str[0] == ' ':
            str = str[1:]
        if str[0] == '-' :
            FlagOfNegative = not FlagOfNegative
            str = str[1:]
        elif str[0] == '+':
            str = str[1:]
        if str[0] > '9' or str[0] < '0':
            return 0
        for each in str:
            if each <='9' and each >= '0':
                ret = ret *10 + int(each)
            else:
                break
        if FlagOfNegative:
            ret = -1 * ret
        if ret > MaxInteger:
            return MaxInteger
        elif ret < MinInteger:
            return MinInteger
        return ret

def main():
    test = Solution()
    print test.myAtoi('   -1434aa32000')

if __name__ == '__main__':
    main()
