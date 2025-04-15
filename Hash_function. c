#include <stdio.h>

// Simple hash function (djb2)
unsigned long simple_hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    // Process each character of the string
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    }

    return hash;
}

int main() {
    const char *input_string = "VS";  // Example input string
    unsigned long hash_value;

    // Calculate hash value
    hash_value = simple_hash(input_string);

    // Print the hash value
    printf("Hash value of '%s' is: %lu\n", input_string, hash_value);

    return 0;
}

OUTPUT:

Hash value of 'VS' is: 5862830
