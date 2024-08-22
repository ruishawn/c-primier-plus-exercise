// Write a program that opens a text file whose name is obtained interactively. Set up a
// loop that asks the user to enter a file position. The program then should print the part of
// the file starting at that position and proceed to the next newline character. Let negative
// or nonnumeric input terminate the user-input loop.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char filename[1024];
    printf("Enter the file name:");
    scanf("%1023s", filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("Enter the file position: ");
    int position;
    while (scanf("%d", &position) == 1 && position >= 0)
    {
        fseek(fp, position, SEEK_SET);
        char ch = fgetc(fp);
        while (ch != '\n' && ch != EOF)
        {
            printf("%c", ch);
            ch = fgetc(fp);
        }
        printf("\nEnter file position, enter negative or nonumeric terminate: ");
    }
    if (fclose(fp) != 0)
    {
        printf("Error closing file.\n");
    }

    return 0;
}