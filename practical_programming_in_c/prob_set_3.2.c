/**
 * @file prob_set_3.2.c
 * @brief Solution for Problem 3.2: Dictionary lookup and user input handling.
 * This file implements a simple dictionary lookup program that loads words from a file,
 * allows the user to input a word, and checks if the word exists in the dictionary.
 * The program includes error handling for file operations and ensures clean user input.
 *
 * Compile with: clang prob_set_3.2.c dict.c -O0 -o dict_lookup
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "dict.h"

const char *FILENAME = "words_definitions.txt";

int main(void)
{
    puts("Loading up the program \n");
    sleep(1);
    if (load_dictionary(FILENAME) == EXIT_FAILURE)
    {
        perror("fopen");
        puts("There was issue loading the words into the Dictionary \n");
        return EXIT_FAILURE;
    }

    bool start = true;
    do
    {
        char USER_INPUT_BUFFER[WORD_LEN];
        get_clean_input(USER_INPUT_BUFFER, WORD_LEN);
        char *lookup_result = lookup(USER_INPUT_BUFFER);
        if (lookup_result == NULL)
        {
            printf("The word %s can not be found in the Dictionary \n", USER_INPUT_BUFFER);
        }
        else
        {
            printf(" %s \n", lookup_result);
        }
        sleep(1);
        puts("Press anykey to continue or Q if you want to quit the program \n");
        char c = getchar();
        if (c == 'q' | c == 'Q')
        {
            puts("Shutting down Program");
            start = false;
        }
    } while (start);
    return EXIT_SUCCESS;
}
