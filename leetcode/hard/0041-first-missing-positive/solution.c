int firstMissingPositive(int* nums, int numsSize) {

    int i = 0;

    // Put each number at its correct position
    while (i < numsSize) {

        int correctIndex = nums[i] - 1;

        if (nums[i] > 0 &&
            nums[i] <= numsSize &&
            nums[i] != nums[correctIndex]) {

            // Swap nums[i] with nums[correctIndex]
            int temp = nums[i];
            nums[i] = nums[correctIndex];
            nums[correctIndex] = temp;
        }
        else {
            i++;
        }
    }

    // Find the first number which is not in its correct place
    for (i = 0; i < numsSize; i++) {

        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // If 1...numsSize are all present
    return numsSize + 1;
}