// Write a program that declares a 3×5 array of int and initializes it to some values of
// your choice. Have the program print the values, double all the values, and then display
// the new values. Write a function to do the displaying and a second function to do the
// doubling. Have the functions take the array name and the number of rows as arguments.

#include <stdio.h>

void display_arr(int (*arr)[5], int rows);
void double_arr(int (*arr)[5], int rows);

void display_arr(int (*arr)[5], int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void double_arr(int (*arr)[5], int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            arr[i][j] *= 2;
        }
    }
}

void main()
{
    int arr[3][5] = {{1, 1, 1, 1, 1}, {2, 2, 2, 2, 2}, {3, 3, 3, 3, 3}};
    display_arr(arr, 3);
    double_arr(arr, 3);
    printf("\n");
    display_arr(arr, 3);
}
