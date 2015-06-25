class Solution:
    # @param {string[]} strs
    # @return {string}
    def longestCommonPrefix(self, strs):
        if len(strs) == 0:
            return ''
        elif len(strs) == 1:
            return strs[0]
        shortestStr = strs[0]
        lenOfshortest = len(strs[0])
        for each in strs:
            if len(each) < lenOfshortest:
                shortestStr = each
                lenOfshortest = len(each)

        ret = self.commonPrefix(shortestStr, strs[0])
        for each in strs:
            ret = self.commonPrefix(ret, each)
        return ret


    def commonPrefix(self, str1, str2):
        print 'str1', str1, 'str2', str2
        ret = ''
        for i in range(len(str1)):
            if str1[i] == str2[i]:
                ret = ret + str1[i]
            else:
                break
        return ret


def main():
    test = Solution()
    print test.commonPrefix('aa', 'aab')

if __name__ == '__main__':
    main()
