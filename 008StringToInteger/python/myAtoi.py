class Solution:
    # @param {string} str
    # @return {integer}
    def myAtoi(self, str):
        FlagOfNegative = False
        MaxInteger = 2147483647
        MinInteger = -2147483648
        ret = 0
        if str == None or str == '':
            return
        if str[0] == '-' :
            FlagOfNegative = True
            str = str[1:]
        if str[0] == '+':
            str = str[1:]
        for each in str:
            if each <'9' and each > '0':
                ret = ret *10 + int(each)
        if FlagOfNegative:
            ret = -1 * ret
        if ret > MaxInteger or ret < MinInteger:
            return 0
        return ret

def main():
    test = Solution()
    print test.myAtoi('-143432')

if __name__ == '__main__':
    main()
