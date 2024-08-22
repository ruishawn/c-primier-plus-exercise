// Design and test a function that searches the string specified by the first function 
// parameter for the first occurrence of a character specified by the second function 
// parameter. Have the function return a pointer to the character if successful, and a null 
// if the character is not found in the string. (This duplicates the way that the library 
// strchr() function works.) Test the function in a complete program that uses a loop to 
// provide input values for feeding to the function.
#include <stdio.h>
#include <string.h>

char *find_str(char *str1, char *str2){
    int l1, l2;
    l1 = strlen(str1);
    l2 = strlen(str2);
    printf("%d\n",l1);
    printf("%d\n",l2);

    // 长度不够包含l2返回NULL
    if (l1 < l2){
        return NULL;
    }

    int i,k =0;
    while(i<=l1-l2){
        if (str1[i] == str2[k]){
            for(int j= i; j<i+l2; j++,k++){
                if (str1[j] != str2[k]){
                    break;
                }
            }
            if( k == l2){
                printf("位于位置%d\n",i);
                return &str1[i];
            }
        }
        i++;
        k=0;
    }
    printf("没有找到位置%d\n",i);
    return NULL;
}


void main(){
    char *str1 = "hello world world";
    char *str2 = "world";
    printf("%p\n", find_str(str1, str2));
}