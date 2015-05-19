class Solution:
    # @param {string} s
    # @return {string}
    def longestPalindrome(self, s):
        dict = {}
        if len(s) <= 1:
            return ''
        elif len(s) == 2 and s[0] == s[1]:
            return s[0]
        elif len(s) == 2:
            return ''

        for i in range(len(s)):
            substr = s[i:i+1]
            if substr in dict:
                dict[substr].append(i)
            else:
                dict[substr] = [i]

        while len(dict) >1:
            for eachKey in dict.keys():
                if len(dict[eachKey]) <= 1 :
                    if len(dict) == 1:
                        break
                    del dict[eachKey]
                else:
                    for eachPosition in dict[eachKey]:
                        if eachPosition + len(eachKey) + 1 > len(s):
                            continue
                        substr = s[eachPosition:eachPosition + len(eachKey) +1]
                        if substr in dict:
                            dict[substr].append(eachPosition)
                        else:
                            dict[substr] = [eachPosition]
                    del dict[eachKey]
            print dict
        return dict.keys()[0][0:-1]

def main():
    test = Solution()
    strForTest = '32101232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100ccd'
    print test.longestPalindrome(strForTest)

if __name__ == '__main__':
    main()
