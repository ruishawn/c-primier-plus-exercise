#include <stdio.h>

#define MAX_Len 5

void input_scanf(void);
void input_gets(void);
void input_fgets(void);
void input_fgets2(void);
void input_gets_s(void);

char *gets_s(char *st, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val) // i.e., ret_val != NULL
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else // must have words[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

char *gets_s_two(char st[], int n)
{
    char *ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val) // i.e., ret_val != NULL
    {
        while (*st != '\n' && *st != '\0')
            st++;
        if (*st == '\n')
            *st = '\0';
        else // must have words[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}


int main(void)
{
    // input_scanf();
    // input_gets();
    // input_fgets();
    // input_fgets2();
    input_gets_s();
    return 0;
}

void input_scanf()
{
    // scanf() and the %s specifier read just a single word
    char name[MAX_Len];
    printf("Enter your name by scanf:\n");
    scanf("%s", name);
    printf("Hello, get by scanf, name is %s.\n", name);
    puts("---scanf done---");
}

void input_gets()
{
    // gets()函数不检查输入字符串的长度,会导致缓冲区溢出,这是一个常见的安全隐患。
    // 因此,现代程序中不再建议使用gets()函数。
    char name[MAX_Len];
    printf("Enter your name by gets:\n");
    gets(name);
    puts("hello, get by gets, name is");
    puts(name);
    puts("---gets done---");
}

void input_fgets()
{
    // fgets()函数会读取指定长度的字符串,并在遇到换行符或到达文件末尾时停止,从而避免了缓冲区溢出的问题。
    char name[MAX_Len];
    printf("Enter your name by gets:\n");
    fgets(name, MAX_Len, stdin);
    puts("hello, get by fgets, name is");
    fputs(name, stdout); // fputs 相比puts不会在结尾追加换行符
    puts(name);
    puts("---fgets done---");
}

void input_fgets2()
{
    char name[MAX_Len];
    puts("hello, get by fgets2:");
    while (fgets(name, MAX_Len, stdin) != NULL && name[0] != '\n')
    {
        fputs(name, stdout);
    }
    puts("---fgets2 done---");
}

void input_gets_s()
{
    char name[MAX_Len];
    char *result;
    printf("Enter your name by gets_s:\n");
    result = gets_s(name, MAX_Len);
    puts("hello, get by gets_s, name is");
    puts(name);
    puts("---gets_s done---");
}
