// look left and right for flowers

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            int leftisEmpty = (i == 0 || flowerbed[i - 1] == 0);
            int rightisEmpty = (i == flowerbedSize - 1 || flowerbed[i + 1] == 0);
            
            if (leftisEmpty && rightisEmpty) {
                i++;
                count++;
            }
        }
    }
    printf("%d", count);
    if (count >= n) {
        return true;
    } else {
        return false;
    }
}