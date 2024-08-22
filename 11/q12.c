// Write a program that reads input up to EOF and reports the number of words, the
// number of uppercase letters, the number of lowercase letters, the number of punctuation
// characters, and the number of digits. Use the ctype.h family of functions.

// 自己写的
// #include <stdio.h>
// #include <ctype.h>

// int main(void)
// {
//     int c;
//     int upper = 0, lower = 0, punct = 0, digit = 0;
//     while ((c = getchar()) != '\n')
//     {
//         if (isupper(c))
//         {
//             upper++;
//             continue;
//         }
//         else if (islower(c))
//         {
//             lower++;
//             continue;
//         }
//         else if (isalnum(c))
//         {
//             digit++;
//         }
//         else if (ispunct(c))
//         {
//             punct++;
//         }
//         else
//         {
//             continue;
//         }
//     }
//     printf("upper: %d\n", upper);
//     printf("lower: %d\n", lower);
//     printf("punct: %d\n", punct);
//     printf("digit: %d\n", digit);
//     return 0;
// }

#include <stdio.h>
#include <ctype.h>

int main() {
    int wordCount = 0;
    int upperCount = 0;
    int lowerCount = 0;
    int punctCount = 0;
    int digitCount = 0;
    int c;

    printf("Enter text (press Ctrl+D or Ctrl+Z to end):\n");

    // 读取输入直到 EOF
    while ((c = getchar()) != EOF) {
        // 判断当前字符的类型
        if (isalpha(c)) {
            if (isupper(c)) {
                upperCount++;
            } else {
                lowerCount++;
            }
            // 如果前一个字符是非字母字符,则当前字符是新的单词
            if (wordCount == 0 || !isalpha(c - 1)) {
                wordCount++;
            }
        } else if (ispunct(c)) {
            punctCount++;
        } else if (isdigit(c)) {
            digitCount++;
        }
    }

    printf("Words: %d\n", wordCount);
    printf("Uppercase letters: %d\n", upperCount);
    printf("Lowercase letters: %d\n", lowerCount);
    printf("Punctuation characters: %d\n", punctCount);
    printf("Digits: %d\n", digitCount);

    return 0;
}