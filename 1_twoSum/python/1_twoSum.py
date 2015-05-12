from copy import deepcopy
class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target):
        positionRecord = deepcopy(nums)
        nums.sort()
        a, b = self.findSuitableIndices(nums, 0, len(nums)-1, target)
        while(nums[a] + nums[b] != target):
            a ,b = self.findSuitableIndices(nums, a+1, b, target)
        indexa = 0
        indexb = len(nums) -1
        while(positionRecord[indexa] != nums[a]):
            indexa += 1;
        while(positionRecord[indexb] != nums[b]):
            indexb -= 1;
        return (indexa+1, indexb+1)

    def findSuitableIndices(self, nums, a, b, target):
        for i in range(b, a, -1):
            if nums[a] + nums[i] == target:
                return (a, i)
            if nums[a] + nums[i] < target:
                return (a, i)

def main():
    testNums = [0, 4 , 3, 0]
    target = 0
    sol = Solution();
    print sol.twoSum(testNums, target)

if __name__ == '__main__':
    main()
