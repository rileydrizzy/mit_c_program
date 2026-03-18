#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    int nfiles = --argc;
    int argidx = 1;
    char *current_file = "";
    char c;
    unsigned long nums_words = 0, nums_lines = 0, nums_chars = 0;
    if (nfiles == 0)
    {
        fp = stdin;
        nfiles++;
    }
    else
    {
        current_file = argv[argidx++];
        fp = fopen(current_file, "r");
    }

    while (nfiles > 0)
    {
        if (fp == NULL)
        {
            fprintf(stderr, "unable to open input \n");
            exit(EXIT_FAILURE);
        }
        nums_chars = nums_words = nums_lines = 0;

        while ((c = getc(fp) != EOF))
        {
            // TODO PROCESS THE FILE USING THE GETC(FP)
            nums_chars++;
            if (c == '\n')
                nums_lines++;
        }
        printf("File Name - %s\nNumber of char - %ld \nNumber of word - %ld \nNumber of lines - %ld\n ",
               current_file, nums_chars, nums_words, nums_lines);
        nfiles--;
        if (nfiles > 0)
        {
            current_file = argv[argidx++];
            fp = fopen(current_file, "r");
        }
    }
    return EXIT_SUCCESS;
}
