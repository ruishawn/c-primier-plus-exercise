// Do Programming Exercise 12, but use variable-length arrays (VLAs) instead of standard
// arrays.

#include <stdio.h>
#include <stdlib.h>

int printPic(char c);
int genArray(int row, int col, char arr[][col], FILE *fp);
int main(void)
{
    // open file
    FILE *fp;
    if ((fp = fopen("q13-input.txt", "r")) == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    // input file contents to array
    int row = 0;
    int col = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch != ' ' && ch != '\n')
        {
            col++;
        }
        else if (ch == '\n')
        {
            row++;
        }
    }
    // print row and col
    row = row + 1;
    col = (col + 1) / row;
    printf("%d-%d\n",row,col);
    char digital[row][col];
    rewind(fp);
    genArray(row, col, digital, fp);

    // print array to picture
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j == (col - 1))
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

int genArray(int row, int col, char arr[][col], FILE *fp)
{
    int r = 0, c = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF && r < row)
    {
        if (ch != ' ' && ch != '\n')
        {
            arr[r][c] = ch;
            c++;
        }
        else if (ch == '\n')
        {
            c = 0;
            r++;
        }
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