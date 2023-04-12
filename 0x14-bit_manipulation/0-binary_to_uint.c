#include "main.h"

/**
unsigned int binary_to_uint(const char *b) {
    if (b == NULL) {
        return 0; // Return 0 if the input string is NULL
    }

    unsigned int result = 0;
    int i = 0;

    while (b[i] != '\0') {
        if (b[i] == '0' || b[i] == '1') {
            result = result << 1; // Shift the current result left by 1
            if (b[i] == '1') {
                result = result | 1; // Set the least significant bit to 1 if the current char is '1'
            }
            i++;
        } else {
            return 0; // Return 0 if there is a char in the string that is not '0' or '1'
        }
    }

    return result;
}

