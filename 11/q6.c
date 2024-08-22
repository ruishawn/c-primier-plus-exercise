// Write a function called is_within() that takes a character and a string pointer as its two 
// function parameters. Have the function return a nonzero value (true) if the character is 
// in the string and zero (false) otherwise. Test the function in a complete program that uses 
// a loop to provide input values for feeding to the function.
#include <stdio.h>

int is_within(char c, char *s){
    int i;
    for(i = 0; s[i] != '\0'; ++i){
        if (c == s[i]) return 1;
    }
    return 0;
}

int main(void){
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    if (is_within(c, "hell world")){
        printf("%c is within the string.\n", c);
    }else{
        printf("%c is not within the string.\n", c);
    }
}