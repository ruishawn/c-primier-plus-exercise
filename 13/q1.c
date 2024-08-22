// 1. Modify Listing 13.1 so that it solicits the user to enter the filename and reads the user’s
// response instead of using command-line arguments.

/* count.c -- using standard I/O */
#include <stdio.h>
#include <stdlib.h> // exit() prototype
#define MAX_LEN 1024
// origin code

// int main(int argc, char *argv[])
// {
//     int ch;   // place to store each character as read
//     FILE *fp; // "file pointer"
//     unsigned long count = 0;
//     if (argc != 2)
//     {
//         printf("Usage: %s filename\n", argv[0]);
//         exit(EXIT_FAILURE);
//     }
//     if ((fp = fopen(argv[1], "r")) == NULL)
//     {
//         printf("Can't open %s\n", argv[1]);
//         exit(EXIT_FAILURE);
//     }
//     while ((ch = getc(fp)) != EOF)
//     {
//         putc(ch, stdout); // same as putchar(ch);
//         count++;
//     }
//     fclose(fp);
//     printf("File %s has %lu characters\n", argv[1], count);
//     return 0;
// }

int main(void)
{
    int ch;
    FILE *fp;
    unsigned long count = 0;
    char filename[MAX_LEN];
    printf("Enter the filename: ");
    scanf("%255s", filename);
    if ((fp = fopen(filename, "r")) == NULL){
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp))!=EOF){
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", filename, count);
    return 0;
}