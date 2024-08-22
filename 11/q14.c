//  Write a power-law program that works on a command-line basis. The first command-line 
// argument should be the type double number to be raised to a certain power, and the 
// second argument should be the integer power.

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

// 编译命令 gcc q14.c -o q14 -lm
int main(int argc, char *argv[]){
    double base;
    int power;
    if(argc != 3){
        printf("Usage: %s <base> <power>\n", argv[0]);
        exit(1);
    }

    base = atof(argv[1]);
    power = atoi(argv[2]);
    printf("%f to the power of %d is %f\n", base, power, pow(base, power));
}