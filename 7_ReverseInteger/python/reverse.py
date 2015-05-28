class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        flag = 0 #means x is a positive number
        if x < 0:
            flag = 1
            x = -x
        retStr = str(x)[::-1]
        retInt = int(retStr)

        maxInt = 0x7fffffff
        minInt = -1 * maxInt -1
        if retInt > maxInt:
            return 0
        if flag == 1:
            retInt = -1 * retInt
            if retInt < minInt:
                return 0
        return retInt


def main():
    a = Solution()
    print a.reverse(-123)

if __name__ == '__main__':
    main()
