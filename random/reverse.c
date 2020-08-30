#include <stdio.h>
#include <strings.h>

void reverseStringPointers(char *str) {
    int i, j;
    char ch, *start_ptr, *end_ptr;
    start_ptr = str;
    end_ptr = str;
    for (i = 0; i < strlen(str) -1; i++) {
        end_ptr++;
    }

    printf("Start pointer: %p, end pointer: %p", start_ptr, end_ptr);

    for (i = 0; i < strlen(str) / 2; i++) {
        ch = *end_ptr;
        *end_ptr = *start_ptr;
        *start_ptr = ch;
        start_ptr++;
        end_ptr--;
    }
}

void reverseStringLoc(char *str) {
    int length = strlen(str);
    for (int i=0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length -1 -i];
        str[length -1 -i] = temp;
    }
}

void passString(char str[]) {
    printf("String is %s\n", str);
    printf("Second character is %c\n", str[1]);
}

int main() {
    char testString[] = "Greetings people of Earth.";
    printf("%lu length\n", strlen(testString));
    // reverseStringPointers(testString);
    reverseStringLoc(testString);
    printf("%s\n", testString);
    passString(testString);
    return 0;
}