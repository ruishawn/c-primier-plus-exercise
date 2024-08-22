// Use the character classification functions to prepare an implementation of atoi(); have 
// this version return the value of 0 if the input string is not a pure number.

#include <stdio.h>
#include <math.h>
#include <string.h>

int covertToNum(char str[]){
    int num = 0;
    int l1 = strlen(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i]>='0' && str[i]<='9'){
            int power = pow(10, l1-i-1);
            num = num+ power*(str[i] - '0');
        }else{
            return 0;
        }
    }
    return num;
}

int main() {
    char str[10];
    int res;
    printf("Enter a string of digits: ");
    scanf("%s", str);
    res = covertToNum(str);
    printf("The number is %d\n", res);
}
