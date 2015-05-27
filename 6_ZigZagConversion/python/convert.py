class Solution:
    # @param {string} s
    # @param {integer} numRows
    # @return {string}
    def convert(self, s, numRows):
        ret = ''
        if numRows == 1:
            return s
        dict = {}
        charCount = 0
        for i in range(numRows):
            dict[i] = ''
        while charCount < len(s):
            for i in range(numRows):
                if charCount == len(s):
                    break
                dict[i] += s[charCount]
                charCount += 1
            for i in range(numRows - 2):
                if charCount == len(s):
                    break
                dict[numRows -i -2] += s[charCount]
                charCount += 1
        for eachKey in dict:
            ret += dict[eachKey]
        return ret

def main():
    a = Solution()
    print a.convert('PAYPALISHIRING', 2)

if __name__ == '__main__':
    main()
