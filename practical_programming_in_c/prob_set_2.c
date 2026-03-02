/**
 * @file prob_set_2.c
 * @brief Contains  solutions for character classification and bitwise operations for Problem 2.
 *
 * This file includes solutions for checking character types (lowercase, uppercase,
 * digits, whitespace) and performing bitwise manipulations such as checking bit
 * patterns, reversing bytes, and rotating bits.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Checks the category of a given character.
 *
 * Prints whether the character is lowercase, uppercase, a digit, or whitespace.
 *
 * @param var The character to be checked.
 */
void char_check(char var)
{

    if (var >= 'a' && var < 'z')
    {
        printf("This is a lower case character \n");
    }
    else if (var >= 'A' && var <= 'Z')
    {
        printf("This is a upper case character \n");
    }
    else if (var >= '0' && var <= '9')
    {
        printf("This is a digits \n");
    }
    else if (var == '\t' || var == '\n' || var == ' ')
    {
        printf("This is a white space \n");
    }
}

/**
 * @brief Checks if at least three of the last four bits of an integer are set.
 *
 * @param val The integer value to inspect.
 */
void is_set(int val)
{
    int mask = 15;
    int last_4_bits = val & mask; //
    if (last_4_bits == 0xF || last_4_bits == 0xB || last_4_bits >= 0xD)
        puts("At least three of the last four bits are on");
    else
        puts("Less than three of the last four bits are on");
}

/**
 * @brief Reverses the byte order of a 16-bit value.
 *
 * Swaps the lower 8 bits with the next 8 bits (e.g., 0xCAFE becomes 0xFECA).
 *
 * @param val The integer containing the bytes to reverse.
 */
void reverse_byte(int val)
{
    int mask = 0xFF;
    int reverse_ans = ((mask & val) << 8) | (val >> 8);
    printf("The reverse_byte of %X is => %X \n", val, reverse_ans);
}

/**
 * @brief Rotates the bits of a 16-bit value to the right by 4 bits.
 *
 * Moves the least significant nibble to the most significant position of a 16-bit word.
 *
 * @param val The integer to rotate.
 */
void rotate_bits(int val)
{
    int mask = 0xF;
    int rotated_bits = ((mask & val) << 12 | val >> 4);
    printf("The rotated bits of %X by four bits is => %X \n", val, rotated_bits);
}

/**
 * @brief Entry point of the program.
 *
 * This function demonstrates several utility operations:
 *  - Character classification/check
 *  - Bit checking on an integer value
 *  - Byte reversal
 *  - Bit rotation
 *
 * The integer value used for testing is 0xCAFE.
 */

int main()
{

    // Character test section
    char lower_char = 'c';
    char upper_char = 'C';
    int nums = 4;
    char space_char = ' ';
    char tab_char = '\t';

    char_check(lower_char);

    char_check(upper_char);

    char_check(nums);

    char_check(space_char);

    char_check(tab_char);

    int val = 0xCAFE;

    // Checks whether specific bits are set in the integer value.

    is_set(val);

    // Reverses the byte order of the integer.
    reverse_byte(val);

    // Performs a bit rotation operation
    rotate_bits(val);
}