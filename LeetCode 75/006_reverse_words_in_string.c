// Return a string of the words in reverse order concatenated by a single space.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** splitString(const char* str, int* count) {
    char* strCopy = strdup(str);
    char* token = strtok(strCopy, " ");
    char** result = NULL;
    *count = 0;

    while (token != NULL) {
        result = realloc(result, sizeof(char*) * (*count + 1));
        result[*count] = strdup(token);
        (*count)++;
        token = strtok(NULL, " ");
    }

    free(strCopy);
    return result;
}

void remove_double_space(char* s) {
    char *copy = s;
    int space_found = 0;

    while (*s != '\0') {
        if (*s == ' ') {
            if (!space_found) {
                *copy++ = *s;
                space_found = 1;
            }
        } else {
            *copy++ = *s;
            space_found = 0;
        }
        s++;
    }

    if (copy > s && *(copy - 1) == ' ') {
        copy--;
    }
    *copy = '\0';
}

char* reverseWords(char* s) {
    remove_double_space(s);
    
    int count;
    char** words = splitString(s, &count);

    int left = 0;
    int right = count - 1;

    while (left < right) {
        char* temp = words[left];
        words[left] = words[right];
        words[right] = temp;
        left++;
        right--;
    }
    char* current = s; // Pointer to rebuild the string
    for (int i = 0; i < count; i++) {
        int len = strlen(words[i]);
        memcpy(current, words[i], len); // Copy the word into `s`
        current += len;

        if (i < count - 1) { // Add a space between words
            *current = ' ';
            current++;
        }
    }
    *current = '\0';

    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    free(words);
    return s;
}