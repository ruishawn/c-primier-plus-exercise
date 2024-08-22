// Write a program that echoes the command-line arguments in reverse word order. That 
// is, if the command-line arguments are see you later, the program should print later 
// you see .

#include <stdio.h>

int main(int argc, char *argv[]){
    int i;
    for(i = argc - 1; i >= 1; i--){
        printf("%s ", argv[i]);
    }
}