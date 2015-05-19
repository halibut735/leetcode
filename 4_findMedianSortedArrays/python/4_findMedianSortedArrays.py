class Solution:
    # @param {integer[]} nums1
    # @param {integer[]} nums2
    # @return {float}
    def findMedianSortedArrays(self, nums1, nums2):
        head1 = 0
        head2 = 0
        tail1 = len(nums1)
        tail2 = len(nums2)
        middle1 = len(nums1) /2
        middle2 = len(nums2) /2
        if nums1[middle1] == nums2[middle2]:
            return nums1[middle2]
        elif nums1[middle1] < nums2[middle2]:
            nums1, nums2 = nums2, nums1
        else:
            while True:
                if nums1[middle1] > nums2[middle2]:
                    tail1 = middle1 + 1
                    head2 = middle2 - 1
                    middle1 = middle1 /2
                    middle2 = (tail2 + middle2) /2
                elif nums1[middle1] == nums2[middle2]:
                    return nums1[middle1]
                else:


def main():
    nums1 = [3, 3, 6]
    nums2 = [2, 4, 6]
    a = Solution()
    print a.findMedianSortedArrays(nums1, nums2)

if __name__ == '__main__':
    main()
