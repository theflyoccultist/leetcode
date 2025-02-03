// You are given an array of integers nums. Return the length of the longest
// subarray of nums which is either
// strictly increasing, or strictly decreasing.

#include <stdio.h>

int longestMonotonicSubarray(int* nums, int numsSize) {
    int jeungga = 1;    // Increase
    int gamso = 1;      // Decrease
    int maxLen = 1;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            gamso++;
            jeungga = 1;
        }
        else if (nums[i] < nums[i + 1]) {
            jeungga++;
            gamso = 1;
        }
        else {
            jeungga = 1;
            gamso = 1;
        }

        if (jeungga > maxLen) maxLen = jeungga;
        if (gamso > maxLen) maxLen = gamso;
    }
    
    return maxLen;
}