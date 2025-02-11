#include <ctype.h>
#include <string.h>

char* clearDigits(char* s) {
    int len = strlen(s);
    char* stakkeu = (char*)malloc((len + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            if (top >= 0) {
                top--;  // pop
            }
        } else{
            stakkeu[++top] = s[i];  // push
        }
    }

    char* output = (char*)malloc((top + 2) * sizeof(char));
    for (int i = 0; i <= top; i++){
        output[i] = stakkeu[i];
    }
    output[top + 1] = '\0';
    free(stakkeu);
    return output;
}