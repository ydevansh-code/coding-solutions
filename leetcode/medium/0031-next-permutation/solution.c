void nextPermutation(int* nums, int numsSize) {

    int i = numsSize - 2;

    // 1. Find the first decreasing element
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // If found
    if (i >= 0) {

        // 2. Find element just greater than nums[i]
        int j = numsSize - 1;

        while (nums[j] <= nums[i]) {
            j--;
        }

        // Swap
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // 3. Reverse the remaining part
    int left = i + 1;
    int right = numsSize - 1;

    while (left < right) {

        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;

        left++;
        right--;
    }
}
