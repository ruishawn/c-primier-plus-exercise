// Write a function that replaces the contents of a string with the string reversed. Test the
// function in a complete program that uses a loop to provide input values for feeding to
// the function.

#include <stdio.h>
#include <string.h>

char *resversed(char *str)
{
    printf("before reversing: %s\n", str);
    int len = strlen(str);
    char p[len];
    for(int i=0; i<len; i++)
    {
        p[i] = str[len-1-i];
    }
    printf("after reversing: %s\n", p);
    return p;
}

int main(void)
{
    char *sources[] =  {"wuhan", "xian", "shanghai", "beijing"};
    for (int i = 0; i<4; ++i){
        resversed(sources[i]);
    }

}