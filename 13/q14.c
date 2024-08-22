// Digital images, particularly those radioed back from spacecraft, may have glitches. Add
// a de-glitching function to programming exercise 12. It should compare each value to its
// immediate neighbors to the left and right, above and below. If the value differs by more
// than 1 from each of its neighbors, replace the value with the average of the neighboring
// values. You should round the average to the nearest integer value. Note that the points
// along the boundaries have fewer than four neighbors, so they require special handling.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int printPic(int c);
int getAverages(int row, int col, int digital[][col], int digitalAverage[][col]);
int main(void)
{
    FILE *fp;
    if ((fp = fopen("q14-input.txt", "r")) == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    // 初始化数组
    int digital[20][30];
    int digitalAverage[20][30];
    int row = 0;
    int col = 0;
    char ch;
    int dig = 0;
    while ((ch = fgetc(fp)) != EOF && row <= 29)
    {
        if (ch != ' ' && ch != '\n')
        {
            dig = ch - '0';
            digital[row][col] = dig;
            //digitalAverage[row][col] = dig;
            col++;
        }
        else if (ch == '\n')
        {
            col = 0;
            row++;
        }
    }  

    // 计算平均值
    memcpy(digitalAverage, digital, sizeof(digital));
    getAverages(20, 30, digital, digitalAverage);

    // 输出结果
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
                printPic(digitalAverage[i][j]);
            }
        }
    }

    // 关闭文件
    if (fclose(fp) != 0)
    {
        printf("Error closing file\n");
    }
    return 0;
}

int getAverages(int row, int col, int digital[][col], int digitalAverage[][col])
{   
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 || j == 0 || i == (row - 1) || j == (col - 1))
            {   
                continue;
            }
            else
            {   
                if (abs(digital[i][j] - digital[i - 1][j]) > 1 
                   && abs(digital[i][j] - digital[i + 1][j]) > 1 
                   && abs(digital[i][j] - digital[i][j - 1]) > 1 
                   && abs(digital[i][j] - digital[i][j + 1]) > 1)
                {
                    double average = (digital[i - 1][j] + digital[i + 1][j] +
                                     digital[i][j - 1] + digital[i][j + 1]) / 4;
                    digitalAverage[i][j] = (int)round(average);
                    printf("%d-%d-%d\n", i, j, digitalAverage[i][j]);
                }
            }
        }
    }
    return 0;
}
int printPic(int c)
{
    switch (c)
    {
    case 0:
        putchar(' ');
        break;
    case 1:
        putchar('.');
        break;
    case 2:
        putchar('\'');
        break;
    case 3:
        putchar(':');
        break;
    case 4:
        putchar('~');
        break;
    case 5:
        putchar('*');
        break;
    case 6:
        putchar('=');
        break;
    case 8:
        putchar('%');
        break;
    case 9:
        putchar('#');
        break;
    default:
        break;
    }
}