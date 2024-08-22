// Write a program that opens two files. You can obtain the filenames either by using
// command-line arguments or by soliciting the user to enter them.
//  a. Have the program print line 1 of the first file, line 1 of the second file, line 2 of the
// first file, line 2 of the second file, and so on, until the last line of the longer file (in
// terms of lines) is printed.
//  b. Modify the program so that lines with the same line number are printed on the
// same line.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1024
int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char file1[MAXLEN], file2[MAXLEN];
    char ch1, ch2;

    if (argc != 3)
    {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    strncpy(file1, argv[1], MAXLEN);
    strncpy(file2, argv[2], MAXLEN);

    if ((fp1 = fopen(file1, "r")) == NULL)
    {
        fprintf(stderr, "Error opening %s\n", file1);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(file2, "r")) == NULL)
    {
        fprintf(stderr, "Error opening %s\n", file2);
        exit(EXIT_FAILURE);
    }

    // print line 1 of the first file, line 1 of the second file, and so on
    char *line1 = NULL;
    char *line2 = NULL;
    size_t len1 = 0;
    size_t len2 = 0;
    size_t read1, read2;

    puts("a answer:");
    while (1)
    {
        read1 = getline(&line1, &len1, fp1);
        read2 = getline(&line2, &len2, fp2);

        if (read1 == -1 && read2 == -1)
        {
            break;
        }

        if (read1 != -1)
        {
            printf("%s", line1);
        }
        if (read2 != -1)
        {
            printf("%s", line2);
        }
    }

    // same line number are printed on the same line.
    puts("b answer:");
    rewind(fp1);
    rewind(fp2);
    while (1)
    {
        read1 = getline(&line1, &len1, fp1);
        read2 = getline(&line2, &len2, fp2);

        if (read1 == -1 && read2 == -1)
        {
            break;
        }

        if (read1 == -1)
        {
            line1 = "";
        }
        if (read2 == -1)
        {
            line2 = "";
        }

        if (read1 != -1 && read2 != -1)
        {
            line1 = strtok(line1, "\n");
        }
        printf("%s%s", line1, line2);
    }

    // close file
    fclose(fp1);
    fclose(fp2);

    // return
    return 0;
}
