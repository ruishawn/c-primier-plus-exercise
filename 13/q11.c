// Write a program that takes two command-line arguments. The first is a string; the
// second is the name of a file. The program should then search the file, printing all lines
// containing the string. Because this task is line oriented rather than character oriented,
// use fgets() instead of getc(). Use the standard C library function strstr() (briefly
// described in exercise 7 of Chapter 11 ) to search each line for the string. Assume no lines
// are longer than 255 characters.

#include <stdio.h>
#include <string.h>
#define MAX_LINE 256
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <string> <file>\n", argv[0]);
        return -1;
    }

    FILE *fp;
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        return -1;
    }

    printf("Searching for %s in file %s\n", argv[1], argv[2]);
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp) != NULL)
    {
        if (strstr(line, argv[1]) != NULL)
        {
            printf("%s", line);
        }
    }

    if (fclose(fp) != 0)
    {
        printf("Error closing file %s\n", argv[2]);
        return -1;
    }
    return 0;
}
