class Solution:
    # @param {string} s
    # @return {string}
    def longestPalindrome(self, s):
        ret = ''
        if len(s) == 1:
            return s
        for index in range(len(s) -1):
            if s[index] == s[index +1]:
                tmp = self.verifyPalindrome(s, index, index +1)
                if len(tmp) >= len(ret):
                    ret = tmp
        for index in range(1, len(s)-1):
            if s[index -1] == s[index +1]:
                tmp = self.verifyPalindrome(s, index -1, index +1)
                if len(tmp) >= len(ret):
                    ret = tmp
        return ret

    def verifyPalindrome(self, s, i, j):
        for var in range(1, len(s)):
            if (i - var) <0 or (j + var) >= len(s) or s[i-var] != s[j+var]:
                return s[i-var+1: j+var]



def main():
    test = Solution()
    strForTest = 'aaaa'
    print test.longestPalindrome(strForTest)

if __name__ == '__main__':
    main()
