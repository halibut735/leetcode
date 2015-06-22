class Solution:
    # @param {integer[]} nums1
    # @param {integer[]} nums2
    # @return {float}
    def findMedianSortedArrays(self, nums1, nums2):
        total = len(nums1) + len(nums2)
        if total % 2:
            return self.findKth(nums1, nums2, total/2 +1)
        else:
            return (self.findKth(nums1, nums2, total/2) + self.findKth(nums1, nums2, total/2 +1))/2.0

    def findKth(self, nums1, nums2, k):
        if len(nums1) > len(nums2):
            return self.findKth(nums2, nums1, k)
        if len(nums1) == 0:
            return nums2[k-1]
        if k == 1:
            return min(nums1[0], nums2[0])
        partionOfnum1 = min(len(nums1), k/2)
        partionOfnum2 = k - partionOfnum1
        if nums1[partionOfnum1 -1]  == nums2[partionOfnum2 -1]:
            return nums1[partionOfnum1 -1]
        elif nums1[partionOfnum1 -1] < nums2[partionOfnum2 -1]:
            return self.findKth(nums1[partionOfnum1:], nums2, k -partionOfnum1)
        else:
            return self.findKth(nums1, nums2[partionOfnum2:], k -partionOfnum2)


def main():
    nums1 = [3, 3, 6]
    nums2 = [2, 4, 6]
    a = Solution()
    print a.findMedianSortedArrays(nums1, nums2)

if __name__ == '__main__':
    main()
