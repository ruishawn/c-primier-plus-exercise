// Create a text file consisting of 20 rows of 30 integers. The integers should be in the range
// 0–9 and be separated by spaces. The file is a digital representation of a picture, with
// the values 0 through 9 representing increasing levels of darkness. Write a program that
// reads the contents of the file into a 20-by-30 array of ints. In a crude approach toward
// converting this digital representation to a picture, have the program use the values
// in this array to initialize a 20-by-31 array of chars, with a 0 value corresponding to a
// space character, a 1 value to the period character, and so on, with each larger number
// represented by a character that occupies more space. For example, you might use # to
// represent 9. The last character (the 31st) in each row should be a null character, making
// it an array of 20 strings. Have the program display the resulting picture (that is, print the
// strings) and also store the result in a text file. For example, suppose you start with this
// data:
//  0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
//  0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
//  0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
//  0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
//  0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
//  0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
//  0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
//  5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
//  8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
//  9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9
//  8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
//  5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
//  0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
//  0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
//  0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
//  0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0
//  0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
//  0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
//  0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
//  0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0

// 0
// 1 .
// 2 '
// 3 :
// 4 ~
// 5 *
// 6 =
// 8 %
// 9 #

//  For one particular choice of output characters, the output looks like this:
//  # *%##%*'
//  # *%##%**'
//  *%.#%*~*'
//  # *%##%* ~*'
//  # *%##%* ~*'
//  *%#.%* ~*'
//  *%##%* ~*'
//  *************%##%*************
//  %%%%%%%%%%%%*%##%*%%%%%%%%%%%%
//  #### #################:#######
//  %%%%%%%%%%%%*%##%*%%%%%%%%%%%%
//  *************%##%*************
//  *%##%*
//  *%##%* ==
//  '' *%##%* *= =*
//  :: *%##%* *=....=*
//  ~~ *%##%* *= =*
//  ** *%##%* ==
//  *%##%*
//  *%##%*

#include <stdio.h>
#include <stdlib.h>

int printPic(char c);
int main(void)
{
    FILE *fp;
    if ((fp = fopen("q12-input.txt", "r")) == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    // input file contents to array
    char digital[20][30];
    char ch;
    int row = 0;
    int col = 0;
    while ((ch = fgetc(fp)) != EOF && row <= 29)
    {
        if (ch != ' ' && ch != '\n')
        {
            digital[row][col] = ch;
            col++;
        }
        else if (ch == '\n')
        {
            col = 0;
            row++;
        }
    }

    // print array to picture
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (j == 29)
            {
                putchar('\n');
            }
            else
            {
                printPic(digital[i][j]);
            }
        }
    }

    // close file
    if (fclose(fp) != 0)
    {
        printf("Error closing file\n");
    }
    return 0;
}

int printPic(char c)
{
    switch (c)
    {
    case '0':
        putchar(' ');
        break;
    case '1':
        putchar('.');
        break;
    case '2':
        putchar('\'');
        break;
    case '3':
          putchar(':');
        break;
    case '4':
          putchar('~');
        break;
    case '5':
          putchar('*');
        break;
    case '6':
          putchar('=');
        break;
    case '8':
          putchar('%');
        break;
    case '9':
          putchar('#');
        break;
    default:
        break;
    }
}