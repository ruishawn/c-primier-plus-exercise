// Modify the program in Listing 13.3 so that each word is numbered according to the order
// in which it was added to the list, starting with 1. Make sure that, when the program is
// run a second time, new word numbering resumes where the previous numbering left off.

//--- originnal 13.3 -----------
/* addaword.c -- uses fprintf(), fscanf(), and rewind() */
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 41
// int main(void)
// {
//     FILE *fp;
//     char words[MAX];
//     if ((fp = fopen("wordy", "a+")) == NULL)
//     {
//         fprintf(stdout, "Can't open \"wordy\" file.\n");
//         exit(EXIT_FAILURE);
//     }
//     puts("Enter words to add to the file; press the #");
//     puts("key at the beginning of a line to terminate.");
//     while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
//         fprintf(fp, "%s\n", words);
//     puts("File contents:");
//     rewind(fp); /* go back to beginning of file */
//     while (fscanf(fp, "%s", words) == 1)
//         puts(words);
//     puts("Done!");
//     if (fclose(fp) != 0)
//         fprintf(stderr, "Error closing file\n");
//     return 0;
// }

//--- originnal 13.3 -----------

//--- modified 13.3 -----------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 42
int main(void)
{
    FILE *fp;
    char words[MAX];
    int i = 0;
    int num = 0;
    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    // get last line num
    char *lastline = NULL;
    size_t len1 = 0;
    size_t read1;
    while ((read1 = getline(&lastline, &len1, fp)) != -1)
    {
    }
    if (lastline != NULL)
    {
        char firstChar = lastline[0];
        if (isdigit(firstChar))
        {
            num = atoi(&firstChar);
        }
    }
    if (num != 0)
    {
        num++;
    }

    // append content
    rewind(fp);
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
    {
        fprintf(fp, "%d %s\n", num++, words);
    }

    // printf
    rewind(fp);
    // while (fscanf(fp, "%s", words) == 1)
    //     puts(words);
    // puts("Done!");
    while ((read1 = getline(&lastline, &len1, fp)) != -1)
    {
        printf("%s", lastline);
    }

    // close file
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
    return 0;
}