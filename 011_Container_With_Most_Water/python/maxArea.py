class Solution:
    # @param {integer[]} height
    # @return {integer}
    def maxArea(self, height):
        #initial ret
        ret = len(height) * abs(height[0] - height[len(height) -1])
        left = 0
        right = len(height) -1
        while(left < right):
            if height[left] < height[right]:
                tmp = left + 1
                while height[tmp] <= height[tmp] and tmp < right:



def main():
    test = Solution()
    test.maxArea()

if __name__ == '__main__':
    main()
