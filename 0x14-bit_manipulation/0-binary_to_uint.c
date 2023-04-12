#include "main.h"

/**

unsigned int binary_to_uint(const char *b) {
    if (b == NULL)
        return 0; // Return 0 if the input string is NULL

    unsigned int result = 0; // Initialize the result to 0
    int i = 0; // Initialize an index variable for traversing the string

    // Loop through each character in the string until a null terminator is encountered
    while (b[i] != '\0') {
        if (b[i] == '0' || b[i] == '1') {
            // Shift the current result to the left by 1 bit and add the binary value of the current character
            result = (result << 1) | (b[i] - '0');
            i++; // Move to the next character
        } else {
            return 0; // Return 0 if a non-binary character is encountered
        }
    }

    return result; // Return the converted unsigned integer
}

