'''
Title: Regular Expression Matching
Url: https://leetcode.com/problems/regular-expression-matching/
Author: halibut735
Data: 15.6.24
'''

class Solution:
    # @param {string} s
    # @param {string} p
    # @return {boolean}
    def isMatch(self, s, p):
        print 's=', s, 'p=', p

        '''
        boundary conditions...
        '''
        #when len(s) == 0
        if len(s) == 0 and len(p) == 0:
            return True
        if len(s) != 0 and len(p) == 0:
            return False
        #when when len(p) == 1,which means that the process would go without 'a*' or '.*'
        #p[0] == * represents no regular matches
        if p[0] == '*':
            return False


        #when p[1] != * or len(p) == 1
        if len(p) == 1 or p[1] != '*':
            if p[0] == '.' or (len(s) != 0 and p[0] == s[0]):
                return self.isMatch(s[1:], p[1:])
            else:
                return False
        else:
            return self.starMatch(s, p)

    def starMatch(self, s, p):
        #when p[1] == '*', we need to discuss whether p[0] matches or not
        while p[0] == '.' or (len(s) != 0 and p[0] == s[0]):
            if self.isMatch(s[1:], p):
                return True
        return self.isMatch(s, p[2:])


def main():
    test = Solution()
    print test.isMatch('aa', "a*a")

if __name__ == '__main__':
    main()
