#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare);

    *returnSize = 0;

    int capacity = 10;

    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {

        // Skip duplicate nums[i]
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        // Since array is sorted
        if (nums[i] > 0)
            break;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {

                // Increase memory if needed
                if (*returnSize == capacity) {
                    capacity *= 2;

                    result = realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes =
                        realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                result[*returnSize] = malloc(3 * sizeof(int));

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Move both pointers
                left++;
                right--;

                // Skip duplicate left values
                while (left < right && nums[left] == nums[left - 1])
                    left++;

                // Skip duplicate right values
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }

            else if (sum < 0) {
                left++;
            }

            else {
                right--;
            }
        }
    }

    return result;
}