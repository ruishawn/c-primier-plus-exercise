//  Write a function that returns the difference between the largest and smallest elements of 
// an array-of- double. Test the function in a simple program.

#include <stdio.h>


double double_diff(double *array, int size);

void main( void )
{
    double array1[ 10 ] = { 3.4, 2.5, 6.7, 8.9, 1.2, 4.5, 7.8, 9.0, 10.1, 11.2 };
    double array2[ 5 ] = { 100.4, 3000.2, 100.0, 0.2, 199 };
    printf("array difference is %.2f \n", double_diff(array1, 10));
    printf("array difference is %.2f \n", double_diff(array2, 5));
}


double double_diff(double *array, int size){
    double min = array[0];
    double max = array[0];
    for(int i=0; i<size; i++){
        if(array[i] < min){
            min = array[i];
        }
        if(array[i] > max){
            max = array[i];
        }
    }
    return max-min;
}