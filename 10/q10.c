// Write a function that sets each element in an array to the sum of the corresponding 
// elements in two other arrays. That is, if array 1 has the values 2, 4, 5, and 8 and array 2 
// has the values 1, 0, 4, and 6, the function assigns array 3 the values 3, 4, 9, and 14. The 
// function should take three array names and an array size as arguments. Test the function 
// in a simple program.


#include <stdio.h>

void sum_arrays(int array1[], int array2[], int array3[], int size);

void main(void){
    int array1[4] = {2, 4, 5, 8};
    int array2[4] = {1, 0, 4, 6};
    int array3[4];
    sum_arrays(array1, array2, array3, 4);
}


void sum_arrays(int array1[], int array2[], int array3[], int size){
    for(int i=0; i<size; i++){
        array3[i] = array1[i] + array2[i];
        printf("%d ", array3[i]);
    }
    printf("\n");
}
