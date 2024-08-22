// Write a program that implements a menu by using an array of pointers to functions. For
// instance, choosing a from the menu would activate the function pointed to by the first
// element of the array.

#include <stdio.h>

int add(int a, int b)
{
    int res = a + b;
    printf("function add return %d\n", res);
    return res;
}

int sub(int a, int b)
{
    int res = a - b;
    printf("function sub return %d\n", res);
    return res;
}

int div(int a, int b)
{
    int res = a / b;
    printf("function div return %d\n", res);
    return res;
}

int mul(int a, int b)
{
    int res = a * b;
    printf("function mul return %d\n", res);
    return res;
}

int cal(int (*func)(int, int), int a, int b)
{
    (*func)(a, b);
}

int main(void)
{
    int a, b;
    int (*func[4])(int, int);
    func[0] = add;
    func[1] = sub;
    func[2] = div;
    func[3] = mul;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    for (int i = 0; i < 4; ++i)
    {
        cal(func[i], a, b);
    }
}