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

#include <stdio.h>

double get_average(double *arr, int size);
double get_average_td(double (*attr)[5], int rows);
double get_max(double (*arr)[5], int rows);

double get_average(double *arr, int size){
    double sum = 0;
    for(int i = 0; i < size; ++i){
        sum += arr[i];
    }
    return sum / size;
}

double get_average_td(double (*attr)[5], int rows){
    double sum = 0;
    for(int i = 0; i < rows; ++i){
        sum += get_average(*(attr+i), 5);
    }
    return sum / rows;
}

double get_max(double (*arr)[5], int rows){
    double max = arr[0][0];
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < 5; ++j){
            if(arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int main() {
    double arr[3][5];
    int i, j;
    for (i = 0; i < 3; ++i) {
        printf("Enter the %d set of five numbers:\n", i + 1);
        for (j = 0; j < 5; ++j) {
            scanf("%lf", &arr[i][j]);
        }
    }

    printf("The average of the first set is %lf\n", get_average(*arr,5));
    printf("The average of the second set is %lf\n", get_average(*(arr+1),5));
    printf("The average of the third set is %lf\n", get_average(*(arr+2),5));
    printf("The average of all values is %lf\n", get_average_td(arr, 3));
    printf("The largest value is %lf\n", get_max(arr, 3));
}