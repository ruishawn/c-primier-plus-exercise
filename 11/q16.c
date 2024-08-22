//  Write a program that reads input until end-of-file and echoes it to the display. Have the
// program recognize and implement the following command-line arguments:
// -p Print input as is
// -u Map input to all uppercase
// -l Map input to all lowercase
// Also, if there are no command-line arguments, let the program behave as if the –p
// argument had been used.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;
    char c;
    for (i = 1; i < argc; ++i)
    {
        if (!strcmp(argv[i], "-p"))
        {
            while ((c = getchar()) != EOF)
                putchar(c);
        }
        else if (!strcmp(argv[i], "-u"))
        {
            while ((c = getchar()) != EOF)
                putchar(toupper(c));
        }
        else if (!strcmp(argv[i], "-l"))
        {
            while ((c = getchar()) != EOF)
                putchar(tolower(c));
        }
    }
}