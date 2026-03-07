/**
 * @file dict.c
 * @brief This file implements the functions declared in dict.h for loading a dictionary from a file,
 * looking up words, and getting clean user input.
 *  It includes error handling for file operations and string manipulation to ensure robust functionality.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include "dict.h"

static char the_dictionary[DICT_MAX_NO][DEF_LEN_MAX];

int load_dictionary(const char *file_name)
{
    FILE *file;
    file = fopen(file_name, "r");
    if (file == NULL)
    {
        return EXIT_FAILURE;
    }

    int dict_index = 0;
    char line[DEF_LEN_MAX];

    while ((fgets(line, DEF_LEN_MAX, file) != NULL) && (dict_index < DICT_MAX_NO))
    {
        // Remove newline character if present
        line[strcspn(line, "\n")] = 0;
        strncpy(the_dictionary[dict_index], line, DEF_LEN_MAX - 1);
        the_dictionary[dict_index][DEF_LEN_MAX - 1] = '\0';
        dict_index += 1;
    }

    fclose(file);
    return EXIT_SUCCESS;
}

char *lookup(char *word)
{
    for (int i = 0; i < DICT_MAX_NO; i++)
    {
        char *word_2 = the_dictionary[i];
        size_t n = 0;
        while (word_2[n] && isalpha((unsigned char)word_2[n]))
            n++;
        if ((strlen(word) == n) && strncmp(word_2, word, n) == 0)
            return word_2;
    }
    return NULL;
}

void get_clean_input(char *user_input, size_t input_len)
{
    puts("Enter the word you want to look up \n");
    fgets(user_input, input_len, stdin);
    char *p = strchr(user_input, '\n');
    if (p)
    {
        *p = '\0';
    }
    else
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
}
