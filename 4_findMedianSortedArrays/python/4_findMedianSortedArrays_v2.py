class Solution:
    # @param {integer[]} nums1
    # @param {integer[]} nums2
    # @return {float}
#    def __init__(self):
#       self.count = 0
    def findMedianSortedArrays(self, nums1, nums2):
        #self.count += 1
        #print self.count
        endIndexOfNums1 = len(nums1) -1
        endIndexOfNums2 = len(nums2) -1
        #print 'nums1', nums1, 'nums2', nums2
        if endIndexOfNums1 <= 1:
            tmp = nums2
            if endIndexOfNums1 == 0:
                tmp = self.insertSort(nums1[0], nums2)
            elif endIndexOfNums1 == 1:
                tmp = self.insertSort(nums1[1], self.insertSort(nums1[0], nums2))
            #print (tmp[len(tmp)/2] + tmp[(len(tmp) -1)/2]) /2, 'final tmp', tmp
            ret = (tmp[len(tmp)/2] + tmp[(len(tmp) -1)/2]) /2.0
            return ret
        if endIndexOfNums2 <= 1:
            return self.findMedianSortedArrays(nums2, nums1)
        if nums1[endIndexOfNums1/2] <= nums2[endIndexOfNums2/2]:
            if endIndexOfNums1 <= endIndexOfNums2:
                return self.findMedianSortedArrays(nums1[endIndexOfNums1/2:], nums2[:endIndexOfNums2 - endIndexOfNums1/2 +1])
            else:
                return self.findMedianSortedArrays(nums2[:endIndexOfNums2/2 + 1], nums1[endIndexOfNums2 - endIndexOfNums2/2 :])
        else:
            return self.findMedianSortedArrays(nums2, nums1)
    def insertSort(self, tmp, nums):
        #print 'tmp', tmp, 'nums', nums
        if len(nums) == 0:
            nums = []
            nums.append(tmp)
            #print nums
            return nums
        if tmp == nums[len(nums)/2]:
            return nums[:len(nums)/2 +1] + nums[len(nums)/2:]
        elif tmp < nums[len(nums)/2]:
            return self.insertSort(tmp, nums[:len(nums)/2]) + nums[len(nums)/2:]
        else:
            return nums[:len(nums)/2 +1] + self.insertSort(tmp, nums[len(nums)/2 +1:])

def main():
    a = Solution()
    print a.findMedianSortedArrays([1,2,3,4,5,6,7], [2, 4, 7, 9])


if __name__ == '__main__':
    main()
