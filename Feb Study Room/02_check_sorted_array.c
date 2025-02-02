// Given an array nums, return true if the array was originally sorted in non-decreasing order, 
// then rotated some number of positions (including zero). Otherwise, return false.

#include <stdio.h>
#include <stdbool.h>

bool check(int* nums, int numsSize) {
    int banjeon = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            banjeon ++;
        }
    }

    if (nums[0] < nums[numsSize - 1]) {
        banjeon ++;
    }

    printf("banjeon, %d", banjeon);
    if (banjeon <= 1) return true;
    return false;
}