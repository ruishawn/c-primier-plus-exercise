//  3. Write a file copy program that prompts the user to enter the name of a text file to act as
// the source file and the name of an output file. The program should use the toupper()
// function from ctype.h to convert all text to uppercase as it’s written to the output file.
// Use standard I/O and the text mode.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    FILE *source, *target;
    char sourcefile[100], targetfile[100];
    printf("Enter the source file name: ");

    scanf("%s", sourcefile);
    if ((source = fopen(sourcefile, "r")) == NULL)
    {
        printf("Can't open %s.\n", sourcefile);
        exit(1);
    }

    printf("Enter the target file name: ");
    scanf("%s", targetfile);
    if ((target = fopen(targetfile, "w")) == NULL)
    {
        printf("Can't open %s.\n", targetfile);
        exit(1);
    }
    

    int buffer_size = 1024;
    char buffer[buffer_size];
    size_t byteread;

    while ((byteread = fread(buffer, 1, buffer_size, source)) > 0)
    {
        for (int i = 0; i < byteread; ++i)
        {
            buffer[i] = toupper(buffer[i]);
        }
        if (fwrite(buffer, 1, byteread, target) != byteread)
        {
            perror("Failed to write to destination file");
            fclose(source);
            fclose(target);
            return 1;
        }
    }

    fclose(source);
    fclose(target);
    return 0;
}