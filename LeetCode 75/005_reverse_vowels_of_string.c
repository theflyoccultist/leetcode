// Input: s = "IceCreAm"
// Output: "AceCreIm"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* arr, int i, int j) {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

char* reverseVowels(char* s) {
    char vowels[] = "aeiouAEIOU";
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        while (left < right && strchr(vowels, s[left]) == NULL) {
            left++;
        }
        while (right > left && (strchr(vowels, s[right]) == NULL)) {
            right--;
        }
        if (left < right) {
            swap(s, left, right);
            left++;
            right--;
        }
    }
    return s;
}