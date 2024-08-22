//  2. Write a file-copy program that takes the original filename and the copy file from the
// command line. Use standard I/O and the binary mode, if possible.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char ch;
    if (argc != 3){
        printf("Usage: %s <source> <destination>\n", argv[0]);
        exit(1);
    }

    fp1 = fopen(argv[1], "rb");
    if (fp1 == NULL){
        printf("Can't open %s\n", argv[1]);
        exit(1);
    }

    fp2 = fopen(argv[2], "wb");
    if (fp2 == NULL){
        printf("Can't open %s\n", argv[2]);
        exit(1);
    }

    // 方法1：使用putc写入
    // while((ch = getc(fp1)) != EOF ){
    //     putc(ch, fp2);
    // }

    // 方法2：使用fwrite写入
    // 缓冲区大小（可以根据需要调整）
    const size_t bufferSize = 1024;
    char buffer[bufferSize];
    size_t bytesRead;
    // 从源文件读取数据并写入到目标文件
    while ((bytesRead = fread(buffer, 1, bufferSize, fp1)) > 0) {
        if (fwrite(buffer, 1, bytesRead, fp2) != bytesRead) {
            perror("Failed to write to destination file");
            fclose(fp1);
            fclose(fp2);
            return 1;
        }
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}