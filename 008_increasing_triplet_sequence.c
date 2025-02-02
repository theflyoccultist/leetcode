// Given an integer array nums, return true if there exists a triple of indices (i, j, k) 
// such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

bool increasingTriplet(int* nums, int numsSize) {
    int first = INT_MAX;
    int second = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= first)
            first = nums[i];
        else if (nums[i] <= second)
            second = nums[i];
        else
            return true;
    }

    return false;
}