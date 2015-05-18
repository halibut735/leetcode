class Solution:
    # @param {integer[]} nums1
    # @param {integer[]} nums2
    # @return {float}
    def findMedianSortedArrays(self, nums1, nums2):
        head1 = 0
        tail1 = len(nums1)
        head2 = 0
        tail2 = len(nums2)
        while(head1 != tail1 -1):
            #if two elemetes are left in each nums array
            if head1 == tail1 - 2:
                if nums1[head1] <=  nums2[head2] and nums1[head1 + 1] >= nums2[head2 + 1]:
                    return (nums2[head2 + 1] + nums2[head2])/2.0
                if nums1[head1] >=  nums2[head2] and nums1[head1 + 1] <= nums2[head2 + 1]:
                    return (nums1[head1 + 1] + nums1[head1])/2.0

                if nums1[head1] <= nums1[head1 + 1]:
                    if nums2[head2] <= nums2[head2 + 1]:
                        if nums2[head2] >= nums1[head1 + 1]:
                            return (nums1[head1 + 1] + nums2[head2])/2.0
                        else:
                            return (nums1[head1] + nums2[head2 + 1])/2.0
                    else:
                        if nums2[head2 + 1] >= nums1[head1 + 1]:
                            return (nums1[head1 + 1] + nums2[head2 + 1])/2.0
                        else:
                            return (nums1[head1] + nums2[head2])/2.0
                else:
                    if nums2[head2] <= nums2[head2 + 1]:
                        if nums2[head2] >= nums1[head1]:
                            return (nums1[head1] + nums2[head2])/2.0
                        else:
                            return (nums1[head1 + 1] + nums2[head2 + 1])/2.0
                    else:
                        if nums2[head2 + 1] >= nums1[head1]:
                            return (nums1[head1] + nums2[head2 + 1])/2.0
                        else:
                            return (nums1[head1 + 1] + nums2[head2])/2.0

            middle1 = (head1 + tail1) /2
            middle2 = (head2 + tail2) /2
            if nums1[middle1] <= nums2[middle2]:
                head1 = head1 - tail2 + middle2
                tail2 = middle2
            else:
                head2 = head2 - tail1 - middle1
                tail1 = middle1
        return (nums1[head1] + nums2[head2])/2.0

def main():
    nums1 = [3, 3, 6]
    nums2 = [2, 4, 6]
    a = Solution()
    print a.findMedianSortedArrays(nums1, nums2)

if __name__ == '__main__':
    main()
