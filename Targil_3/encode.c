#include "encriptor.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define KEY "defghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abc"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s src_file dst_file\n", argv[0]);
        return 1;
    }

    // Buffer for Read key from file input
    char input_word[ALPHABET_SIZE + 1]; // +1 is for \0 in the end of the string.

    // Open source file for reading
    FILE *src_file = fopen(argv[1], "r");
    if (src_file == NULL) {
        printf("Error opening source file: %s\n", argv[1]);
        return 1;
    }

    // Open destination file for writing
    FILE *dst_file = fopen(argv[2], "w");
    if (dst_file == NULL) {
        printf("Error opening destination file: %s\n", argv[2]);
        fclose(src_file);
        return 1;
    }

    // Read data from the file into the buffer
    while (fgets(input_word, sizeof(input_word), src_file) != NULL) {
        // Process the data as needed
        printf("input_word is = %s\n", input_word);
    }

    // Close the file
    fclose(src_file);

// Encode the input word:

    // 1. Create the codec:
    void *codec = createCodec(KEY); // assuming that we have the encoding key in advanced.
    if (codec == NULL) {
        printf("Failed to create codec\n");
        return 1;
    }

    // 2. encoding the input word to text:
    // find len of input word:
    size_t input_word_length = strlen(input_word);
    char encoding_word[input_word_length];
    int len = encode(input_word, encoding_word, input_word_length, codec);
    printf("encoded word is: %s\n", encoding_word);
    
    // 3. write encoding_word to output file:
    if (fputs(encoding_word, dst_file) != EOF) {
        printf("String successfully written to the file.\n");
    } else {
        perror("Error writing to the file");
    }

    // Close the file
    fclose(dst_file);

    return 0;
}
