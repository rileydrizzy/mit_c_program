/**
 * @file dict.h
 * @brief Header file for dictionary operations, including loading a dictionary from a file,
 * looking up words, and getting clean user input.
 *
 */

#ifndef DICT_H
#define DICT_H

#define DEF_LEN_MAX 100 // Maximum length of a word definition
#define WORD_LEN 13 // Maximum length of a word (12 characters + null terminator)
#define DICT_MAX_NO 75 // Maximum number of words and their definition in the dictionary

/**
 * @brief loads the dictionary from the file
 * @return EXIT_SUCCESS if the dictionary was loaded successfully, EXIT_FAILURE otherwise
 *
 */
int load_dictionary(const char *file_name);

/**
 * @brief looks up a word in the dictionary and returns it if found
 * @param word the word to look up
 * @return the word if found, NULL otherwise
 *
 */
char *lookup(char *word);

/**
 * @brief gets clean input from the user, removing any trailing newline characters
 * @param user_input the buffer to store the input
 * @return void
 *
 */
void get_clean_input(char *user_input, size_t input_len);

#endif
