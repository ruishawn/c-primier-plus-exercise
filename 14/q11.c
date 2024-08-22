/*
Write a function called transform() that takes four arguments: the name of a source
array containing type double data, the name of a target array of type double, an int
representing the number of array elements, and the name of a function (or, equivalently,
a pointer to a function). The transform() function should apply the indicated function
to each element in the source array, placing the return value in the target array. For
example, the call
 transform(source, target, 100, sin);
would set target[0] to sin(source[0]), and so on, for 100 elements. Test the function
in a program that calls transform() four times, using two functions from the math.h
library and two suitable functions of your own devising as arguments to successive calls
of the transform() function.
*/

#include <stdio.h>
#include <math.h>

void transform(double source[], double target[], int n, double (*func)(double), char *func_name)
{
    printf("func %s: \n", func_name);

    for (int i = 0; i < n; ++i)
    {
        target[i] = func(source[i]);
        printf("%.2f->%.2f\n", source[i], target[i]);
    }
}

double square(double x)
{
    return x * x;
}

double add_one(double x)
{
    return x + 1;
}

int main(void)
{
    double source[10] = {4, 8, 9, 27, 100, 1024, 3.14, 27, 1000};
    double target[10];
    transform(source, target, 10, sqrt, "sqrt");
    transform(source, target, 10, square, "square");
    transform(source, target, 10, add_one, "add_one");
}
