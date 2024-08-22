
// Write a function that reverses the contents of an array of double and test it in a simple 
// program.
#include<stdio.h>


void reverse(double *source, double *target, int);
void print_arr(double *arr, int n);

void main(){
    double source[4] = {1.0, 2.1, 3.5, 4.7};
    double target[4]; 
    reverse(source, target, 4);
    print_arr(target, 4);
}


void reverse(double *source, double *target, int n){
    for(int i = 0; i < n; ++i){
        target[n-1 - i] = source[i];
    }
}

void print_arr(double *arr, int n){
    for(int i = 0; i < n; ++i){
        printf("%f ", arr[i]);
    }
    printf("\n");
}