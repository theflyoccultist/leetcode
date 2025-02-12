#include <stdio.h>

int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void twoLargestDigitSums(int* nums, int numsSize, int* maxNums, int* secondMaxNums) {
    for (int i = 0; i < numsSize; i++) {
        int ds = digitSum(nums[i]);

        if (nums[i] > maxNums[ds]) {
            secondMaxNums[ds] = maxNums[ds];
            maxNums[ds] = nums[i];
        } else if (nums[i] > secondMaxNums[ds]) {
            secondMaxNums[ds] = nums[i];
        }
    }
}

int maximumSum(int* nums, int numsSize) {
    int maxNums[91] = {0};
    int secondMaxNums[91] = {0};

    twoLargestDigitSums(nums, numsSize, maxNums, secondMaxNums);

    int maxSum = -1;
    for (int ds = 0; ds < 91; ds++) {
        if (secondMaxNums[ds] > 0) {
            int sum = maxNums[ds] + secondMaxNums[ds];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }

    return maxSum;
}