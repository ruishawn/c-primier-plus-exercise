// Use a copy function from Programming Exercise 2 to copy the third through fifth 
// elements of a seven-element array into a three-element array. The function itself need
// not be altered; just choose the right actual arguments. (The actual arguments need not be 
// an array name and array size. They only have to be the address of an array element and a 
// number of elements to be processed.)

#include <stdio.h>


void copy_array(double *source, double *target, int size, int start){
    for (int i=0;i<size;i++){
        target[i]=source[i+start];
    }
}

void print_array(double *array, int size){
    for(int i=0;i<size;i++){
        printf("%f ",array[i]);
    }
    printf("\n");
}

void main(){
    double source[7]={1.0,2.0,3.0,4.0,5.0,6.0,7.0};
    double target[3];
    copy_array(source,target,3,2);
    print_array(target,3);
}