#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int gnc(int* candies, int candiesSize) {
    int max = candies[0];
    for (int i = 1; i < candiesSize; i++) {
        if (max < candies[i]) {
            max = candies[i];
        }
    }
    return max;
}

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int maxCandies = gnc(candies, candiesSize);
    bool* result = (bool*)malloc(candiesSize * sizeof(bool));
    
    for (int i = 0; i < candiesSize; i++) {
        result[i] = (candies[i] + extraCandies >= maxCandies);
    }

    *returnSize = candiesSize;
    return result;
}