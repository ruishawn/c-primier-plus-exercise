//  Write a program that prompts the user to enter three sets of five double numbers each. 
// (You may assume the user responds correctly and doesn’t enter non-numeric data.) The 
// program should accomplish all of the following: 
//  a. Store the information in a 3×5 array. 
//  b. Compute the average of each set of five values. 
//  c. Compute the average of all the values. 
//  d. Determine the largest value of the 15 values. 
//  e. Report the results. 
// Each major task should be handled by a separate function using the traditional C 
// approach to handling arrays. Accomplish task “b” by using a function that computes 
// and returns the average of a one-dimensional array; use a loop to call this function three 
// times. The other tasks should take the entire array as an argument, and the functions 
// performing tasks “c” and “d” should return the answer to the calling program.


// Note: use variable-length array(VLA) function parameters.

#include <stdio.h>



double get_average(double *arr, int size){
    double sum = 0;
    for(int i = 0; i < size; ++i){
        sum += arr[i];
    }
    return sum / size;
}


double get_average2d(int rows, int cols, double arr[rows][cols]){
    double sum = 0;
    for(int i=0; i < rows; ++i){
        for(int j=0; j < cols; ++j){
            sum += arr[i][j];
        }
    }
    return sum / (rows * cols);
}


double get_max_2d(int rows, int cols, double arr[rows][cols]){
    double max = arr[0][0];
    for(int i=0; i < rows; ++i){
        for(int j=0; j < cols; ++j){
            if(arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

void print_result(int rows, int cols, double arr[rows][cols]){
    for(int i=0; i < rows; ++i){
        printf("The average of the set%d is %lf\n", i+1, get_average(arr[i], cols));
    }
    printf("The average of all values is %lf\n", get_average2d(rows, cols, arr));
    printf("The largest value is %lf\n", get_max_2d(rows, cols, arr));

}

int main() {
    int rows,cols;
    int i, j;

    printf("Enter the num of rows: \n");
    scanf("%d", &rows);
    printf("Enter the num of cols: \n");
    scanf("%d", &cols);
    double arr[rows][cols];


    for (i = 0; i < rows; ++i) {
        printf("Enter the %d set of %d numbers:\n", i + 1, cols);
        for (j = 0; j < cols; ++j) {
            scanf("%lf", &arr[i][j]);
        }
    }

    print_result(rows, cols, arr);
}