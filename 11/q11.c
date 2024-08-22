// Write a program that reads in up to 10 strings or to EOF, whichever comes first. Have it
// offer the user a menu with five choices: print the original list of strings, print the strings
// in ASCII collating sequence, print the strings in order of increasing length, print the
// strings in order of the length of the first word in the string, and quit. Have the menu
// recycle until the user enters the quit request. The program, of course, should actually
// perform the promised tasks.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 5
#define MAX_STRING_LENGTH 100

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

int compare_first_word(char *a, char *b)
{
    int l1 = 0;
    int l2 = 0;
    while (*a != ' ' && *a != '\0')
    {
        l1++;
        a++;
    }
    while (*a != ' ' && *a != '\0')
    {
        l2++;
        b++;
    }

    return l1 - l2;
}

int main()
{
    puts("input strngs:");
    char str[MAX_STRINGS][MAX_STRING_LENGTH];
    int i = 0;
    while (i < MAX_STRINGS)
    {
        gets_s(str[i], MAX_STRING_LENGTH);
        i++;
    }

    int choice = 0;
    printf("1. print the original list of strings\n");
    printf("2. print the strings in ASCII collating sequence\n");
    printf("3. print the strings in order of increasing length\n");
    printf("4. print the strings in order of the length of the first word in the string\n");
    printf("5. quit\n");
    puts("input your choice:(1-5)");
    scanf("%d", &choice);

    char quilt_flag[10];
    switch (choice)
    {
    case 1:
        printf("the original list of strings is: \n");
        for (int i = 0; i < MAX_STRINGS; ++i)
        {
            printf("%s\n", str[i]);
        }
        break;
    case 2:
        printf("the strings in ASCII collating sequence is: \n");
        for (int i = 0; i < MAX_STRINGS; i++)
        {
            for (int j = i + 1; j < MAX_STRINGS; j++)
            {
                if (strcmp(str[i], str[j]) > 0)
                {
                    char t[MAX_STRING_LENGTH];
                    strcpy(t, str[j]);
                    strcpy(str[j], str[i]);
                    strcpy(str[i], t);
                }
            }
        }

        for (int i = 0; i < MAX_STRINGS; ++i)
        {
            printf("%s\n", str[i]);
        }
        break;
    case 3:
        printf("the strings in order of increasing length is: \n");
        for (int i = 0; i < MAX_STRINGS; i++)
        {
            for (int j = i + 1; j < MAX_STRINGS; j++)
            {
                if (strlen(str[i]) > strlen(str[j]))
                {
                    char t[MAX_STRING_LENGTH];
                    strcpy(t, str[j]);
                    strcpy(str[j], str[i]);
                    strcpy(str[i], t);
                }
            }
        }

        for (int i = 0; i < MAX_STRINGS; ++i)
        {
            printf("%s\n", str[i]);
        }
        break;
    case 4:
        printf("the strings in order of the length of the first word in the string is: \n");
        for (int i = 0; i < MAX_STRINGS; i++)
        {
            for (int j = i + 1; j < MAX_STRINGS; j++)
            {
                if (compare_first_word(str[i], str[j]) >= 0)
                {
                    char t[MAX_STRING_LENGTH];
                    strcpy(t, str[j]);
                    strcpy(str[j], str[i]);
                    strcpy(str[i], t);
                }
            }
        }
        for (int i = 0; i < MAX_STRINGS; ++i)
        {
            printf("%s\n", str[i]);
        }
        break;
    case 5:
        while (strcmp(quilt_flag, "quit") != 0)
        {   
            printf("quilt flag is %s\n", quilt_flag);
            scanf("%s", quilt_flag);
        }
        printf("good bye\n");
        break;
    default:
        printf("invalid choice\n");
        break;
    }

    return 0;
}