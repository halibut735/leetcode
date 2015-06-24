class Solution:
    # @param {string} s
    # @param {string} p
    # @return {boolean}
    def __init__(self):
        self.isRepeat = []
    def isMatch(self, s, p):
        print 's=', s, 'p=', p

        #cut operation
        tmp  = [s, p]
        if tmp in self.isRepeat:
            return
        else:
            self.isRepeat.append(tmp)

        #when len(s) == 0
        if len(s) == 0:
            if (len(p) == 2 and p[1] == '*') or len(p) == 0:
                return True
            if len(p) >= 2 and p[1] == '*':
                return self.starMatch(s, p)
            else:
                return False
        if len(s) != 0 and len(p) == 0:
            return False
        #when when len(p) == 1,which means that the process would go without 'a*' or '.*'
        if len(p) == 1:
            if p[0] == '*':
                return False
            elif p[0] == '.' and len(s) == 1:
                return True
            elif s == p:
                return True
            else:
                return False
        #p[0] == * represents no regular matches
        if p[0] == '*':
            return False
        if p[1] != '*':
            if p[0] == '.':
                return self.isMatch(s[1:], p[1:])
            else:
                if p[0] == s[0]:
                    return self.isMatch(s[1:], p[1:])
                else:
                    return False
        else:
            return self.starMatch(s, p)

    def starMatch(self, s, p):
        '''
        when p[1] == '*', we need to discuss whether p[0] matches or not
        '''
        if len(s) != 0 and (p[0] == s[0] or p[0] == '.'):
            return  self.isMatch(s[1:], p) or self.isMatch(s, p[2:])
        else:
            return self.isMatch(s, p[2:])


def main():
    test = Solution()
    print test.isMatch("a", "a*a")

if __name__ == '__main__':
    main()
