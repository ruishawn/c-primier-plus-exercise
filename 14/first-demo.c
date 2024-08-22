#include <stdio.h>
int sum(int value1, int valu2)
{
    return value1 + valu2;
}

int main(void)
{

    int n1 = 1, n2 = 2, n3 = 3;
    char c1 = 'a', c2 = 'b', c3 = 'c';
    int numArray[3] = {n1, n2, n3};
    char charArray[3] = {c1, c2, c3};
    int twoDimArray[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // pNum 是一个指向int的指针，它指向numArray数组中的第一个元素
    int *pNum = numArray;
    printf("&pNum[0] = %d\n", &pNum[0]);
    printf("pNum = %d\n", pNum);

    // pNum2指向指针的指针
    int **pNum2 = &pNum;
    printf("pNum2 = %d\n", pNum2);


    // pChar 是一个指向char的指针，它指向charArray数组中的第一个元素
    char *pChar = charArray;
    printf("&pChar[0] = %d\n", &pChar[0]);
    printf("pChar = %d\n", pChar);


    // 指向函数的指针
    int (*func)(int, int) = sum;
    printf("sum(3, 4) result is: %d\n", func(3, 4));

    // aar1 是一个指针数组，它有3个元素，每个元素都是一个指向int的指针
    int *arr1[3] = {&n1, &n2, &n3};
    for (int i; i < 3; i++)
    {
        printf("arr1[%d] = %d\n", i, arr1[i]);
    }
    // arr2 是一个指向数组的指针，它指向一个包含3个元素的数组
    int(*arr2)[3] = twoDimArray;
    for (int i; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("arr2[%d][%d] = %d\n", i, j, arr2[i][j]);
        }
    }
    // arr3 是指向函数的指针，它指向一个返回int的函数
    int (*funcp)(int, int) = sum;
    printf("sum %d + %d result is: %d\n", 2, 3, funcp(2, 3));
}
