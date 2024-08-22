// Design and test a function that fetches the next n characters from input (including 
// blanks, tabs, and newlines), storing the results in an array whose address is passed as an 
// argument.
#include <stdio.h>

char *getNchar(int n, char *res);


int main(void){
    int n=6;
    char *p;
    getNchar(n,p);
    printf(p);
    return 0;
}

char *getNchar(int n, char *res){
    // printf("%d\n", n);
    int i =0;
    while(i<n){
        char c = getchar();
        res[i] = c;
        i++;
    }
    return res;
}