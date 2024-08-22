//  The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1, truncating 
// s2 or padding it with extra null characters as necessary. The target string may not be 
// null-terminated if the length of s2 is n or more. The function returns s1. Write your own 
// version of this function; call it mystrncpy(). Test the function in a complete program 
// that uses a loop to provide input values for feeding to the function.

#include <stdio.h>
#include <string.h>

char *mystrncpy(char *s1, const char *s2, size_t n){
    int l = strlen(s2);
    if (n > l)
    {
        printf("n is big than length of s2");
        return NULL;
    }
    
    int i;
    for (i = 0; i < n && s2[i] != '\0'; ++i){
        s1[i] = s2[i];
    }

    return s1;
}


int main(void){
    char s1[20];
    char *s2 = "helloworld";
    char *sources[] =  {"wuhan", "xian", "shanghai", "beijing"};
    for (int i = 0; i<4; ++i){
        mystrncpy(s1, sources[i], 5);
        printf("%s\n", s1);
    }

}