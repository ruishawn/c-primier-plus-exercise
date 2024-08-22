// Write a program that takes as command-line arguments a character and zero or more
// filenames. If no arguments follow the character, have the program read the standard
// input. Otherwise, have it open each file in turn and report how many times the character
// appears in each file. The filename and the character itself should be reported along with
// the count. Include error-checking to see whether the number of arguments is correct and
// whether the files can be opened. If a file can’t be opened, have the program report that
// fact and go on to the next file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countNum(char c, char *filename);
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s char [file ...]\n", argv[0]);
        exit(1);
    }

    if (strlen(argv[1])>1){
        printf("Usage: %s char [file ...]\n", argv[0]);
        exit(1);
    }


    char c = *argv[1];
    if (argc == 2)
    {
        char *filename;
        printf("Please input the file name, input q quit:\n");
        scanf("%s", filename);
        while (strcmp(filename, "q") != 0)
        {
            if (countNum(c, filename) != 0)
            {
                printf("Please input the file name, input q quit:\n");
                scanf("%s", filename);
                continue;
            }
            printf("Please input the file name, input q quit:\n");
            scanf("%s", filename);
        }
    }
    else
    {
        for (int i = 2; i < argc; ++i)
        {
            int tmp = countNum(c, argv[i]);
            if (tmp != 0)
            {
                continue;
            }
        }
    }
}

int countNum(char c, char *filename)
{
    FILE *fp;
    int count = 0;
    char ch;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Can't open: %s\n", filename);
        return -1;
    }
    while ((ch = getc(fp)) != EOF)
    {
        if (c == ch)
        {
            count++;
        }
    }
    printf("The char %c appears in the file %s is: %d\n", c, filename, count);
    fclose(fp);
    return 0;
}