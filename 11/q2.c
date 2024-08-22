// Modify and test the function in exercise 1 so that it stops after n characters or after the 
// first blank, tab, or newline, whichever comes first. (Don’t just use scanf() .)

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
        if(c == '\n' || c==' ' || c=='\t'){
            break;
        }
        res[i] = c;
        i++;
    }
    return res;
}