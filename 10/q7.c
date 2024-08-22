// Write a program that initializes a two-dimensional array-of- double and uses one of the 
// copy functions from exercise 2 to copy it to a second two-dimensional array. (Because a 
// two-dimensional array is an array of arrays, a one-dimensional copy function can be used 
// with each subarray.)

#include <stdio.h>
void copy_attr(double *target, double *source, int n);
void copy_td_attr(double (*target)[4], double (*source)[4], int n);
void print_td_arr(double (*target)[4],int, int);

int main(void) {
    int i, j;
    double source[3][4] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0 };
    double target[3][4];
    copy_td_attr(target, source, 3);
    print_td_arr(target,3, 4);
}

void copy_attr(double *target, double *source, int n){
    for (int i = 0; i < n; ++i) {
        *target++ = *source++;
    }
}


void copy_td_attr(double (*target)[4], double (*source)[4], int n) {
    for (int i = 0; i < n; ++i) {
        copy_attr(target[i], source[i], 4);
        //写法如下也可以是等价的
        //copy_attr(*(target+i), *(source+i), 4);
    }
}

void print_td_arr(double (*target)[4], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%.2f ", target[i][j]);
            //写法如下也可以是等价的
            //printf("%.2f ", *(*(target+i)+j));
        }
    }
    printf("\n");
}