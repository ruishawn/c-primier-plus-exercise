// Design and test a function that reads the first word from a line of input into an array and
// discards the rest of the line. It should skip over leading whitespace. Define a word as a
// sequence of characters with no blanks, tabs, or newlines in it. Use getchar(), not

// Design and test a function like that described in Programming Exercise 3 except that it 
// accepts a second parameter specifying the maximum number of characters that can be 
// read.

#include <stdio.h>


void read_first_word(char *word_buffer, int maxlen)
{
    int c, i = 0;

    // 跳过行首的空白字符
    while ((c = getchar()) != '\n' && (c ==' '|| c =='\t'))
        ;

    // 读取第一个单词并存储到 word_buffer 中
    while (c !='\n' && c !=' ' && c !='\t' && i < maxlen - 1)
    {
        word_buffer[i++] = c;
        c = getchar();
    }

    // 添加字符串结束符
    word_buffer[i] = '\0';

    // 丢弃剩余的行内容
    while (c != '\n')
        c = getchar();

}

void main()
{   
    int max = 5;
    char word[5];
    read_first_word(word, max);
    printf(word);
}