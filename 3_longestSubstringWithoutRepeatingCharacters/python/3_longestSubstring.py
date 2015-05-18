class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLongestSubstring(self, s):
        if len(s) == 0:
            return 0
        maxLength = 1
        substr = s[0]
        head = 0
        tail = 1
        while(tail < len(s)):
            tail += 1
            if s[tail - 1] in substr:
                #if there is some char same as s[tial -1],find it out!
                for each in substr:
                    head += 1
                    if each == s[tail -1]:
                        substr = s[head:tail]
                        break
            else:
                substr = s[head:tail]
            if tail - head > maxLength:
                maxLength = tail - head
        return maxLength

def main():
    a = Solution()
    print a.lengthOfLongestSubstring('djdjdjdjdj')

if __name__ == '__main__':
    main()
