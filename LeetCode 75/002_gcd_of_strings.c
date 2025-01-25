// Calculate the gcd of strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int are_concatenations_equal(char* str1, char*str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t total_len = len1 + len2;

    char * c1 = (char*)malloc(total_len + 1);
    char * c2 = (char*)malloc(total_len + 1);
    strcpy(c1, str1);
    strcat(c1, str2);
    strcpy(c2, str2);
    strcat(c2, str1);
    int result = strcmp(c1, c2) == 0;
    free(c1);
    free(c2);
    return result;

}

char* gcdOfStrings(char* str1, char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t total_len = len1 + len2;

    char * result = (char*)malloc(total_len + 1);
    if(!are_concatenations_equal(str1, str2)) {
        return "";
    }
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int gcd_len = gcd(l1, l2);
    strncpy(result, str1, gcd_len);
    result[gcd_len] = '\0';

    return result;
}