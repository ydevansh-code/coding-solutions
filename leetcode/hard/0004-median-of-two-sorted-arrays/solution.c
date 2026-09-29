double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    // Make nums1 the smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int left = 0;
    int right = nums1Size;

    int total = nums1Size + nums2Size;
    int half = (total + 1) / 2;

    while (left <= right) {

        // Partition nums1
        int partition1 = (left + right) / 2;

        // Partition nums2
        int partition2 = half - partition1;

        int left1  = (partition1 == 0) ? -2147483648 : nums1[partition1 - 1];
        int right1 = (partition1 == nums1Size) ? 2147483647 : nums1[partition1];

        int left2  = (partition2 == 0) ? -2147483648 : nums2[partition2 - 1];
        int right2 = (partition2 == nums2Size) ? 2147483647 : nums2[partition2];

        // Correct partition
        if (left1 <= right2 && left2 <= right1) {

            // Odd total length
            if (total % 2 != 0) {
                return (double)(left1 > left2 ? left1 : left2);
            }

            // Even total length
            int maxLeft = (left1 > left2) ? left1 : left2;
            int minRight = (right1 < right2) ? right1 : right2;

            return ((double)maxLeft + minRight) / 2.0;
        }

        // We took too many elements from nums1
        else if (left1 > right2) {
            right = partition1 - 1;
        }

        // We took too few elements from nums1
        else {
            left = partition1 + 1;
        }
    }

    return 0.0;
}