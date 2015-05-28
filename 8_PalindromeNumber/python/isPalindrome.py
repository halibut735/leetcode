class Solution:
    # @param {integer} x
    # @return {boolean}
    def isPalindrome(self, x):
        if x < 0:
            return False
        x = abs(x)
        lengthOfX = len(str(x))
        for i in range(lengthOfX/2):
            if str(x)[lengthOfX-1-i] != str(x)[i]:
                return False
        return True

def main():
    a = Solution()
    print a.isPalindrome(-2147447412)

if __name__ == '__main__':
    main()
