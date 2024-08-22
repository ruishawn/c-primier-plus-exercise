//  Write a function that takes a string as an argument and removes the spaces from the 
// string. Test it in a program that uses a loop to read lines until you enter an empty line. 
// The program should apply the function to each input string and display the result.

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// 自己写的比较糟糕的实现
char  *remove_spaces(char *str) {
    int i = 0, j = 0;
    char *res = str;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != ' ') {
            res[j] = str[i];
            j++;
        }
    }
    res[j] = '\0';
    return str;
}

// 自己写的错误的写法
// 在 C 语言中,函数参数是按值传递的。这意味着当您将 str 传递给 remove_spaces() 函数时,
// 它只是复制了一个指向原始字符串的指针。在函数内部修改 str 的指向并不会影响函数外部的 str 变量。
char  *remove_spaces_bad(char *str) {
    int i = 0, j = 0;
    char res[strlen(str)];
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != ' ') {
            res[j] = str[i];
            j++;
        }
    }
    res[j] = '\0';
    str = res;
    printf("%p\n", str);
    return str;
}



// 比较好的实现
char* remove_spaces1(char* str) {
    char* dest = str;
    for (char* src = str; *src != '\0'; src++) {
        if (*src != ' ') {
            *dest++ = *src;
        }
    }
    *dest = '\0';
    return str;
}

int main() {
    char line[MAX_LINE_LENGTH];

    printf("Enter lines of text (enter an empty line to quit):\n");

    while (1) {
        printf("> ");
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL || line[0] == '\n') {
            break;
        }

        // 删除行尾的换行符
        line[strcspn(line, "\n")] = '\0';

        // 调用 remove_spaces 函数
        remove_spaces(line);

        printf("Result: %s\n", line);
    }

    return 0;
}